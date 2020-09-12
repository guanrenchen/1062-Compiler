# F74046022 Compiler_hw1

## Advanced Feature


[Discard C and C++ type comment]
    print "... C COMENT" if "//..."
    print "... C++ COMMENT" if "/*...*/"

[Coun the comment lines]

    comment line plus 1 if  line not already counted
    comment line plus N for N newline in comment


[Syntax error check]

    try to access but lookup failed
        => undeclared 
    try to insert but lookup success 
        => redefined

---

## Syntax

    float32 FLOAT32
    println PRINTLN_FUNC
    print   PRINT_FUNC
    else    ELSE
    for     FOR
    var     VAR
    int     INT
    if      IF

    ++      INCREMENT
    --      DECREMENT
    <=      LESS_EQUAL
    >=      GREATER_EQUAL
    ==      EQUAL
    !=      NOT_EQUAL
    +=      ADD_ASSIGN
    -=      SUB_ASSIGN
    *=      MUL_ASSIGN
    /=      DIV_ASSIGN
    %=      MOD_ASSIGN
    &&      AND
    ||      OR

    (       LB
    )       RB
    {       LCB
    }       RCB
    +       ADD
    -       SUB
    *       MUL
    /       DIV
    %       MOD
    <       LESS
    >       GREATER
    =       ASSIGN
    !       NOT