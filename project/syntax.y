%{
    #include"lex.yy.c"
    
    void yyerror(const char*);


%}

%union{
    struct node* n;
    double d;
}

%token <n> INT FLOAT CHAR ID 
%token <n> TYPE STRUCT IF ELSE WHILE RETURN DOT SEMI COMMA ASSIGN 
%token <n> LT LE GT GE NE EQ PLUS MINUS MUL DIV AND OR NOT
%token <n> LP RP LC RC LB RB 
%type  <n> Program ExtDefList ExtDef ExtDecList Specifier StructSpecifier VarDec  FunDec VarList CompSt ParamDec StmtList Stmt DefList Def DecList Dec Exp Args

%right ASSIGN
%left OR
%left AND 
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LC RC LB RB DOT 
%%

Program: ExtDefList {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Program",temp,1); travesal($$,0);};
ExtDefList: ExtDef ExtDefList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("ExtDefList",temp,2);}
|{$$ = createLeafNode("ExtDefList",-1,"");};
ExtDef: Specifier ExtDecList SEMI {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("ExtDef",temp,3);}
| Specifier SEMI {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("ExtDef",temp,2);}
| Specifier FunDec CompSt {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("ExtDef",temp,3);} ;
ExtDecList: VarDec {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("ExtDecList",temp,1);}
| VarDec COMMA ExtDecList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("ExtDecList",temp,3);};
/* specifier */
Specifier: TYPE {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Specifier",temp,1);}
| StructSpecifier {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Specifier",temp,1);};
StructSpecifier: STRUCT ID LC DefList RC {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; temp[4]= $5;$$ = createNode("StructSpecifier",temp,5);}
| STRUCT ID {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("StructSpecifier",temp,2);};
/* declarator */
VarDec: ID {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("VarDec",temp,1);}
| VarDec LB INT RB {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("VarDec",temp,4);};
FunDec: ID LP VarList RP {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("FunDec",temp,4);}
| ID LP RP {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("FunDec",temp,3);};
VarList: ParamDec COMMA VarList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("VarList",temp,3);}
| ParamDec {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("VarList",temp,1);};
ParamDec: Specifier VarDec {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("ParamDec",temp,2);};
/* statement */
CompSt: LC DefList StmtList RC {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("CompSt",temp,4);};
StmtList: Stmt StmtList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("StmtList",temp,2);}
|{$$ = createLeafNode("StmtList",-1,"");};
Stmt: Exp SEMI {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("Stmt",temp,2);}
| CompSt {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Stmt",temp,1);}
| RETURN Exp SEMI {printf("return");struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Stmt",temp,3);}
| IF LP Exp RP Stmt ELSE Stmt {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; temp[4]= $5; temp[5]= $6; temp[6] = $7;$$ = createNode("Stmt",temp,7);}
| IF LP Exp RP Stmt {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("Stmt",temp,4);}
| WHILE LP Exp RP Stmt {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; temp[4]= $5;$$ = createNode("Stmt",temp,5);};
/* local definition */
DefList: Def DefList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("DefList",temp,2);}
|{$$ = createLeafNode("DefList",-1,"");};
Def: Specifier DecList SEMI {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Def",temp,3);};
DecList: Dec {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("DecList",temp,1);}
| Dec COMMA DecList {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("DecList",temp,3);};
Dec: VarDec {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Dec",temp,1);}
| VarDec ASSIGN Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Dec",temp,3);};
/* Expression */
Exp: Exp ASSIGN Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp AND Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp OR Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp LT Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp LE Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp GT Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp GE Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp NE Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp EQ Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp PLUS Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp MINUS Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp MUL Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp DIV Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| LP Exp RP {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| MINUS Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("Exp",temp,2);}
| NOT Exp {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2;$$ = createNode("Exp",temp,2);}
| ID LP Args RP {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("Exp",temp,4);}
| ID LP RP {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| Exp LB Exp RB {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; temp[3]= $4; $$ = createNode("Exp",temp,4);}
| Exp DOT ID {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Exp",temp,3);}
| ID {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Exp",temp,1);}
| INT {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Exp",temp,1);}
| FLOAT {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Exp",temp,1);}
| CHAR {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Exp",temp,1);};
Args: Exp COMMA Args {struct node*temp[MAX_SIZE];temp[0]=$1; temp[1]=$2; temp[2]=$3; $$ = createNode("Args",temp,3);}
| Exp {struct node*temp[MAX_SIZE];temp[0]=$1; $$ = createNode("Args",temp,1);};

%%

void yyerror(const char *s){
    printf("syntax error: ");
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
