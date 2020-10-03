%{
    #include"syntax.tab.h"
%}
%option yylineno
TYPE int | float | char
STRUCT struct
IF if
ELSE else
WHILE while
RETURN return
DOT \.
SEMI ;
COMMA ,
ASSIGN =
LT <
LE <=
GT >
GE >=
NE !=
EQ ==
PLUS +
MINUS -
MUL *
DIV /
AND &&
OR ||
NOT !
LP (
RP )
LB [
RB ]
LC {
RC }
AERROR .
%%

int | float | char {return TYPE;}
{STRUCT} {return STRUCT;}
{IF} {return IF;}
{ELSE} {return ELSE;}
{WHILE} {return WHILE;}
{RETURN} {return RETURN;}
{DOT} {return DOT;}
{SEMI}{return SEMI;}
{COMMA} {return COMMA;}
{NOT} {return NOT;}
{}

