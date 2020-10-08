%{
    #include "stdio.h"
    #define MAX_SIZE 20
    #include"syntax.tab.h"
    int hasError=0;
    struct node{
	int line;
	char * name;
    int num;
	struct node *child[MAX_SIZE];
	union{
	char* id;
	int ival;
	char* fval;
	char* cval;
	} ;
    };

	struct node* createNode(char* name, struct node* childs[MAX_SIZE],int num);
    struct node* createLeafNode(char* name, int line,char*value);
	void travesal(struct node*,int level);
%}
%option yylineno
%option noyywrap
DECINT [1-9][0-9]*|0
HEXINT 0[Xx][1-9A-Fa-f][0-9A-Fa-f]*
FLOAT [1-9][0-9]*\.[0-9]*|0\.[0-9]*
CHAR \'[a-zA-Z0-9!@#$%^&*()_+-={}:";'<>?,./|]\'
HEXCHAR \'\\[Xx](0)?[a-fA-F0-9]{2}\'
ID [_A-Za-z][_0-9A-Za-z]*
TYPE "int"|"float"|"char"
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
ERRORID [0-9][0-9A-Za-z_]*
ERRORCHAR \'[a-zA-Z0-9!@#$%^&\*()_\+-=\[\]\{\}:\"\;\'<>?,\./|\\][a-zA-Z0-9!@#$%^&\*()_\+-=\[\]\{\}:\"\;\'<>?,\./|\\]+\'
HEXERROR1 0(X|x)[a-zA-Z0-9]*
HEXERROR2 \'\\[Xx][a-zA-Z0-9]*\'
AERROR .
%%
{TYPE} {yylval.n=createLeafNode("TYPE",yylineno,yytext);return TYPE;}
{STRUCT} {yylval.n=createLeafNode("STRUCT",yylineno,yytext);return STRUCT;}
{DECINT} {yylval.n=createLeafNode("INT",yylineno,yytext);return INT;}
{HEXINT} {yylval.n=createLeafNode("INT",yylineno,yytext);return INT;}
{FLOAT} {yylval.n=createLeafNode("FLOAT",yylineno,yytext);return FLOAT;}
{IF} {yylval.n=createLeafNode("IF",yylineno,yytext);return IF;}
{ELSE} {yylval.n=createLeafNode("ELSE",yylineno,yytext);return ELSE;}
{WHILE} {yylval.n=createLeafNode("WHILE",yylineno,yytext);return WHILE;}
{RETURN} {yylval.n=createLeafNode("RETURN",yylineno,yytext);return RETURN;}
{DOT} {yylval.n=createLeafNode("DOT",yylineno,yytext);return DOT;}
{SEMI} {yylval.n=createLeafNode("SEMI",yylineno,yytext);return SEMI;}
{COMMA} {yylval.n=createLeafNode("COMMA",yylineno,yytext);return COMMA;}
{ASSIGN} {yylval.n=createLeafNode("ASSIGN",yylineno,yytext);return ASSIGN;}
{LT} {yylval.n=createLeafNode("LT",yylineno,yytext);return LT;}
{LE} {yylval.n=createLeafNode("LE",yylineno,yytext);return LE;}
{GT} {yylval.n=createLeafNode("GT",yylineno,yytext);return GT;}
{GE} {yylval.n=createLeafNode("GE",yylineno,yytext);return GE;}
{NE} {yylval.n=createLeafNode("NE",yylineno,yytext);return NE;}
{EQ} {yylval.n=createLeafNode("EQ",yylineno,yytext);return EQ;}
{PLUS} {yylval.n=createLeafNode("PLUS",yylineno,yytext);return PLUS;}
{MINUS} {yylval.n=createLeafNode("MINUS",yylineno,yytext);return MINUS;}
{MUL} {yylval.n=createLeafNode("MUL",yylineno,yytext);return MUL;}
{DIV} {yylval.n=createLeafNode("DIV",yylineno,yytext);return DIV;}
{AND} {yylval.n=createLeafNode("AND",yylineno,yytext);return AND;}
{OR} {yylval.n=createLeafNode("OR",yylineno,yytext);return OR;}
{NOT} {yylval.n=createLeafNode("NOT",yylineno,yytext);return NOT;}
{LP} {yylval.n=createLeafNode("LP",yylineno,yytext);return LP;}
{RP} {yylval.n=createLeafNode("RP",yylineno,yytext);return RP;}
{LB} {yylval.n=createLeafNode("LB",yylineno,yytext);return LB;}
{RB} {yylval.n=createLeafNode("RB",yylineno,yytext);return RB;}
{LC} {yylval.n=createLeafNode("LC",yylineno,yytext);return LC;}
{RC} {yylval.n=createLeafNode("RC",yylineno,yytext);return RC;}
"//" {char c; while((c=input())!='\n');}
" " {}
"	" {}
"\n" {}

