%{
    #include"lex.yy.c"

    void yyerror(const char *s){
    printf("Error type B ");
    }
    struct symTab* head;

    struct funTab* funHead;
    struct arrTab* arrHead;
    struct strTab* strHead;
    struct varTab* varHead;
    struct resTab* resHead;
    int varnum = 1;
    int resnum = 1;
    int labelnum = 0;
    int debug=0;
%}

%union{
    struct node* n;
    double d;
}

%token <n> INT FLOAT CHAR ID ERROR
%token <n> TYPE STRUCT IF ELSE WHILE RETURN DOT SEMI COMMA ASSIGN 
%token <n> LT LE GT GE NE EQ PLUS MINUS MUL DIV AND OR NOT
%token <n> LP RP LC RC LB RB 
%type  <n> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier VarDec  FunDec VarList CompSt ParamDec StmtList Stmt DefList Def DecList Dec Exp Args

%right ASSIGN 
%left OR
%left AND 
%left PLUS MINUS
%left MUL DIV
%right NOT
%left LP RP LC RC LB RB  
%left DOT
%%

Program: ExtDefList {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Program",temp,1); 
//if(!hasError)travesal($$,0);
};
ExtDefList: ExtDef ExtDefList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("ExtDefList",temp,2);}
|{$$ = createLeafNode("ExtDefList",-1,"");};
ExtDef: Specifier ExtDecList SEMI { 
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("ExtDef",temp,3);}
    
| Specifier SEMI {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("ExtDef",temp,2);}
| Specifier FunDec CompSt {
    //project3 GENERATE
    if(debug)printf("Begin\n");
    printf("%s",$3->code);
    // struct node*compSt=(struct node *)malloc(sizeof(struct node));
    // compSt = $3->child[1];
    // while(compSt->num>0){
    // struct node*dec=(struct node *)malloc(sizeof(struct node));
    // dec=compSt->child[0]->child[1];
    // while(dec->num==3){
    //     //if(strcmp("",dec->child[0]->code))
    //     if(debug)  printf("def %s",dec->child[0]->code);
    //     else printf("%s",dec->child[0]->code);
    //     dec=dec->child[2];
    // }
    // dec=dec->child[0];
    // //if(strcmp("",dec->child[0]->code))
    // if(debug)  printf("def %s",dec->code);
    // else printf("%s",dec->code);
    // compSt=compSt->child[1];
    // }
    // compSt = $3->child[2];
    // while(compSt->num==2){
    //     if(debug)printf("stmt: %s",compSt->child[0]->code);
    //     else printf("%s",compSt->child[0]->code);
    //     compSt=compSt->child[1];
    // }
    // if(debug){
    //     struct resTab* res=(struct resTab*)malloc(sizeof(struct resTab));
    //     res = resHead;
    //     while(res->next!=NULL){
    //         printf("%s,%s,%s,%s\n",res->opera,res->var1,res->var2,res->var3);
    //         res = res->next;
    //     }
    // }

    //printf("Func: %s %s ",$1->type->name,$2->id);
    findfunc($2->id,funHead)->type=$1->type;
    struct node* tmp=(struct node*)malloc(sizeof(struct node));
    tmp=$3->child[2];//StmtList
    while(tmp->num==2){
        struct node* stmt=(struct node*)malloc(sizeof(struct node));
        stmt=tmp->child[0];
        //printf("CHECK RETURN\n");
        if(checkReturn($1->type,stmt)==0)
            hasError=1;
        tmp=tmp->child[1];
    }
    //printf("Type check:%s %s",$1->id,$2->id);
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("ExtDef",temp,3);
    } ;
ExtDecList: VarDec {
    // if(lookup($1->id,head)==1){ 
    //     printf("Error type 3 at Line %d: variable %s is redefined\n", $1->line, $1->id);
    //     hasError=1;
    //     }
    // else{
    //     printf("not exist\n");
    //     struct symTab *newSym=newSymTab("",$1->id);
    //     insert("",$1->id,head);
  struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("ExtDecList",temp,1);}

| VarDec COMMA ExtDecList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("ExtDecList",temp,3);};

