/*	Definition section */
%{
extern int yylineno;
extern int yylex();

extern void yyerror(const char *s);

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int type;
    union {
        int i;
        float f;
        char *s;
    } val;
} Inst;

typedef struct symbol{
    int depth;
    char *id;
    Inst inst;
    struct symbol *next;
} Symbol;

typedef struct scope{
    int depth;
    Symbol *symbols;
    struct scope *next, *prev, *side;
} Scope;

Scope *topScope = NULL;
Scope *curScope = NULL;

char err[4096];
int is_err = 0;
int lastline = 0;

/* Symbol table function - you can add new function if need. */
Symbol *lookup_symbol_cur(const char *id);
Symbol *lookup_symbol_all(const char *id);
void create_symbol();
void insert_symbol();
void dump_symbol();

void enter_scope();
void leave_scope();
void init_scope();

Inst calc(void *a, int op, void *b);
void print_inst(Inst inst);
void print_op(int op);
void print_type(int type);

void myerror(const char *s);
void flush_error();

// use struct(value, type) to implement type checking

%}

/* Using union to define nonterminal and token type */
%union {
    struct {
        int type;
        union {
            int i;
            float f;
            char *s;
        } val;
    } inst;

    int i;
    float f;
    char *s;
    int type;

    int op;
}

/* Token without return */
%right ASSIGN ASSIGN_ADD ASSIGN_SUB ASSIGN_MUL ASSIGN_DIV ASSIGN_MOD 

%left OR
%left AND
%nonassoc GE LE EQ NE GT LT
%left ADD SUB
%left MUL DIV MOD
%left INC DEC

%token NEWLINE MY_EOF
%token INT FLOAT
%token PRINT PRINTLN 
%token IF ELSE FOR
%token VAR

%token LB RB LCB RCB

%token BOOL T_ERROR

/* Token with return, which need to sepcify type */
%token <i> I_CONST
%token <f> F_CONST
%token <s> STRING
%token <s> ID

/* Nonterminal with return, which need to sepcify type */

%type <op> assign_op print_op
%type <i> incdec_op
%type <type> type
%type <inst> expr operand literal

/* Yacc will start at this nonterminal */
%start program

/* Grammar section */
%%

program
    : stmts MY_EOF {
        flush_error();
        dump_symbol(); 
        exit(0); 
        }
;

stmts 
    : stmts stmt  
    | 
;

stmt
    : declaration   
    | assignment    
    | for_stmt      {printf("for_stmt\n");}
    | if_stmt       {printf("if_stmt\n");}
    | print_stmt    
    | block         
    | NEWLINE       {flush_error();}
    | expr {
        if ($1.type==BOOL) {
            print_inst(*(Inst*)&($1));
            printf("\n");
        }
    }
;

block : lcb stmts rcb ;
lcb : LCB   { enter_scope(); } ;
rcb : RCB   { leave_scope(); } ;
lb  : LB    { enter_scope(); } ;
rb  : RB    { leave_scope(); } ;

declaration
    : VAR ID type ASSIGN expr {
        insert_symbol($2, $3, (Inst*)&($5));
        }
    | VAR ID type {
        insert_symbol($2, $3, NULL);
        }
;

type
    : INT   { $$ = INT; }
    | FLOAT { $$ = FLOAT; }
;

