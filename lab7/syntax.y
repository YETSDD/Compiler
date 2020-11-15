%{
    #define YYSTYPE char*
    #include"lex.yy.c"
    
    void yyerror(const char*);
%}

%token LC RC LB RB COLON COMMA
%token STRING NUMBER ERROR
%token TRUE FALSE VNULL
%%

Json:
      Value {printf("begin");}
    | ERROR error{puts("wrong number, recovered");}
    ;
Value:
      Object  {$$ = $1;}
    | Array {$$ = $1;}
    | STRING {printf("string: %s\n",$1);$$ = $1;}
    | NUMBER {printf("number: %s\n",$1);$$ = $1;}
    | TRUE {$$ = $1;}
    | FALSE {$$ = $1;}
    | VNULL  {$$ = $1;}
    | ERROR error {puts("wrong number, recovered");}
    | Object STRING error {puts("misplaced value, recovered");}
    ;
Object:
      LC RC 
    | LC Members RC {printf("Object\n");}
    | LC Members RB error {puts("unmatched right brace, recovered");}
    | LC Members COMMA error {puts("comma instead brace, recovered");}
    | LC Members error {puts("missing right brace, recovered");}
    ;
Members:
      Member 
    | Member COMMA Members {printf("Member\n");}
    | Member Members error{puts("missing comma, recovered");}
    | Member COMMA error {puts("extra comma, recovered");}
    | Member COLON Members error {puts("colon instead comma, recovered");}
    ;
Member:
      STRING COLON Value 
      {printf("Member\n");
      struct ObjectMember *newMem = (struct ObjectMember*)malloc(sizeof(struct ObjectMember));
      newMem->key=$1;
      newMem->value=$3;
      newMem->next=NULL;
      }
    | Value COLON Value error {puts("no_quoted key, recovered");}
    | STRING error {puts("wrong colon, recovered");}
    | STRING COMMA Value error {puts("comma instead colon, recovered");}
    | STRING COMMA Value COMMA error {puts("extra comma, recovered");};
Array:
      LB RB 
    | LB Values RB 
    {printf("Array\n");
    struct ArrayValue *newArray=(struct ArrayValue*)malloc(sizeof(struct ArrayValue)); 
    newArray->value=$2;$$= $2;}
    | LB Values RB RB error {puts("extra close, recovered");}
    | LB Values RC error { puts("unmatched right bracket, recovered"); }
    | LB Values COMMA error {puts("comma instead bracket, recovered");}
    | LB Values RB COMMA error{puts("comma after close, recovered");}  
    | LB Values error {puts("unclosed array, recovered");}
    ;
Values:
    Value 
    {printf("Values: %s\n",(char*)$1);
    struct ArrayValue *newArray=(struct ArrayValue*)malloc(sizeof(struct ArrayValue));
    struct JsonObject *newObj=(struct JsonObject*)malloc(sizeof(struct JsonObject));
    char*t=(char*) malloc(sizeof(char*)*40);
    strcpy(t,$1);
    newObj->string=t;
	newArray->value=newObj;
	printf("Values over");}
    | Value COMMA Values 
    | Value COLON Values error {puts("colon instead comma, recovered");}
    | Values COMMA COMMA error {puts("extra comma, recovered");}
    | COMMA Values error {puts("missing value, recovered");}
    | Value COMMA error {puts("extra comma, recovered");}
    ;
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
