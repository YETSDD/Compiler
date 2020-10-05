%{
    #include"syntax.tab.h"
%}
%option yylineno
%option noyywrap

TYPE int|float|char
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
{AERROR} {printf("Error type A at Line %d: Unknown characters \’%s\’\ n",yylineno, yytext);}
%%