/* specifier */
Specifier: TYPE {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Specifier",temp,1);$$->type=newType($1->id);}
| StructSpecifier {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Specifier",temp,1);$$->type=$1->type;};
StructSpecifier: STRUCT ID LC DefList RC {
    //printf("Struct Specifier");
    if(lookupstr($2->id,strHead)==1){
        printf("Error type 15 at Line %d: structure %s is redefined\n", $2->line, $2->id);
        hasError=1;
    }
    //printf("struct id valid %s",$2->id);
    struct Type* strType=newType("STRUCT");
    strcpy(strType->uName,$2->id);
    struct node* tmp=(struct node *)malloc(sizeof(struct node));
    tmp=$4;
    //printf("tmp: %s %d",tmp->name,tmp->num);
     while(tmp->num==2){
        struct Type* type=tmp->child[0]->child[0]->type;
        struct node* dec=(struct node *)malloc(sizeof(struct node));
        dec=tmp->child[0]->child[1];
        while(dec->num==3){
            struct FieldList* newField=(struct FieldList *)malloc(sizeof(struct FieldList));
            strcpy(newField->name,dec->child[0]->id);
            newField->type=type;
            newField->next=NULL;
            if(strType->structure==NULL)
                strType->structure=newField;
            else
                strType->structure->next=newField;
            dec=dec->child[2];
        }
        struct FieldList* newField=(struct FieldList *)malloc(sizeof(struct FieldList));
        strcpy(newField->name,dec->child[0]->id);

        newField->type=type;
        newField->next=NULL;
        if(strType->structure==NULL)
            strType->structure=newField;
        else
            strType->structure->next=newField;
        tmp=tmp->child[1];
    }
    insertstr(strType,$2->id,strHead);
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; temp[4]= $5;$$ = createNode("StructSpecifier",temp,5);
    $$->type=strType;
    }
| STRUCT ID {
    //printf("use struct\n");
    if(lookupstr($2->id,strHead)==0){
        printf("Error type 14 at Line %d: structure %s is undefined\n", $2->line, $2->id);
        hasError=1;
    }

    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("StructSpecifier",temp,2);$$->type=findstr($2->id,strHead)->type;};

/* declarator */
VarDec: ID {
    //printf("VarDec ID: %s\n",$1->id);
    if(lookup($1->id,head)==1||lookupfunc($1->id,funHead)==1||lookupstr($1->id,strHead)==1||lookuparr($1->id,arrHead)==1){ 
        printf("Error type 3 at Line %d: variable %s is redefined\n",$1->line, $1->id);
        hasError=1;
        }
    else{
        //printf("not exist\n");
        // struct symTab *newSym=newSymTab("",$1->id);
        insert("",$1->id,head);
    struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("VarDec",temp,1);}
    //project3
    //struct varTab* tmp= (struct varTab*)malloc(sizeof(struct varTab));
    newVarTab($1->id,varHead);
    varnum++;
    // if(tmp!=NULL){
    //     printf("exist\n");
    // }
    char* a=(char*)malloc(10);
    sprintf(a,"v%d",lookupVar($1->id,varHead));
    //printf("change place %s\n",a);
    $$->place=a;
    $$->code = "";
    }
| VarDec LB INT RB {
    
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("VarDec",temp,4);};
FunDec: ID LP VarList RP {
    //project3 function
    printf("FUNCTION %s :\n",$1->id);
    //TODO parameters
    struct node* para=(struct node *)malloc(sizeof(struct node));
    para = $3;
    while (para->num==3){
        if(lookupVar(para->child[0]->child[1]->child[0]->id,varHead)){
            printf("PARAM v%d\n",lookupVar(para->child[0]->child[1]->child[0]->id,varHead));
        }
        else{
            printf("PARAM v%d\n",varnum);
            varnum++;
            newVarTab(para->child[0]->child[1]->child[0]->id,varHead);
        }
        if(debug) printf("%s",para->child[0]->child[1]->child[0]->id);
        
        para = para->child[2];
    }
    if(para->num!=0){
        if(lookupVar(para->child[0]->child[1]->child[0]->id,varHead)){
            printf("PARAM v%d\n",lookupVar(para->child[0]->child[1]->child[0]->id,varHead));
        }
        else{
            printf("PARAM v%d\n",varnum);
            varnum++;
            newVarTab(para->child[0]->child[1]->child[0]->id,varHead);
        }
        
        if(debug) printf("%s\n",para->child[0]->child[1]->child[0]->id);

    }
    //printf("FunDec ID: %s\n",$1->id);
    if(lookupfunc($1->id,funHead)==1){ 
        printf("Error type 4 at Line %d: function %s is redefined\n",$1->line, $1->id);
        hasError=1;
        }
    else{
        struct symTab* param[MAX_SIZE];
        int pnum=0;
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=$3;
        while(tmp->num==3){
            char *type=tmp->child[0]->child[0]->id;
            char *name=tmp->child[0]->child[1]->id;
            if(findType(name,head)==NULL&&strcmp(findType(name,head)->name,"")==0)
            setType(type,name,head);
            //printf("%s %s\n",type,name);
            param[pnum]=newSymTab(type,name);
            pnum++;
            tmp=tmp->child[2];
        }
        char *type=tmp->child[0]->child[0]->id;
        char *name=tmp->child[0]->child[1]->id;
        if(findType(name,head)==NULL&&strcmp(findType(name,head)->name,"")==0)
        setType(type,name,head);
        //printf("%s %s\n",tmp->child[0]->child[0]->id,tmp->child[0]->child[1]->id);
        param[pnum]=newSymTab(type,name);
        pnum++;
        //printf("Parameter number: %d",pnum);
        insertfunc("int",$1->id,1,pnum,param,funHead);
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("FunDec",temp,4);}
    }
| ID LP RP {
    //project3 function
    printf("FUNCTION %s :\n",$1->id);


    //printf("ID: %s",$1->id);
    if(lookupfunc($1->id,funHead)==1){ 
        printf("Error type 4 at Line %d: function %s is redefined\n",$1->line, $1->id);
        hasError=1;
        }
    else{
        struct symTab* param[MAX_SIZE];
        insertfunc("int",$1->id,1,0,param,funHead);
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("FunDec",temp,3);}
    }
;
VarList: ParamDec COMMA VarList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("VarList",temp,3);}
| ParamDec {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("VarList",temp,1);};
ParamDec: Specifier VarDec {
       struct Type* type=$1->type;
    //printf("Def %s\n",type->name);
    if(type->category==PRIMITIVE){
    
        //printf("DEF: %s %s %s\n",$1->name,type->name,$2->name);
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=$2;
        
        if(tmp->num==4){
                //printf("ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp;
                while(var->num==4){
                    ////printf("newArray: %s,  %s, %d",oldType->name,var->child[2]->type->name,var->child[2]->ival);
                    oldType=newArrType(oldType,var->child[2]->ival);
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
        }
        else{
            //printf("PRIMITIVE");
            if(findType(tmp->child[0]->id,head)!=NULL&&strcmp(findType(tmp->child[0]->id,head)->name,"")!=0){//match type of Specifier and DecList
                struct Type* type=findType(tmp->child[0]->id,head);
                //printf("Type check: %s, %s\n",$1->id,type->name);
                if(strcmp(type->name,$1->id)!=0){
                    printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->id,type->name);
                    hasError=1;
                }
            }
            else{
                //printf("-----\n");
                setType($1->type->name,tmp->child[0]->id,head);
            }
            
        }

    }

    else if(type->category==STRUCTURE){

        //printf("STRUCT");
        //printf("DEF: %s %s %s\n",$1->name,type->uName,$2->name);
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=$2;

        while(tmp->num==3){
            if(tmp->child[0]->child[0]->num==4){
                //printf("STRUCT ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    oldType=newArrType(oldType,atoi(var->child[3]->id));
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
            }
            else{
            if(findType(tmp->child[0]->id,head)!=NULL&&strcmp(findType(tmp->child[0]->id,head)->name,"")!=0){//match type of Specifier and DecList
                struct Type* type=findType(tmp->child[0]->id,head);
                //printf("Type check: %s, %s\n",$1->id,type->name);
                if(strcmp(type->name,$1->id)!=0){
                    printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->id,type->name);
                    hasError=1;
                }
            }
            else{
                //printf("Set type: %s,%s\n",type->uName,tmp->child[0]->id);
                // setType(type->name,tmp->child[0]->id,head);
                findSym(tmp->child[0]->id,head)->type=findstr(type->uName,strHead)->type;
            }
            }
            tmp=tmp->child[2];
        }

        if(tmp->child[0]->child[0]->num==4){
                //printf("STRUCT ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    oldType=newArrType(oldType,var->child[2]->ival);
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
            }
        else{
            //printf("Set type: %s,%s\n",type->uName,tmp->child[0]->id);
            findSym(tmp->child[0]->id,head)->type=findstr(type->uName,strHead)->type;
        }
    }
    //printf("finish: %s %s\n",$2->child[0]->id,findType($2->child[0]->id,head)->name);
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("ParamDec",temp,2);};

