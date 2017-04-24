%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    int yyparse();
    int yyerror();
%}
%token A B
%%
expr: A recA recB '\n' {
    printf("Valid string.\n");
    exit(0);
}

recA: recA A
    |
    ;
recB: recB B
    |
    ;
%%
int main()
{
    printf("Enter a string:\n");
    yyparse();
}
int yyerror()
{
    printf("Invalid string.\n");
    exit(0);
}