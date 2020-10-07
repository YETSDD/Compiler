%{
    #include "stdio.h"
    #include"syntax.tab.h"
%}
%option yylineno
%option noyywrap
DECINT [1-9][0-9]*|0
HEXINT 0[Xx][1-9A-Fa-f][0-9A-Fa-f]*
FLOAT DEXINT.[0-9]*
CHAR '[A-Za-z]'|(0[Xx][0-9A-Fa-f]{2,2}
ID [_A-Za-z][_0-9A-Za-z]*
TYPE int|float|char
STRUCT struct
IF if
ELSE else
WHILE while
RETURN return
DOT \.
SEMI \;
COMMA ,
ASSIGN =
LT <
LE <=
GT >
GE >=
NE !=
EQ ==
PLUS \+
MINUS -
MUL \*
DIV \/
AND &&
OR \|\|
NOT !
LP \(
RP \)
LB \[
RB \]
LC \{
RC \}
AERROR .
HEXERROR 0(X|x)[a-zA-Z0-9]*
%%
{TYPE} {printf("type %s\n",yytext);return TYPE;}
{STRUCT} {printf("STRUCT\n");return STRUCT;}
{DECINT} {printf("DEC %s\n",yytext);return INT;}
{HEXINT} {printf("HEX\n");return INT;}
{FLOAT} {printf("FLOAT\n");return FLOAT;}
{IF} {printf("IF\n");return IF;}
{ELSE} {return ELSE;}
{WHILE} {return WHILE;}
{RETURN} {return RETURN;}
{DOT} {return DOT;}
{SEMI} {printf("SEMI\n");return SEMI;}
{COMMA} {printf("COMMA\n");return COMMA;}
{ASSIGN} {return ASSIGN;}
{LT} {return LT;}
{LE} {return LE;}
{GT} {return GT;}
{GE} {return GE;}
{NE} {return NE;}
{EQ} {return EQ;}
{PLUS} {return PLUS;}
{MINUS} {return MINUS;}
{MUL} {return MUL;}
{DIV} {return DIV;}
{AND} {return AND;}
{OR} {return OR;}
{NOT} {return NOT;}
{LP} {printf("PBC\r");return LP;}
{RP} {printf("PBC\r");return RP;}
{LB} {printf("PBC\r");return LB;}
{RB} {printf("PBC\r");return RB;}
{LC} {printf("PBC\r");return LC;}
{RC} {printf("PBC\r");return RC;}
"//" {char c; while((c=input())!="\n");}
" " {}
"\r\n" {}
{CHAR} {printf("CHAR\n");return CHAR;}
{ID} {printf("ID %s\n",yytext);return ID;}
{AERROR} {printf("Error type A at Line %d: Unknown characters \'%s\'\n",yylineno, yytext);}
{HEXERROR} {printf("Error type A at Line %d: Invalid hex \'%s\'\n",yylineno, yytext);}
%%

