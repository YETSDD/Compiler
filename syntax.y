%{
    #include"lex.yy.c"
    void yyerror(const char *s){}
    int result;
%}
%token LP RP LB RB LC RC
%%
String: Part {result = $1;}
    | {result =0;}  ;
Part:LP RP {$$ = 1;}
    |LB RB {$$ =1;}
    |LC RC {$$ = 1;}
    |LP Part RP {$$ = $2;}
    |LB Part RB {$$ = $2;}
    |LC Part RC {$$ = $2;}
    |Part Part {$$ = $1 * $2;}
    |Wrong {$$ = 0;}
; 
Wrong: Right Left
     |  LP RB
     | LP RC
     | LB RP
     | LB RC
     | LC RP
     | LC RB
     ; 
Left: LP | LB | LC
Right: RP | RB | RC
%%

int validParentheses(char *expr){
    yy_scan_string(expr);
    yyparse();
    return result;
}

