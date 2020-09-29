%{
    #include"lex.yy.c"
    void yyerror(const char*);
%}

%token LC RC LB RB COLON COMMA
%token STRING NUMBER ERROR
%token TRUE FALSE VNULL
%%

Json:
      Value
    | ERROR error{puts("wrong number, recovered");}
    ;
Value:
      Object 
    | Array
    | STRING
    | NUMBER
    | TRUE
    | FALSE
    | VNULL
    | ERROR error {puts("wrong number, recovered");}
    | Object STRING error {puts("misplaced value, recovered");}
    ;
Object:
      LC RC
    | LC Members RC
    | LC Members RB error {puts("unmatched right brace, recovered");}
    | LC Members COMMA error {puts("comma instead brace, recovered");}
    | LC Members error {puts("missing right brace, recovered");}
    ;
Members:
      Member
    | Member COMMA Members
    | Member Members error{puts("missing comma, recovered");}
    | Member COMMA error {puts("extra comma, recovered");}
    | Member COLON Members error {puts("colon instead comma, recovered");}
    ;
Member:
      STRING COLON Value
    | Value COLON Value error {puts("no_quoted key, recovered");}
    | STRING error {puts("wrong colon, recovered");}
    | STRING COMMA Value error {puts("comma instead colon, recovered");}
    | STRING COMMA Value COMMA error {puts("extra comma, recovered");};
Array:
      LB RB
    | LB Values RB
    | LB Values RB RB error {puts("extra close, recovered");}
    | LB Values RC error { puts("unmatched right bracket, recovered"); }
    | LB Values COMMA error {puts("comma instead bracket, recovered");}
    | LB Values RB COMMA error{puts("comma after close, recovered");}  
    | LB Values error {puts("unclosed array, recovered");}
    ;
Values:
      Value
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