{CHAR} {yylval.n=createLeafNode("CHAR",yylineno,yytext);return CHAR;}
{HEXCHAR} {yylval.n=createLeafNode("CHAR",yylineno,yytext);return CHAR;}
{ID} {yylval.n=createLeafNode("ID",yylineno,yytext);return ID;}
{ERRORID} {hasError=1;printf("Error type A at Line %d : Unknown lexeme %s\n",yylineno, yytext);yylval.n=createLeafNode("ERROR",yylineno,yytext);return ERROR;}
{HEXERROR1} {hasError=1;printf("Error type A at Line %d : Invalid hex integer %s\n",yylineno, yytext);yylval.n=createLeafNode("ERROR",yylineno,yytext);return ERROR;}
{HEXERROR2} {hasError=1;printf("Error type A at Line %d : Invalid hex character %s\n",yylineno, yytext);yylval.n=createLeafNode("ERROR",yylineno,yytext);return ERROR;}
{AERROR} {hasError=1;printf("Error type A at Line %d : Unknown characters %s\n",yylineno, yytext);yylval.n=createLeafNode("ERROR",yylineno,yytext);return ERROR;}
%%

struct node* createNode(char* name,struct node* childs[MAX_SIZE],int num){
    
    struct node *a=(struct node *)malloc(sizeof(struct node));
    a->name = name;
    for(int i=0;i<num;i++){
        a->child[i]=childs[i];
    }
    a->line= childs[0]->line;
    a->num = num;
    //printf("createNode{%s,%d,%d}\n",name,a->line,num);
    return a;
}

struct node* createLeafNode(char * name, int line,char* value){
    //printf("createLeafNode{%s,%d,%s}\n",name,line,value);
    struct node *a=(struct node *)malloc(sizeof(struct node));
    a->num=0;
    a->line = line;
    a->name = name;
    if((!strcmp(a->name,"ID"))||(!strcmp(a->name,"TYPE"))){
        char*t=(char*) malloc(sizeof(char*)*40);
        strcpy(t,value);
        a->id=t;
    }
    else if(!strcmp(a->name,"INT")) {
        char*t=(char*) malloc(sizeof(char*)*40);
        strcpy(t,value);
        if(t[1]=='X'|t[1]=='x'){
            int temp=strtol(t,NULL,16);
            a->ival=temp;
        }
        else{
            a->ival=atoi(value);
        }
        }
    else if(!strcmp(a->name,"FLOAT")) {
        char*t=(char*) malloc(sizeof(char*)*40);
        strcpy(t,value);
        a->fval=t;
        }
    else if(!strcmp(a->name,"CHAR")) {
        char*t=(char*) malloc(sizeof(char*)*40);
        char*temp=(char*) malloc(sizeof(char*)*40);
        strcpy(t,value);
        for(int i=1;t[i]!='\'';i++){
            temp[i-1]=t[i];
        }
        a->cval=temp;
        }
    return a;
}

void travesal(struct node* a, int level){
    if(a!=NULL){
        
        if(a->line!=-1){
            for(int i=0;i<level;++i) printf("  ");
            printf("%s",a->name);
            if((!strcmp(a->name,"ID"))||(!strcmp(a->name,"TYPE")))printf(": %s",a->id);
            else if(!strcmp(a->name,"INT"))printf(": %d",a->ival);
            else if(!strcmp(a->name,"FLOAT"))printf(": %s",a->fval);
            else if(!strcmp(a->name,"CHAR")){printf(": %s",a->cval);}
            else if(a->num!=0)printf("(%d)",a->line);
            printf("\n");
        }
        
        
	     
        for(int i=0;i<a->num;i++){
            travesal(a->child[i],level+1);
        } 
    }
}