/* statement */
CompSt: LC DefList StmtList RC {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("CompSt",temp,4);
//TODO
char code1[10000]="";
char code2[10000]="";

struct node*compSt=(struct node *)malloc(sizeof(struct node));
compSt = $2;
while(compSt->num>0){
struct node*dec=(struct node *)malloc(sizeof(struct node));
dec=compSt->child[0]->child[1];
while(dec->num==3){
    //if(strcmp("",dec->child[0]->code))
    //if(debug)  printf("def %s",dec->child[0]->code);
    //else printf("%s",dec->child[0]->code);
    strcat(code1,dec->child[0]->code);
    dec=dec->child[2];
}
dec=dec->child[0];
//if(strcmp("",dec->child[0]->code))
//if(debug)  printf("def %s",dec->code);
//else printf("%s",dec->code);
strcat(code1,dec->code);
compSt=compSt->child[1];
}
compSt = $3;
while(compSt->num==2){
    //if(debug)printf("stmt: %s",compSt->child[0]->code);
    //else printf("%s",compSt->child[0]->code);
    strcat(code2,compSt->child[0]->code);
    compSt=compSt->child[1];
}

char *code =(char*)malloc(100000);

sprintf(code,"%s%s",code1,code2);
$$->code = code;

};
StmtList: Stmt StmtList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("StmtList",temp,2);
//printf("Stmt: %s\n",$1->code);
}
|{$$ = createLeafNode("StmtList",-1,"");};
Stmt: Exp SEMI {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("Stmt",temp,2);
$$->code= $1->code;
//printf("code: %s",$$->code);
}
| CompSt {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Stmt",temp,1);
$$->code = $1->code;
$$->place = $1->place;
}
| RETURN Exp SEMI {
    //printf("RETURN\n");
    //printf("RETURN %s",$2->type->name);
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Stmt",temp,3);

    //printf("====%s\n",$2->code);
    char* code= (char*)malloc(10000);
    sprintf(code,"%sRETURN %s\n",$2->code,$2->place);
    //code = strcat($2->code,code);
    $$ -> code = code;
    }
