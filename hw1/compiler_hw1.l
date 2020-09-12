/* Definition section */
%{
	#include <stdio.h>
	#include <stdlib.h>

	/* Symbol table function */
	void create_symbol(char *id, char *type);
	void insert_symbol(char *id, char *type);
	int lookup_symbol(char *id);
	void dump_symbol();

	struct symbol{
		char *id, *type;
		struct symbol *next;
	};

	struct symbol *symbols=NULL;
	size_t comment=0;
	unsigned char counted = 0;
%}

/* Define regular expression label */

letter [a-zA-Z]
digit [0-9]
id {letter}+({letter}|{digit})*
number {digit}+
floatnum {number}+\.{number}*
string (\")([^"]|\\\"|\n)*(\")
comment_0 \/\/.*
comment_1 \/\*[^*]*\*+(?:[^/*][^*]*\*+)*\/
ws [ \t\r]+
type (int|float32)
declaration (var){ws}+{id}{ws}+{type}

/* Rules section */
%%

{ws}	{}
\n		{ yylineno++; counted=0;}
{comment_0}	{
	if(!counted){
		comment++;
		counted = 1;
	}
	for(int i=0; yytext[i]!='\0'; i++)
		if(yytext[i]!='\r')
			printf("%c", yytext[i]);
	printf(" \t C COMMENT \n");
}
{comment_1}	{ 
	if(!counted){
		comment++;
		counted = 1;
	}
	for(int i=0; yytext[i]!='\0'; i++){
		if(yytext[i]!='\r')
			printf("%c", yytext[i]);
		if(yytext[i]=='\n'){
			yylineno++;
			comment++;
		}
	}
	printf(" \t C++ COMMENT \n");
}
{string}	{ printf("%s \t STRING \n", yytext);}
{floatnum}	{ printf("%s \t FLOAT_NUMBER \n", yytext);}
{number}	{ printf("%s \t NUMBER \n", yytext);}
{declaration}	{
	int n=0, pos;
	char *id, *type;
	while(yytext[n]!=' ' && yytext[n]!='\t') n++;
	while(yytext[n]==' ' || yytext[n]=='\t') n++;
	pos = n;
	while(yytext[n]!=' ' && yytext[n]!='\t') n++;
	id = malloc(n-pos);
	memset(id, '\0', n-pos);
	strncpy(id, yytext+pos, n-pos);
	while(yytext[n]==' ' || yytext[n]=='\t') n++;
	pos = n;
	while(yytext[n]!='\0') n++;
	type = malloc(n-pos);
	memset(type, '\0', n-pos);
	strncpy(type, yytext+pos, n-pos);

	printf("%s \t %s TYPE VAR \n", id, type);
	insert_symbol(id, type);
}

"float32"	{ printf("%s \t FLOAT32 \n", yytext);}
"println"	{ printf("%s \t PRINTLN_FUNC \n", yytext);}
"print"	{ printf("%s \t PRINT_FUNC \n", yytext);}
"else"	{ printf("%s \t ELSE \n", yytext);}
"for"	{ printf("%s \t FOR \n", yytext);}
"var"	{ printf("%s \t VAR \n", yytext);}
"int"	{ printf("%s \t INT \n", yytext);}
"if"	{ printf("%s \t IF \n", yytext);}

{id}	{ 
	if(lookup_symbol(yytext)!=-1)
		printf("%s \t ID \n", yytext);
	else
		printf("%s \t ID UNDECLARED\n", yytext);
}

"++"	{ printf("%s \t INCREMENT \n", yytext);}
"--"	{ printf("%s \t DECREMENT \n", yytext);}
"<="	{ printf("%s \t LESS_EQUAL \n", yytext);}
">="	{ printf("%s \t GREATER_EQUAL \n", yytext);}
"=="	{ printf("%s \t EQUAL \n", yytext);}
"!="	{ printf("%s \t NOT_EQUAL \n", yytext);}
"+="	{ printf("%s \t ADD_ASSIGN \n", yytext);}
"-="	{ printf("%s \t SUB_ASSIGN \n", yytext);}
"*="	{ printf("%s \t MUL_ASSIGN \n", yytext);}
"/="	{ printf("%s \t DIV_ASSIGN \n", yytext);}
"%="	{ printf("%s \t MOD_ASSIGN \n", yytext);}
"&&"	{ printf("%s \t AND \n", yytext);}
"||"	{ printf("%s \t OR \n", yytext);}

"("		{ printf("%s \t LB \n", yytext);}
")"		{ printf("%s \t RB \n", yytext);}
"{"		{ printf("%s \t LCB \n", yytext);}
"}"		{ printf("%s \t RCB \n", yytext);}
"+" 	{ printf("%s \t ADD \n", yytext); }
"-"		{ printf("%s \t SUB \n", yytext); }
"*"		{ printf("%s \t MUL \n", yytext);}
"/"		{ printf("%s \t DIV \n", yytext);}
"%"		{ printf("%s \t MOD \n", yytext);}
"<"		{ printf("%s \t LESS \n", yytext);}
">"		{ printf("%s \t GREATER \n", yytext);}
"="		{ printf("%s \t ASSIGN \n", yytext);}
"!"		{ printf("%s \t NOT \n", yytext);}

%%

/*	C Code section */
int yywrap(void)
{
    return 1;
}

void create_symbol(char *id, char *type) {
	symbols = malloc(sizeof(struct symbol));
	symbols->id = malloc(strlen(id));
	strncpy(symbols->id, id, strlen(id));
	symbols->type = malloc(strlen(type));
	strncpy(symbols->type, type, strlen(type));
	symbols->next = NULL;

	printf("Create a symbol table\n");
	printf("Insert a symbol: %s\n", id);
}
void insert_symbol(char *id, char *type) {
	if (!symbols){
		create_symbol(id, type);
		return;
	}

	if(lookup_symbol(id)!=-1){
		printf("%s \t ID REDEFINED\n", id);
		return;
	}
	
	struct symbol *cur;
	for(cur=symbols; cur->next!=NULL; cur=cur->next);
	cur->next = malloc(sizeof(struct symbol));
	cur = cur->next;
	cur->id = malloc(strlen(id));
	strncpy(cur->id, id, strlen(id));
	cur->type = malloc(strlen(type));
	strncpy(cur->type, type, strlen(type));
	cur->next = NULL;

	printf("Insert a symbol: %s\n", cur->id);
}
int lookup_symbol(char *id) {
	struct symbol *cur;
	int i=0;
	for(cur=symbols; cur!=NULL; cur=cur->next, i++){
		if(strcmp(cur->id, id)==0)
			return i;
	}
	return -1;
}
void dump_symbol() {
	printf("Parse over, the line number is %d.\n\n", yylineno);
	printf("comment: %ld lines\n\n", comment);
	printf("The symbol table dump:\n");

	struct symbol *cur;
	size_t cnt = 0;
	for(cur=symbols; cur!=NULL; cur=cur->next){
		printf("%ld \t %s \t %s \n",
			++cnt,
			cur->id,
			cur->type);
	}
}

int main(int argc,char *argv[])
{
	yyin = fopen(argv[1],"r");
	yylex();

	dump_symbol();

	return 0;
}
