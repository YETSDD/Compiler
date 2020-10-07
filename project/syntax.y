%{
    #include"lex.yy.c"
    void yyerror(const char*);
    #include <list>
    using namespace std;
    struct node{
	int line;
	char * name;
	list<node> child;
	union{
	char* id;
	int ival;
	float fval;
	char cval;
	}
    }
	struct node* createNode(char* name, list<node> childs);
    struct node* createNode(char* name, int line);
	void travesal(struct node*,int level);
%}

%union{
    struct node* n;
}

%token <n> INT FLOAT CHAR ID 
%token <n> TYPE STRUCT IF ELSE WHILE RETURN DOT SEMI COMMA ASSIGN 
%token <n> LT LE GT GE NE EQ PLUS MINUS MUL DIV AND OR NOT
%token <n> LP RP LC RC LB RB 
%type  <n> Program ExtDefList ExtDef ExtDecList Specifire StructSpecifire OptTag  Tag VarDec  FunDec VarList ParamDec Compst StmtList Stmt DefList Def DecList Dec Exp Args

%right ASSIGN
%left OR
%left AND 
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LC RC LB RB DOT 
%%

Program: ExtDefList;
ExtDefList: ExtDef ExtDefList
|;
ExtDef: Specifier ExtDecList SEMI
| Specifier SEMI
| Specifier FunDec CompSt;
ExtDecList: VarDec
| VarDec COMMA ExtDecList;
/* specifier */
Specifier: TYPE 
| StructSpecifier;
StructSpecifier: STRUCT ID LC DefList RC
| STRUCT ID;
/* declarator */
VarDec: ID
| VarDec LB INT RB;
FunDec: ID LP VarList RP {printf("FUNC");}
| ID LP RP;
VarList: ParamDec COMMA VarList
| ParamDec;
ParamDec: Specifier VarDec;
/* statement */
CompSt: LC DefList StmtList RC;
StmtList: Stmt StmtList
|;
Stmt: Exp SEMI
| CompSt
| RETURN Exp SEMI
| IF LP Exp RP Stmt
| IF LP Exp RP Stmt ELSE Stmt
| WHILE LP Exp RP Stmt;
/* local definition */
DefList: Def DefList
|;
Def: Specifier DecList SEMI;
DecList: Dec
| Dec COMMA DecList;
Dec: VarDec
| VarDec ASSIGN Exp;
/* Expression */
Exp: Exp ASSIGN Exp
| Exp AND Exp
| Exp OR Exp
| Exp LT Exp
| Exp LE Exp
| Exp GT Exp
| Exp GE Exp
| Exp NE Exp
| Exp EQ Exp
| Exp PLUS Exp
| Exp MINUS Exp
| Exp MUL Exp
| Exp DIV Exp
| LP Exp RP
| MINUS Exp
| NOT Exp
| ID LP Args RP
| ID LP RP
| Exp LB Exp RB
| Exp DOT ID
| ID
| INT
| FLOAT
| CHAR;
Args: Exp COMMA Args
| Exp;

%%

void yyerror(const char *s){
    printf("syntax error: ");
}

struct node* createNode(char* name,list<node> childs){
    struct node *a=(struct node *)malloc(sizeof(struct node));
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    a->name = name;
    a->child = childs;//todo
    a->line=childs.begin().line;
    return a;
}

struct node* createNode(char * name, int line){
    struct node *a=(struct node *)malloc(sizeof(struct node));
    a->line = line;
    if((!strcmp(a->name,"ID"))||(!strcmp(a->name,"TYPE"))){
        char* t=(char*)malloc(sizeof(char* )*40);
        strcpy(t,yytext);
        a->id=t;
    }
    else if(!strcmp(a->name,"INTEGER")) {a->ival=atoi(yytext);}
    else if(!strcmp(a->name,"FLOAT")) {a->fval=atof(yytext);}
    else if(!strcmp(a->name,"CHAR")) {a->cval=yytext;}
}

void travesal(struct node* a, int level){
    if(a!=NULL){
        for(int i=0;i<level;++i) printf("   ");
        if(a->line!=-1){
            printf("%s ",a->name);
            if((!strcmp(a->name,"ID"))||(!strcmp(a->name,"TYPE")))printf(":%s ",a->idtype);
            else if(!strcmp(a->name,"INTEGER"))printf(":%d",a->ival);
            else if(!strcmp(a->name,"FLOAT"))printf(":%f",a->fval);
            else if(!strcmp(a->name,"CHAR"))printf(":%s",a->cval);
            else printf("(%d)",a->line);
        }
        printf("\n");
        
	    list<node>::iterator itor=a->child.begin();  
        while(itor!=a->child.end){
            travesal(itor,level+1);
        } 
    }
}
int main(int argc, char **argv){
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    yyparse();
    return 0;
}
