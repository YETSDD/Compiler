%{
    #include "stdio.h"
    #include"syntax.tab.h"
%}
%option yylineno
%option noyywrap
DEXINT [1-9][0-9]*|0
HEXINT 0[Xx][1-9A-Fa-f][0-9A-Fa-f]*
FLOAT DEXINT.[0-9]*
CHAR [A-Za-z]*|(0[Xx](0|1[0-9]{0,2}|2[0-4]?[0-9]?|25[0-5]?|[3-9][0-9]?))
ID [A-Za-z_][0-9A-Za-z_]
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
%%
{TYPE} {return TYPE;}
{STRUCT} {return STRUCT;}
{IF} {return IF;}
{ELSE} {return ELSE;}
{WHILE} {return WHILE;}
{RETURN} {return RETURN;}
{DOT} {return DOT;}
{SEMI} {return SEMI;}
{COMMA} {return COMMA;}
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
{LP} {return LP;}
{RP} {return RP;}
{LB} {return LB;}
{RB} {return RB;}
{LC} {return LC;}
{RC} {return RC;}
"//" {char c; while((c=input())!="\n");}
{AERROR} {printf("Error type A at Line %d: Unknown characters \'%s\'\n",yylineno, yytext);}
%%