| IF LP Exp RP Stmt ELSE Stmt 
{struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; temp[4]= $5; temp[5]= $6; temp[6] = $7;$$ = createNode("Stmt",temp,7);
//printf("IF %s GOTO label\n",$3->id);
//printf("GOTO label\n");
int label1 = labelnum;
labelnum++;
int label2 = labelnum;
labelnum++;
int label3 = labelnum;
labelnum++;
char *code1=(char*)malloc(100000);
sprintf(code1,"%s",$3->code);
char *code2=(char*)malloc(100000);
sprintf(code2,"IF %s GOTO label%d\n",$3->place,label1);
char *code3=(char*)malloc(100);
sprintf(code3,"GOTO label%d\n",label2);
char *code4=(char*)malloc(100000);
sprintf(code4,"LABEL label%d :\n%sGOTO label%d\nLABEL label%d :\n%sLABEL label%d :\n",label1,$5->code,label3,label2,$7->code,label3);
//printf("--------%s",code4);
char *code=(char*)malloc(400000);
if(debug)sprintf(code,"code1: %s code2: %s code3: %s code4: %s",code1,code2,code3,code4);
else sprintf(code,"%s%s%s%s",code1,code2,code3,code4);
$$->code = code;
//printf("code: %s",$$->code);
}
| IF LP Exp RP Stmt 
{struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("Stmt",temp,4);
int label1 = labelnum;
labelnum++;
int label2 = labelnum;
labelnum++;
char *code1=(char*)malloc(100000);
sprintf(code1,"%s",$3->code);
char *code2=(char*)malloc(100000);
sprintf(code2,"IF %s GOTO label%d\n",$3->place,label1);
char *code3=(char*)malloc(100);
sprintf(code3,"GOTO label%d\n",label2);
char *code4=(char*)malloc(100000);
sprintf(code4,"LABEL label%d :\n%sLABEL label%d :\n",label1,$5->code,label2);
//printf("--------%s",code4);
char *code=(char*)malloc(400000);
if(debug)sprintf(code,"code1: %s code2: %s code3: %s code4: %s",code1,code2,code3,code4);
else sprintf(code,"%s%s%s%s",code1,code2,code3,code4);
$$->code = code;
}
| WHILE LP Exp RP Stmt 
{struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; temp[4]= $5;$$ = createNode("Stmt",temp,5);
//TODO
int label1 = labelnum;
labelnum++;
int label2 = labelnum;
labelnum++;
int label3 = labelnum;
labelnum++;
char *code1=(char*)malloc(100000);
sprintf(code1,"LABEL label%d :\n%s",label1,$3->code);
char *code2=(char*)malloc(100000);
sprintf(code2,"IF %s GOTO label%d\n",$3->place,label2);
char *code3=(char*)malloc(100);
sprintf(code3,"GOTO label%d\n",label3);
char *code4=(char*)malloc(100000);
sprintf(code4,"LABEL label%d :\n%sGOTO label%d\nLABEL label%d :\n",label2,$5->code,label1,label3);
//printf("--------%s",code4);
char *code=(char*)malloc(400000);
if(debug)sprintf(code,"code1: %s code2: %s code3: %s code4: %s",code1,code2,code3,code4);
else sprintf(code,"%s%s%s%s",code1,code2,code3,code4);
$$->code = code;
};

/* local definition */
DefList: Def DefList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("DefList",temp,2);}
|{$$ = createLeafNode("DefList",-1,"");};
Def: Specifier DecList SEMI {
    struct Type* type=$1->type;
    //printf("Def %s\n",type->name);
    if(type->category==PRIMITIVE){
    
        //printf("DEF: %s %s %s\n",$1->name,type->name,$2->name);
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=$2;
        
        while(tmp->num==3){
            if(tmp->child[0]->child[0]->num==4){
                //printf("ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    oldType=newArrType(oldType,atoi(var->child[3]->id));
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
            }
            else{
                //printf("PRIMITIVE");
                if(findType(tmp->child[0]->id,head)!=NULL&&strcmp(findType(tmp->child[0]->id,head)->name,"")!=0){//match type of Specifier and DecList
                    struct Type* type=findType(tmp->child[0]->id,head);
                    //printf("Type check: %s, %s\n",$1->id,type->name);
                    if(strcmp(type->name,$1->id)!=0){
                        //printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->id,type->name);
                        hasError=1;
                    }
                }
                else{
                    //printf("======\n");
                    setType($1->id,tmp->child[0]->id,head);
                }
                
            }
            tmp=tmp->child[2];
        }
        
        if(tmp->child[0]->child[0]->num==4){
                //printf("ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    ////printf("newArray: %s,  %s, %d",oldType->name,var->child[2]->type->name,var->child[2]->ival);
                    oldType=newArrType(oldType,var->child[2]->ival);
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
        }
        else{
            //printf("PRIMITIVE");
            if(findType(tmp->child[0]->id,head)!=NULL&&strcmp(findType(tmp->child[0]->id,head)->name,"")!=0){//match type of Specifier and DecList
                struct Type* type=findType(tmp->child[0]->id,head);
                //printf("Type check: %s, %s\n",$1->id,type->name);
                if(strcmp(type->name,$1->id)!=0){
                    printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->id,type->name);
                    hasError=1;
                }
            }
            else{
                //printf("++++++\n");
                setType($1->id,tmp->child[0]->id,head);
            }
            
        }

    }

    else if(type->category==STRUCTURE){

        //printf("STRUCT");
        //printf("DEF: %s %s %s\n",$1->name,type->uName,$2->name);
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=$2;

        while(tmp->num==3){
            if(tmp->child[0]->child[0]->num==4){
                //printf("STRUCT ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    oldType=newArrType(oldType,atoi(var->child[3]->id));
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
            }
            else{
            if(findType(tmp->child[0]->id,head)!=NULL&&strcmp(findType(tmp->child[0]->id,head)->name,"")!=0){//match type of Specifier and DecList
                struct Type* type=findType(tmp->child[0]->id,head);
                //printf("Type check: %s, %s\n",$1->id,type->name);
                if(strcmp(type->name,$1->id)!=0){
                    printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->id,type->name);
                    hasError=1;
                }
            }
            else{
                //printf("Set type: %s,%s\n",type->uName,tmp->child[0]->id);
                // setType(type->name,tmp->child[0]->id,head);
                findSym(tmp->child[0]->id,head)->type=findstr(type->uName,strHead)->type;
            }
            }
            tmp=tmp->child[2];
        }

        if(tmp->child[0]->child[0]->num==4){
                //printf("STRUCT ARRAY");
                struct node* var=(struct node *)malloc(sizeof(struct node));
                struct Type* oldType=(struct Type*)malloc(sizeof(struct Type));
                oldType=type;
                var=tmp->child[0]->child[0];
                while(var->num==4){
                    oldType=newArrType(oldType,var->child[2]->ival);
                    var=var->child[0];
                }
                insertarr(oldType,var->child[0]->id,arrHead);
                findSym(var->child[0]->id,head)->type=oldType;
                //printf("set Type : %s %s\n",var->child[0]->id,oldType->name);
            }
        else{
            //printf("Set type: %s,%s\n",type->uName,tmp->child[0]->id);
            findSym(tmp->child[0]->id,head)->type=findstr(type->uName,strHead)->type;
        }
    }
    //printf("%d",lookup($2->name,head));
    // if(lookup($2->name,head)==1){printf("exist");hasError=1;}
    // else{
    //     printf("not exist");
    //     struct symTab *newSym=newSymTab("",$1->name,tail);
    //     tail=newSym;
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Def",temp,3);
};
DecList: Dec {
    //printf("DecList: Dec\n");
     struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("DecList",temp,1);}