expr 
    : operand       { $$ = $1; }
    | expr  OR expr { 
        Inst tmp = calc(&($1),  OR, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr AND expr { 
        Inst tmp = calc(&($1), AND, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr  GE expr { 
        Inst tmp = calc(&($1),  GE, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr  LE expr { 
        Inst tmp = calc(&($1),  LE, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr  EQ expr { 
        Inst tmp = calc(&($1),  EQ, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr  NE expr { 
        Inst tmp = calc(&($1),  NE, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr  GT expr { 
        Inst tmp = calc(&($1),  GT, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr  LT expr { 
        Inst tmp = calc(&($1),  LT, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr ADD expr { 
        Inst tmp = calc(&($1), ADD, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr SUB expr { 
        Inst tmp = calc(&($1), SUB, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr MUL expr { 
        Inst tmp = calc(&($1), MUL, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr DIV expr { 
        Inst tmp = calc(&($1), DIV, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
    | expr MOD expr { 
        Inst tmp = calc(&($1), MOD, &($3)); 
        memcpy(&($$), &tmp, sizeof($$));
        }
;

operand 
    : literal       {$$=$1;}
    | lb expr rb    {$$=$2;}
    | ID incdec_op {
        Symbol *sym = lookup_symbol_all($1);
        if(!sym) {
            myerror("Undefined variable");
            $$.type = T_ERROR;
        }else{
            // printf("\tvariable %s is in depth %d\n", sym->id, sym->depth);
            memcpy(&($$), &(sym->inst), sizeof($$));
            if(sym->inst.type==INT){
                sym->inst.val.i += $2;
            }else if ($2!=0) {
                myerror("Invalid operation on variable");
            }
        }
        }
;

incdec_op
    : INC   {$$= 1;}
    | DEC   {$$=-1;}
    |       {$$= 0;}
;

literal 
    : I_CONST { 
        $$.type = INT;
        $$.val.i = $1;
        }
    | F_CONST { 
        $$.type = FLOAT;
        $$.val.f = $1;
        }
    | STRING { 
        $$.type = STRING;
        $$.val.s = strdup($1);
        }
;

assignment
    : ID assign_op expr {
        Symbol *sym = lookup_symbol_all($1);

        Inst *lv, *rv;
        lv = &(sym->inst);
        rv = (Inst*)&($3);

        if(!sym) {
            myerror("Undefined variable");
        }else{
            Inst ret;
            switch ($2) {
            case ASSIGN_ADD : ret = calc(lv, ADD, rv); break;
            case ASSIGN_SUB : ret = calc(lv, SUB, rv); break;
            case ASSIGN_MUL : ret = calc(lv, MUL, rv); break;
            case ASSIGN_DIV : ret = calc(lv, DIV, rv); break;
            case ASSIGN_MOD : ret = calc(lv, MOD, rv); break;
            case ASSIGN     : ret = *rv;
            }

            if (ret.type==INT || ret.type==FLOAT) {
                if(sym->inst.type == INT){
                    sym->inst.val.i = 
                        (ret.type==FLOAT? ret.val.f : ret.val.i);
                }else{
                    sym->inst.val.f = 
                        (ret.type==FLOAT? ret.val.f : ret.val.i);
                }
            } else if (ret.type!=T_ERROR) {
                myerror("Assignment type error");
            }
        }
        }
;

assign_op
    : ASSIGN        {$$=ASSIGN;}
    | ASSIGN_ADD    {$$=ASSIGN_ADD;}
    | ASSIGN_SUB    {$$=ASSIGN_SUB;}
    | ASSIGN_MUL    {$$=ASSIGN_MUL;}
    | ASSIGN_DIV    {$$=ASSIGN_DIV;}
    | ASSIGN_MOD    {$$=ASSIGN_MOD;}
;

for_stmt
    : FOR expr block    
;

if_stmt
    : IF expr block                  
    | IF expr block ELSE if_stmt
    | IF expr block ELSE block   
;

print_stmt
    : print_op lb expr rb {
        print_inst(*(Inst*)&($3));
        if($1==PRINTLN) printf("\n");
        }
;

print_op
    : PRINT     { $$ = PRINT; }
    | PRINTLN   { $$ = PRINTLN; }
;

%%

/* C code section */
int main(int argc, char** argv)
{
    enter_scope();

    yylineno = 0;
    yyparse();

    return 0;
}

void yyerror(const char *s){
    fprintf(stderr, "line %d\t: %s\n", yylineno+1, s);
}

void myerror(const char *s) {
    if(strcmp(err,"")==0){
        strncpy(err, s, sizeof(err));
    }
}

void flush_error() {
    if(strcmp(err,"")!=0){
        fprintf(stderr, "line %d\t: %s\n", yylineno, err);
        memset(err, 0, sizeof(err));
    }
}

Symbol *lookup_symbol_cur(const char *id){
    Symbol *sym;
    for (sym=curScope->symbols; sym; sym=sym->next)
        if (strcmp(id, sym->id)==0)
            return sym;
    return NULL;
}
Symbol *lookup_symbol_all(const char* id){
    Scope *scp;
    Symbol *sym;
    for(scp=curScope; scp; scp=scp->prev){
        for(sym=scp->symbols; sym; sym=sym->next){
            if(strcmp(id, sym->id)==0) {
                // printf("variable %s is depth %d\n", sym->id, sym->depth);
                return sym;
            }
        }
    }
    return NULL;
}
void create_symbol() {
    curScope->symbols = malloc(sizeof(Symbol));
    // printf("create symbol table for depth %d\n", curScope->depth);
}
void insert_symbol(const char *id, int type, Inst *inst) {
    if (lookup_symbol_cur(id)) {
        myerror("Redefined variable");
        return;
    }
    
    Symbol *tmp = curScope->symbols;
    if (tmp) {
        while(tmp->next) tmp=tmp->next;
        tmp->next = malloc(sizeof(Symbol));
        tmp = tmp->next;
    } else {    
        create_symbol();
        tmp = curScope->symbols;
    }
    tmp->depth = curScope->depth;
    tmp->id = strdup(id);
    tmp->next = NULL;

    if (inst) {
        if (inst->type==T_ERROR){
            return;
        } else if (inst->type!=INT && inst->type!=FLOAT) {
            myerror("Declaration type mismatch");
            return;
        } else {
            tmp->inst = *inst;
        }
    } else {
        memset(&(tmp->inst), 0, sizeof(Inst));
        tmp->inst.type = type;
    }

    printf("declare %s in block of depth %d\n", id, curScope->depth);
        
}
void dump_symbol() {
    Scope *scp;
    Symbol *sym;
    printf("\tSYMBOL TABLE\n");
    for (scp=curScope; scp; scp=scp->prev) {
        printf("\tdepth %d :\n", scp->depth);
        for (sym=scp->symbols; sym; sym=sym->next){
            printf("\t\t%s\t", sym->id);
            print_type(sym->inst.type);
            printf("\t");
            print_inst(sym->inst);
            printf("\n");
        }
    }
}

void enter_scope() {
    if (!topScope){
        topScope = malloc(sizeof(Scope));
        init_scope(topScope, 0);
        curScope = topScope;
    }else{
        if(!(curScope->next)){
            curScope->next = malloc(sizeof(Scope));
            init_scope(curScope->next, curScope->depth+1);
            curScope->next->prev = curScope;
            curScope = curScope->next;
        }else{
            Scope *tmp;
            for (tmp=curScope->next; tmp->side; tmp=tmp->side);
            tmp->side = malloc(sizeof(Scope));
            tmp = tmp->side;
            init_scope(tmp, curScope->depth+1);
            tmp->prev = curScope;
            curScope = tmp;
        }
        // printf("%s %d\n", __func__, curScope->depth);
    }
} 
void leave_scope() {
    if (curScope->prev) {
        // printf("%s %d\n", __func__, curScope->depth);
        curScope = curScope->prev;
    }
}
void init_scope(Scope *scp, int depth) {
    scp->depth = depth;
    scp->symbols = NULL;
    scp->next = NULL;
    scp->prev = NULL;
    scp->side = NULL;
}

void print_inst(Inst inst){
    switch (inst.type) {
    case INT:       printf("%d", inst.val.i);   break;
    case FLOAT:     printf("%f", inst.val.f);   break;
    case STRING:    printf("%s", inst.val.s);   break;
    case BOOL:      printf(inst.val.i? "true": "false"); break;
    default: break;
    }
}
void print_op(int op){
    switch (op) {
    case OR:    printf("||");   break;
    case AND:   printf("&&");   break;
    case GE:    printf(">=");   break;
    case LE:    printf("<=");   break;
    case EQ:    printf("==");   break;
    case NE:    printf("!=");   break;
    case GT:    printf( ">");   break;
    case LT:    printf( "<");   break;
    case ADD:   printf( "+");   break;
    case SUB:   printf( "-");   break;
    case MUL:   printf( "*");   break;
    case DIV:   printf( "/");   break;
    case MOD:   printf("%%");   break;
    case INC:   printf("++");   break;
    case DEC:   printf("--");   break;
    default:    printf("op?");   break;
    }
    printf(" ");
}
void print_type(int type){
    switch (type) {
        case INT:       printf("int");          break;
        case FLOAT:     printf("float32");      break;
        case STRING:    printf("String");       break;
        case BOOL:      printf("Boolean");      break;
        case T_ERROR:   printf("T_ERROR");      break;
        default :       printf("type?");        break;
    }
}

Inst calc(void *a, int op, void *b){
    Inst ret;
    Inst x=*(Inst*)a, y=*(Inst*)b;

    ret.type = T_ERROR;

    if (x.type==T_ERROR || y.type==T_ERROR){
        return ret;
    }

    if(x.type==STRING || y.type==STRING){
        myerror("Invalid operation with string");
        return ret;
    }

    switch (op) {
    case OR:
        ret.type = BOOL;
        ret.val.i = (*(float*)&x.val) || (*(float*)&y.val);
        return ret;
    case AND:
        ret.type = BOOL;
        ret.val.i = (*(float*)&x.val) && (*(float*)&y.val);
        return ret;
    case GE:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) >= 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case LE:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) <= 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case EQ:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) == 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case NE:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) != 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case GT:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) > 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case LT:
        ret.type = BOOL;
        ret.val.i = 
            (x.type==FLOAT? x.val.f: x.val.i) < 
            (y.type==FLOAT? y.val.f: y.val.i);
        return ret;
    case ADD:
        if (x.type==FLOAT || y.type==FLOAT){
            ret.type = FLOAT;
            ret.val.f = 
                (x.type==FLOAT? x.val.f: x.val.i) + 
                (y.type==FLOAT? y.val.f: y.val.i);
        }else{
            ret.type = INT;
            ret.val.i = 
                (x.type==FLOAT? x.val.f: x.val.i) + 
                (y.type==FLOAT? y.val.f: y.val.i);
        }
        return ret;
    case SUB:
        if (x.type==FLOAT || y.type==FLOAT){
            ret.type = FLOAT;
            ret.val.f = 
                (x.type==FLOAT? x.val.f: x.val.i) - 
                (y.type==FLOAT? y.val.f: y.val.i);
        }else{
            ret.type = INT;
            ret.val.i = 
                (x.type==FLOAT? x.val.f: x.val.i) -
                (y.type==FLOAT? y.val.f: y.val.i);
        }
        return ret;
    case MUL:
        if (x.type==FLOAT || y.type==FLOAT){
            ret.type = FLOAT;
            ret.val.f = 
                (x.type==FLOAT? x.val.f: x.val.i) * 
                (y.type==FLOAT? y.val.f: y.val.i);
        }else{
            ret.type = INT;
            ret.val.i = 
                (x.type==FLOAT? x.val.f: x.val.i) * 
                (y.type==FLOAT? y.val.f: y.val.i);
        }
        return ret;
    case DIV:
        if ( (y.type==FLOAT? y.val.f: y.val.i)==0 ) {
            myerror("Divide by 0");
        }else if (x.type==FLOAT || y.type==FLOAT){
            ret.type = FLOAT;
            ret.val.f = 
                (x.type==FLOAT? x.val.f: x.val.i) /
                (y.type==FLOAT? y.val.f: y.val.i);
        }else{
            ret.type = INT;
            ret.val.i = 
                (x.type==FLOAT? x.val.f: x.val.i) / 
                (y.type==FLOAT? y.val.f: y.val.i);
        }
        return ret;
    case MOD:
        if (x.type==FLOAT || y.type==FLOAT){
            myerror("Modulus with float32");
        }else if(y.val.i==0) {
            myerror("Divide by 0 (modulus)");
        }else{
            ret.type = INT;
            ret.val.i = x.val.i % y.val.i;
        }
        return ret;
    default:
        return ret;
    }
}