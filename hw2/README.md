# <b>F74046022_Compiler_hw2</b>

## <b>Basic Feature (note)</b>

* Relation between int and float32 is same as that in C.
```
// I_CONST converts to F_CONST when assigned to variable(float32).
// F_CONST rounded down when assgined to 
variable(int).
// hybrid operation returns F_CONST

var i int = 5.5     // i == 5
var f float32 = 5   // f == 5.0
```
* Accessing variable does not print message in order to keep output clean. If  needed, just uncomment line 236 in <b>compiler_hw2.y</b>.
* dump_symbol() displays all visible variable at the time.
* Always call dump_symbol() at the end. If not needed comment line 125 in <b>compiler_hw2.y</b> . 

---

## <b>Advanced feature</b>

### if_stmt (print "if_stmt" if matched)
```
if_stmt
    : IF expr block                 
    | IF expr block ELSE if_stmt   
    | IF expr block ELSE block    
;
```
### Scope checking
* number = depth
* "-" = bi-directional link
* "→" = directional link
* Scopes are reserved in case of needing to analyze (All scope reachable from root).
```
// program : {{}} {{}} {}

initial     : 0*

enter_block : 0  - 1*

enter_block : 0  - 1  - 2*

leave_block : 0  - 1* - 2

leave_block : 0* - 1  - 2

enter_block : 0  - 1  - 2
                 ↖ ↓  
                   1*  

enter_block : 0  - 1  - 2
                 ↖ ↓    ↓
                   1  - 2*

leave_block : 0  - 1  - 2
                 ↖ ↓    ↓
                   1* - 2

leave_block : 0* - 1  - 2
                 ↖ ↓    ↓
                   1  - 2

enter_block : 0  - 1  - 2
                 ↖ ↓    ↓
                   1  - 2
                 ↖ ↓
                   1*

leave_block : 0* - 1  - 2
                 ↖ ↓    ↓
                   1  - 2
                 ↖ ↓
                   1
```