| Dec COMMA DecList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("DecList",temp,3);}
;
Dec: VarDec {
    //printf("Dec: VarDec\n");
    struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Dec",temp,1);
    $$->code="";
    $$->place="";
    }
| VarDec ASSIGN Exp {
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Dec",temp,3); 
    setType($3->type->name,$1->id,head);
    //project3 
    char* code = (char*)malloc(1000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s := %s\n",$3->code,$1->place,$3->place);
    //sprintf(place,"");
    $$->code=code;
    $$->place="";
    }
|ERROR ASSIGN Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;temp[2]=$3; $$ = createNode("Dec",temp,3);}
|ERROR {struct node*temp[MAX_SIZE];temp[0]=$1;  $$ = createNode("Dec",temp,1);};
/* Expression */
Exp: 
Exp ASSIGN Exp { 
     //printf("%s ASSIGN %s\n",$1->type->name,$3->type->name);
     //printf("%s = %s\n",$1->place, $3->place);
    if(strcmp($1->type->name,$3->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;   
    }
    else if($1->id==NULL){
        printf("Error type 6 at Line %d: rvalue on the left side\n",$1->line);
        hasError=1;
    }
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);

    //project3
    
    
    char* code= (char*)malloc(10000);
    sprintf(code,"%s%s := %s \n",$3->code,$1->place,$3->place);
    $$ -> code = code;
    }
