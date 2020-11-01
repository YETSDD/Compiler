%{
    #define YYSTYPE char*
    #include"syntax.tab.h"

    #define bool int
    #define TRUE 1
    #define FALSE 0
    struct JsonObject{
        enum{Object, Array,String,Number,Boolean,Vnull} categoty;
        union{
            struct ObjectMember *members;
            struct ArrayValue *values;
            char *string;
            double number;
            bool BOOLEAN;
        };
    };
    struct ObjectMember{
        char *key;
        struct JsonObject *value;
        struct ObjectMember *next;
    
    };

    struct ArrayValue{
        struct JsonObject *value;
        struct ArrayValue *next;
    };
%}
%option noyywrap

unic u[0-9a-fA-F]{4}
esc \\([\"\\/bfnrt]|{unic})
scp [^"\\\x00-\x1f]
string \"({esc}|{scp})*\"

int 0|[1-9][0-9]*
frac \.[0-9]+
exp [Ee][+-]?[0-9]+
number -?{int}{frac}?{exp}?
wrongnumber 0[1-9]+

empty [ \n\r\t]

%%

"{" { return LC; }
"}" { return RC; }
"[" { return LB; }
"]" { return RB; }
":" { return COLON; }
"," { return COMMA; }

"true" { return TRUE; }
"false" { return FALSE; }
"null" { return VNULL; }

{string} { yylval = strdup(yytext);return STRING; }
{number} { yylval = strdup(yytext);return NUMBER; }
{wrongnumber} {return ERROR;}
{empty} {}

. { printf("lexical error: %s\n", yytext); }
