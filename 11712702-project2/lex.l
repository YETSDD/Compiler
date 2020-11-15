%{
    #include "stdio.h"
    #define MAX_SIZE 20
    #include"syntax.tab.h"
    int hasError=0;
    struct node{
	int line;
	char * name;
    int num; //the length of child
	struct node *child[MAX_SIZE];
    char* id;
	struct Type* type;
    char* cval;
	int ival;
	char* fval;

	
    };

    struct symTab{
        char *name;
        struct Type* type;
        struct symTab *next;
    };

    struct funTab{
        int ifDef;
        char *name;
        struct Type* type;
        int pnum;
        struct symTab *param[MAX_SIZE];
        struct funTab *next;
    };

    struct strTab{
        char *name;
        struct Type* type;
        struct strTab* next;
    };

    struct arrTab{
        char *name;
        struct Type* type;
        struct arrTab* next;
    };

    typedef struct Type{
        char name[32];
        char uName[32];
        enum {PRIMITIVE, ARRAY, STRUCTURE} category;
        union {
            enum{Int, Float,Char} primitive;
            struct Array * array;
            struct FieldList *structure;
        };
    }Type;

    typedef struct Array{
        struct Type *base;
        int size;
    }Array;

    typedef struct FieldList{
        char name[32];
        struct Type* type;
        struct FieldList *next;
    }FieldList;
    
    struct symTab* newSymTab(char* type, char* name);
    int lookup(char* name,struct symTab* head);
    int insert(char* type, char* name, struct symTab* head);
    struct symTab* findSym(char* name, struct symTab* head);
    struct Type* newType(char *typename);
    struct Type* newArrType(struct Type* type,int size);
    void setType(char* type, char* name, struct symTab* head);
    struct Type* findType(char* name,struct symTab* head);

    int lookupfunc(char* name,struct funTab* head);
    int insertfunc(char* type, char* name,int ifDef,int num, struct symTab* param[MAX_SIZE], struct funTab* head);
    struct funTab* findfunc(char* name,struct funTab* head);
    int checkReturn(struct Type*type,struct node*node);

    int lookuparr(char* name, struct arrTab* head);
    int insertarr(struct Type* type, char* name, struct arrTab* head);
    struct arrTab* findarr(char* name, struct arrTab* head);

    int lookupstr(char* name,struct strTab* head);
    int insertstr(struct Type* type, char* name, struct strTab* head);
    struct strTab* findstr(char* name,struct strTab* head);

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

struct symTab* newSymTab(char* type, char* name){
    struct symTab* newTab=(struct symTab*)malloc(sizeof(struct symTab));
    newTab->type=newType(type);
    newTab->name=name;
    newTab->next=NULL;
    return newTab;
}
    
int lookup(char* name,struct symTab* head){
    //printf("Lookup: %s\n",name);
    struct symTab* temp= (struct symTab*)malloc(sizeof(struct symTab));
    if(head->next!=NULL)
        temp= head;
    else
        return 0;
    int flag=0;
    while (temp!=NULL){
        //printf("%s\n",temp->name);
        if(!strcmp(name,temp->name)){
            flag=1;
            return 1;
        }
        temp=temp->next;
    }
    if(!flag)
    return 0;
}

int insert(char* type, char* name, struct symTab* head) {
    //printf("Insert: %s\n",name);
    struct symTab* temp= (struct symTab*)malloc(sizeof(struct symTab));
    temp=head;
    while (temp->next!=NULL){
        //printf("%s\n",temp->name);
        temp=temp->next;
    }
    struct symTab* newTab=(struct symTab*)malloc(sizeof(struct symTab));
    newTab->type=newType(type);
    newTab->name=name;
    newTab->next=NULL;
    temp->next=newTab;
    return 1;
}

struct symTab* findSym(char* name, struct symTab* head){
    struct symTab* temp= (struct symTab*)malloc(sizeof(struct symTab));
    if(head->next!=NULL)
        temp= head;
    else
        return NULL;
    while (temp!=NULL){
        //printf("%s\n",temp->name);
        if(!strcmp(name,temp->name)){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

struct Type* newType(char *typename){
    struct Type* newT=(struct Type*)malloc(sizeof(struct Type));
    strcpy(newT->name,typename);
    if(strcmp(typename,"int")==0||strcmp(typename,"float")==0||strcmp(typename,"char")==0) newT->category=PRIMITIVE;
    else if(strcmp(typename,"ARRAY")==0) {newT->category=ARRAY;}
    else if(strcmp(typename,"STRUCT")==0) {newT->category=STRUCTURE;}
    return newT;
}

struct Type* newArrType(struct Type* type,int size){
    struct Type* newT=newType("ARRAY");
    struct Array* newArray=(struct Array*)malloc(sizeof(struct Array));
    newArray->base=type;
    newArray->size=size;
    newT->array=newArray;
    return newT;
}
void setType(char* type, char* name, struct symTab* head){
    //printf("set type: %s %s\n",type,name);
    struct symTab* temp= (struct symTab*)malloc(sizeof(struct symTab));
    if(head->next!=NULL)
        temp= head;
    else
        return ;
    int flag=0;
    while (temp!=NULL){
        //printf("%s\n",temp->name);
        if(!strcmp(name,temp->name)){
            temp->type=newType(type);
        }
        temp=temp->next;
    }

    
}
struct Type* findType(char* name,struct symTab* head){
    struct symTab* temp= (struct symTab*)malloc(sizeof(struct symTab));
    if(head->next!=NULL)
        temp= head;
    else
        return NULL;

    while (temp!=NULL){
        //printf("%s\n",temp->name);
        if(!strcmp(name,temp->name)){
            //printf("%s %s\n",name,temp->type->name);
            return temp->type;
        }
        temp=temp->next;
    }

    return NULL;
}

int lookupfunc(char* name,struct funTab* head){
    //printf("Fun Lookup: %s\n",name);
    struct funTab* temp= (struct funTab*)malloc(sizeof(struct funTab));
    if(head->next!=NULL)
        temp= head;
    else
        return 0;
    while (temp!=NULL){
        //printf("%s\n",temp->name);
        if(!strcmp(name,temp->name)){

            return 1;
        }
        temp=temp->next;
    }
    
    return 0;
}

struct funTab* findfunc(char* name,struct funTab* head){
    struct funTab* temp= (struct funTab*)malloc(sizeof(struct funTab));
    if(head->next!=NULL)
        temp= head;
    else
        return NULL;
    while (temp!=NULL){
        //printf("%s\n",temp->name);
        if(!strcmp(name,temp->name)){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}
int insertfunc(char* type, char* name,int ifDef,int num, struct symTab* param[MAX_SIZE], struct funTab* head){
    //printf("Insert: %s\n",name);
    struct funTab* temp= (struct funTab*)malloc(sizeof(struct funTab));
    temp=head;
    while (temp->next!=NULL){
        //printf("%s\n",temp->name);
        temp=temp->next;
    }
    struct funTab* newFun= (struct funTab*)malloc(sizeof(struct funTab));
    newFun->type=newType(type);
    newFun->name=name;
    newFun->next=NULL;
    newFun->ifDef=ifDef;
    if(num>MAX_SIZE){
        printf("parameter number out of bound");
        return 0;
    }
    newFun->pnum=num;
    for(int i=0;i<num;i++){
        newFun->param[i]=param[i];
    }
    temp->next=newFun;
    return 1;
}

int checkReturn(struct Type*type,struct node*node){
    
    if(node!=NULL&&node->line!=-1){
        if(strcmp(node->child[0]->name,"RETURN")==0){//type check
            //printf("REQUIRE: %s RETURN: %s\n",type->name,node->child[1]->type->name);
            if(type->category==STRUCTURE&&node->child[1]->type->category==STRUCTURE){//TODO
                //printf("uname: %s,%s\n",type->uName,node->child[1]->type->uName);
                if(strcmp(type->uName,node->child[1]->type->uName)!=0){
                    printf("Error type 8 at Line %d: incompatiable return type\n",node->child[0]->line);
                    return 0;
                }
            }
            if(type->category==ARRAY&&node->child[1]->type->category==ARRAY){//TODO
            }
            if(strcmp(type->name,node->child[1]->type->name)!=0){
                printf("Error type 8 at Line %d: incompatiable return type\n",node->child[0]->line);
                return 0;
            }
            if(strcmp(node->child[1]->type->name,"error")==0)
                return 0;
            return 1;
        }
        int flag=1;
        for(int i=0;i<node->num;i++){
            //printf("%s ",node->child[i]->name);
            if(strcmp(node->child[i]->name,"Stmt")==0||strcmp(node->child[i]->name,"CompSt")==0||strcmp(node->child[i]->name,"StmtList")==0)
                if(checkReturn(type,node->child[i])==0)
                    flag=0;
        } 
        //printf("\n");
        return flag;
    }
}

int lookuparr(char* name, struct arrTab* head){
    struct arrTab* temp= (struct arrTab*)malloc(sizeof(struct arrTab));
    if(head->next!=NULL)
        temp= head;
    else
        return 0;
    while (temp!=NULL){
        //printf("%s\n",temp->name);
        if(!strcmp(name,temp->name)){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int insertarr(struct Type* type, char* name, struct arrTab* head){
    struct arrTab* newArr=(struct arrTab*)malloc(sizeof(struct arrTab));
    newArr->name=name;
    newArr->type=type;
    struct arrTab* temp= (struct arrTab*)malloc(sizeof(struct arrTab));
    temp=head;
    while (temp->next!=NULL){
        //printf("%s\n",temp->name);
        temp=temp->next;
    }
    temp->next=newArr;
    return 1;
}

struct arrTab* findarr(char* name, struct arrTab* head){
    struct arrTab* temp= (struct arrTab*)malloc(sizeof(struct arrTab));
    if(head->next!=NULL)
        temp= head;
    else
        return NULL;
    while (temp!=NULL){
        //printf("%s\n",temp->name);
        if(!strcmp(name,temp->name)){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}


int lookupstr(char* name,struct strTab* head){
    //printf("Struct Lookup: %s\n",name);
    struct strTab* temp= (struct strTab*)malloc(sizeof(struct strTab));
    if(head->next!=NULL)
        temp= head;
    else
        return 0;
    while (temp!=NULL){
        //printf("%s\n",temp->name);
        if(!strcmp(name,temp->name)){
            return 1;
        }
        temp=temp->next;
    }
    return 0;
}

int insertstr(struct Type* type, char* name, struct strTab* head){
    struct strTab* newStr=(struct strTab*)malloc(sizeof(struct strTab));
    newStr->name=name;
    newStr->type=type;
    struct strTab* temp= (struct strTab*)malloc(sizeof(struct strTab));
    temp=head;
    while (temp->next!=NULL){
        //printf("%s\n",temp->name);
        temp=temp->next;
    }
    temp->next=newStr;
    return 1;
}

struct strTab* findstr(char* name,struct strTab* head){
    struct strTab* temp= (struct strTab*)malloc(sizeof(struct strTab));
    if(head->next!=NULL)
        temp= head;
    else
        return NULL;
    while (temp!=NULL){
        //printf("%s\n",temp->name);
        if(!strcmp(name,temp->name)){
            return temp;
        }
        temp=temp->next;
    }
    return NULL;
}

struct node* createNode(char* name,struct node* childs[MAX_SIZE],int num){
    
    struct node *a=(struct node *)malloc(sizeof(struct node));
    a->name = name;
    for(int i=0;i<num;i++){
        a->child[i]=childs[i];
    }
    a->line= childs[0]->line;
    a->num = num;
    a->id = childs[0]->id;
    a->type=childs[0]->type;
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
            a->ival=atoi(t);
            //printf("%d\n",a->ival);
        }
        }
    else if(!strcmp(a->name,"FLOAT")) {
        char*t=(char*) malloc(sizeof(char*)*40);
        strcpy(t,value);
        a->fval=t;
        }
    else if(!strcmp(a->name,"CHAR")) {
        char*t=(char*) malloc(sizeof(char*)*40);
        strcpy(t,value);
        a->cval=t;
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