| Exp AND Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);
//
}
| Exp OR Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);
}
| Exp LT Exp {
    if(strcmp($1->type->name,$3->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3); $$->type=newType("int");
    //project3
    
    char* code= (char*)malloc(100);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",$1->code,$3->code);
    sprintf(place,"%s < %s",$1->place,$3->place);
    
    $$ -> code = code;
    $$->place=place;
    }
| Exp LE Exp {
    if(strcmp($1->type->name,$3->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("int");
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",$1->code,$3->code);
    sprintf(place,"%s <= %s",$1->place,$3->place);
    
    $$ -> code = code;
    $$->place=place;
    }
| Exp GT Exp {
    if(strcmp($1->type->name,$3->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("int");
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",$1->code,$3->code);
    sprintf(place,"%s > %s",$1->place,$3->place);
    
    $$ -> code = code;
    $$->place=place;
    }
| Exp GE Exp {
    if(strcmp($1->type->name,$3->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("int");
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",$1->code,$3->code);
    sprintf(place,"%s >= %s",$1->place,$3->place);
    
    $$ -> code = code;
    $$->place=place;
    }
| Exp NE Exp {
    if(strcmp($1->type->name,$3->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("int");
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",$1->code,$3->code);
    sprintf(place,"%s != %s",$1->place,$3->place);
    
    $$ -> code = code;
    $$->place=place;
    }
| Exp EQ Exp {
    if(strcmp($1->type->name,$3->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;   
    }
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("int");
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    sprintf(code,"%s%s",$1->code,$3->code);
    sprintf(place,"%s == %s",$1->place,$3->place);
    
    $$ -> code = code;
    $$->place=place;
    }
| Exp PLUS Exp {
    struct Type* type1=$1->type;
    struct Type* type2=$3->type;
    if(type1->category!=type2->category){
        printf("Error type 7 at Line %d: unmatching operands between %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;    
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("error");
    }   
    else if(strcmp($1->type->name,$3->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;  
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("error"); 
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);
    }
    //project3
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    
       if(debug) printf("'%s + %s' not exist,put into t%d\n",$1->place,$3->place,resnum);
        sprintf(place,"t%d",resnum);
        resnum++;
        newResTab("+",$1->place,$3->place,"",resHead);
        sprintf(code,"%s%s%s := %s + %s\n",$1->code,$3->code,place,$1->place,$3->place);
    
    
    $$ -> code = code;
    $$->place=place;
    //printf("%s%s\n",code,place);
}
| Exp MINUS Exp {
    struct Type* type1=$1->type;
    struct Type* type2=$3->type;
    if(type1->category!=type2->category){
        printf("Error type 7 at Line %d: unmatching operands between %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;    
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("error");
    }   
    else if(strcmp($1->type->name,$3->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;  
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("error"); 
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
    //project3
    //printf("MINUS\n");
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    
       if(debug) printf("'%s - %s' not exist,put into t%d\n",$1->place,$3->place,resnum);
        sprintf(place,"t%d",resnum);
        resnum++;
        newResTab("-",$1->place,$3->place,"",resHead);
        sprintf(code,"%s%s%s := %s - %s\n",$1->code,$3->code,place,$1->place,$3->place);
    
    
    $$ -> code = code;
    $$->place=place;
}
| Exp MUL Exp {
    struct Type* type1=$1->type;
    struct Type* type2=$3->type;
    //printf("type1: %s type2: %s\n",type1->name,type2->name);
    if(type1->category!=type2->category){
        printf("Error type 7 at Line %d: unmatching operands between %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;    
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("error");
    }   
    else if(strcmp($1->type->name,$3->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;  
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("error"); 
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
    //project3
    //printf("MUL: %s %s\n",$1->place,$3->place);
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
     
       if(debug) printf("'%s * %s' not exist,put into t%d\n",$1->place,$3->place,resnum);
        sprintf(place,"t%d",resnum);
        resnum++;
        newResTab("*",$1->place,$3->place,"",resHead);
        sprintf(code,"%s%s%s := %s * %s\n",$1->code,$3->code,place,$1->place,$3->place);
    
    
    $$ -> code = code;
    $$->place=place;
}
| Exp DIV Exp {
    struct Type* type1=$1->type;
    struct Type* type2=$3->type;
    if(type1->category!=type2->category){
        printf("Error type 7 at Line %d: unmatching operands between %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;    
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("error");
    }   
    else if(strcmp($1->type->name,$3->type->name)!=0){
        printf("Error type 5 at Line %d: unmatching type %s and %s\n",$1->line,$1->type->name,$3->type->name);
        hasError=1;  
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("error"); 
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
    //project3
    //printf("DIV\n");
    char* code= (char*)malloc(10000);
    char* place = (char*)malloc(10);
    
       if(debug) printf("'%s / %s' not exist,put into t%d\n",$1->place,$3->place,resnum);
        sprintf(place,"t%d",resnum);
        resnum++;
        newResTab("/",$1->place,$3->place,"",resHead);
        sprintf(code,"%s%s%s := %s / %s\n",$1->code,$3->code,place,$1->place,$3->place);
    
    
    $$ -> code = code;
    $$->place=place;
    }
| LP Exp RP {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=$2->type;
$$-> code = $2->code;
$$-> place = $2->place;
}
| MINUS Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("Exp",temp,2); $$->type=$2->type;}
| NOT Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("Exp",temp,2);$$->type=$2->type;}
| ID LP Args RP {
    //printf("func use\n");
    if(strcmp($1->id,"write")==0){
        //printf("WRITE %d\n",$3->child[0]->child[0]->ival); 
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("Exp",temp,4);
        
        char* code= (char*)malloc(10000);
        sprintf(code,"%sWRITE %s\n",$3->child[0]->code,$3->child[0]->place);  
        $$->code = code; 
        //printf("code: %s",$$->code);
    }
    else{
    if(lookupfunc($1->id,funHead)==0){
        printf("Error type 11 at Line %d: function %s is used without definition\n",$1->line,$1->id);
        hasError=1; 
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("Exp",temp,4);$$->type=newType("error");       
    }
    else {
        struct funTab* func= findfunc($1->id,funHead);
        //printf("=====================fun type: %s",func->type->name);
        struct node* tmp=(struct node *)malloc(sizeof(struct node));
        tmp=$3;
        int paraNum=0;
        int flag=1;
        while(tmp->num==3){
            //printf("para: %d %d",paraNum, func->pnum);
            
            //printf("type: %s, %s\n",tmp->child[0]->type->name,func->param[paraNum]->type->name);
            if(strcmp(tmp->child[0]->type->name,func->param[paraNum]->type->name)!=0){
                printf("Error type 9 at Line %d: function %s requires %s but recieve %s\n",$1->line,$1->id,func->param[paraNum]->type->name,tmp->child[0]->type->name);
                hasError=1;
                flag=0;
                break;
            }
            paraNum++;
            if(paraNum==func->pnum){
                printf("Error type 9 at Line %d: function %s recieves wrong number of args \n",$1->line,$1->id);
                    hasError=1;
                flag=0;
                break;
            }
            tmp=tmp->child[2];
        }
        //printf("type: %s, %s\n",tmp->child[0]->type->name,func->param[paraNum]->type->name);
        if(flag!=0){
            if(paraNum+1!=func->pnum){
                    printf("Error type 9 at Line %d: function %s recieves wrong number of args \n",$1->line,$1->id);
                    hasError=1;
                    flag=0;
            }
            else if(strcmp(tmp->child[0]->type->name,func->param[paraNum]->type->name)!=0){
                printf("Error type 9 at Line %d: function %s requires %s but recieve %s\n",$1->line,$1->id,func->param[paraNum]->type->name,tmp->child[0]->type->name);
                hasError=1;
                flag=0;
            }
        }
        
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("Exp",temp,4);
        if(flag){
            $$->type=func->type;
            //printf("REEEEEEEEEETURN %s",$$->type->name);
        }
        else
            $$->type=newType("error");
    }
	//project 3
    struct node* args=(struct node *)malloc(sizeof(struct node));
    args=$3;
    
    char* place= (char*)malloc(10);
    char code1[10000]="";
    char code2[10000]="";
    char* code3=(char*)malloc(10000);
    char* code =(char*)malloc(10000);
    sprintf(place,"t%d",resnum);
    resnum++;

    while(args->num==3){
        char tmp1[10000]="";
        sprintf(tmp1,"%s",args->child[0]->code);
        strcat(code1,tmp1);
        char tmp2[10000]="";
        sprintf(tmp2,"ARG %s\n",args->child[0]->place);
        strcat(tmp2,code2);
        strcpy(code2,tmp2);
        args=args->child[2];
    }
    char tmp1[10000]="";
    sprintf(tmp1,"%s",args->child[0]->code);
    strcat(code1,tmp1);
    char tmp2[10000]="";
    sprintf(tmp2,"ARG %s\n",args->child[0]->place);
    strcat(tmp2,code2);
    strcpy(code2,tmp2);
    
    
    //strcat(code2,args->child[0]->place);
    sprintf(code3,"%s := CALL %s\n",place,$1->id);  
    sprintf(code,"%s%s%s",code1,code2,code3);
    $$->code = code;
    $$->place= place;
    }
    }
| ID LP RP {
    //printf("Function use\n");
    if(strcmp($1->id,"read")==0){ //READ
        int num;
        struct resTab* temp = (struct resTab*)malloc(sizeof(struct resTab));

        //TODO optimize function getNum
        temp= resHead;
        while (temp->next!=NULL){
            temp=temp->next;
        }
        num=temp->num+1;
        
        char res[10];
        sprintf(res,"t%d",num);
        char* a= (char*)malloc(sizeof(res));
        strcpy(a,res);
        char* code=(char*)malloc(10000);
        sprintf(code,"READ %s\n",res);
        struct node*child[MAX_SIZE];child[0]=$1; child[1]=$2; child[2]=$3; $$ = createNode("Exp",child,3);$$->type=findfunc($1->id,funHead)->type;
        $$->place= a;
        $$->code = code;
        newResTab("read",a,"","",resHead);
        resnum++;
    }
    else{
    if(lookupfunc($1->id,funHead)==0){
        printf("Error type 11 at Line %d: function %s is used without definition\n",$1->line,$1->id);
        hasError=1;        
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("error");
    }
    else if(findfunc($1->id,funHead)->pnum!=0){
        printf("Error type 9 at Line %d: function %s requires %d parameters but recieve 0",$1->line,$1->id,findfunc($1->id,funHead)->pnum);
        hasError=1;
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("error");
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=findfunc($1->id,funHead)->type;
    }
    //project3
    char* place= (char*)malloc(10);
    char* code=(char*)malloc(10000);
    sprintf(place,"t%d",resnum);
    resnum++;
    sprintf(code,"%s := CALL %s\n",place,$1->id);
    $$->code = code;
    $$->place= place;
    }
}
| Exp LB Exp RB {
    //printf("%s\n",$1->type->name);
    if(strcmp($3->type->name,"int")!=0){
        printf("Error type 12 at Line %d: array indexing with non-integer value\n",$1->line);
        hasError=1;
    }
    else if($1->type->category!=ARRAY){
        printf("Error type 10 at Line %d: apply indexing operator to non-array variable\n",$1->line);
        hasError=1;
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("Exp",temp,4);$$->type=newType("error");
    }
    else{
    //printf("type is %s\n",$1->type->name);
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("Exp",temp,4);$$->type=$1->type->array->base;}
}
| Exp DOT ID {
    //printf("%s dot %s\n",$1->type->name,findType($3->id,head)->name);
    if(lookup($3->id,head)==0){
        printf("Error type 14 at Line %d: no such variable %s\n",$1->line,$3->id);
        hasError =1;
        struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=newType("error");
    }
    else if($1->type->category!=STRUCTURE){
        printf("Error type 13 at Line %d: non-structure variable\n",$1->line);
        hasError =1;
    }
    else{
    struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);$$->type=findType($3->id,head);}}
| ID {
    //printf("ID: %s %s\n",$1->id,findType($1->id,head)->name);
    if(lookup($1->id,head)==0){ 
        printf("Error type 1 at Line %d: variable %s is used without definition\n",$1->line,$1->id);
        hasError=1;
        struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Exp",temp,1);$$->type=newType("error");
        }
    else{
    struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Exp",temp,1);$$->type=findType($1->id,head);}
    //project3 
    //printf("ID: %s\n",$1->id);
    
    newVarTab($1->id,varHead);
    varnum++;
    char* a=(char*)malloc(10);
    sprintf(a,"v%d",lookupVar($1->id,varHead));
    //printf("change place %s\n",a);
    $$->place=a;
    $$->code = "";
    //memset(res,0,sizeof(res));
}
| INT {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Exp",temp,1);$$->type=newType("int");
    //project3
    char* value = (char*)malloc(10);
    sprintf(value,"#%d",$1->ival);
    char* a=(char*)malloc(10);
    char*code =(char*)malloc(10);
    if(lookupRes("int",value,"","",resHead)==0){
        if($1->ival<0){
            if(debug) printf("%s not exist,put into t%d\n",value,resnum);
        sprintf(a,"t%d",resnum);
        resnum++;
        char* tmp=(char*)malloc(10);
        sprintf(tmp,"t%d",resnum);
        resnum++;
        newResTab("int",value,"","",resHead);
        sprintf(code,"%s := #%d\n%s := #0 - %s\n",tmp,(-$1->ival),a,tmp);
        }
        else{
       if(debug) printf("%s not exist,put into t%d\n",value,resnum);
        sprintf(a,"t%d",resnum);
        resnum++;
        newResTab("int",value,"","",resHead);
        sprintf(code,"%s := #%d\n",a,$1->ival);
        }
    }
    else {
        if(debug) printf("%s exist in t%d\n",value,lookupRes("int",value,"","",resHead));
        sprintf(a,"t%d",lookupRes("int",value,"","",resHead));
        sprintf(code,"%s := #%d\n",a,$1->ival);
    }
    //TODO optional duplicate int
    
    //printf("CCCCCCCODE: %s\n",code);
    $$->place=a;
    $$->code = code;
    
}
| FLOAT {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Exp",temp,1);$$->type=newType("float");}
| CHAR {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Exp",temp,1);$$->type=newType("char");}
| ID LP Args error {hasError=1;printf("at line %d : Missing RP\n", $1->line);}
| ID LP error {hasError=1;printf("at line %d : Missing RP\n", $1->line);}
| LP Exp error {hasError=1;printf("at line %d : Missing RP\n", $2->line);}
| Exp ERROR Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| ERROR {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Exp",temp,1);};
Args: Exp COMMA Args {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Args",temp,3);}
| Exp {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Args",temp,1);}
| Exp SEMI Args error{hasError=1;printf("at line %d : COMMA instead of SEMI\n", $2->line);}
| Exp Args error{hasError=1;printf("at line %d : Missing COMMA\n", $2->line);};

%%

char* substr(const char* str, unsigned start, unsigned end){
    unsigned n=end-start;
    static char stbuf[256];
    strncpy(stbuf,str+start,n);
    stbuf[n]=0;
    return stbuf;
}


int main(int argc, char **argv){
    head=(struct symTab*)malloc(sizeof(struct symTab));
    head->name="header";
    head->next=NULL;
    
    // tail=(struct symTab*)malloc(sizeof(struct symTab));
    // tail=head;
    // struct symTab* newSym=newSymTab("","test");
    // insert("","i",head);

    // if(lookup("i",head)==1){
    //     printf("i exist\n");
    // }
    // else{
    //     struct symTab* temp=(struct symTab*)malloc(sizeof(struct symTab));
    //     temp=head;
    //     while(temp->next!=NULL){
    //         printf("%s %s\n",temp->type,temp->name);
    //         temp=temp->next;
    //     }
    // }
    funHead=(struct funTab*)malloc(sizeof(struct funTab));
    funHead->name="header";
    funHead->next=NULL;
    struct symTab* param[MAX_SIZE];
    
    insertfunc("int","read",1,0,param,funHead);
    insertfunc("int","write",1,1,param,funHead);
    arrHead=(struct arrTab*)malloc(sizeof (struct arrTab));
    arrHead->name="header";
    arrHead->next=NULL;

    strHead=(struct strTab*)malloc(sizeof(struct strTab));
    strHead->name="header";
    strHead->next=NULL;

    varHead=(struct varTab*)malloc(sizeof(struct varTab));
    varHead->name="header";
    varHead->num=0;
    varHead->next=NULL;

    resHead=(struct resTab*)malloc(sizeof(struct resTab));
    resHead->opera="header";
    resHead->num=0;
    resHead->next=NULL;

    //lookup("test",head);
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(-1);
    }
    else if(!(yyin = fopen(argv[1], "r"))) {
        perror(argv[1]);
        exit(-1);
    }
    if(debug){
        // printf("%s",argv[1]);
        
        // char* filepath=argv[1];
        // char* fileExt;
        // char* ptr,c='.';
        // ptr = strrchr(filepath,c);
        // int pos = ptr- filepath;
        // fileExt=substr(filepath,pos+1,strlen(filepath));
        // printf("%s",fileExt);
        // char* outpath="./test/output.out";
        // if(strcmp(fileExt,"spl")==0){
        //     int i= strlen(filepath);
        //     char* fn1=filepath+i;
        //     while(fn1>filepath){
        //         if(*fn1=='.'){
        //             *fn1=0;
        //             break;
        //         }
        //         fn1--;
        //     }
        //     outpath=strcat(filepath,".out");
        // }
        // printf("out %s",outpath);
        // if(freopen(outpath,"w",stdout)==NULL)
        //     printf("redirect fail");
    
    }
    else{
        char* filepath=argv[1];
        char* fileExt;
        char* ptr,c='.';
        ptr = strrchr(filepath,c);
        int pos = ptr- filepath;
        fileExt=substr(filepath,pos+1,strlen(filepath));
        //printf("%s",fileExt);
        char* outpath="./test/output.out";
        if(strcmp(fileExt,"spl")==0){
            int i= strlen(filepath);
            char* fn1=filepath+i;
            while(fn1>filepath){
                if(*fn1=='.'){
                    *fn1=0;
                    break;
                }
                fn1--;
            }
            outpath=strcat(filepath,".ir");
        }
        printf("out: %s",outpath);
        if(freopen(outpath,"w",stdout)==NULL)
            printf("redirect fail");
    }
    yyparse();
    return 0;
}
