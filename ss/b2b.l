%{
    #include<stdio.h>
    int flag = 0;
%}
ws [ \t\n]
%%
{ws}[aA][nN][dD]{ws} {flag = 1;}
{ws}[oO][rR]{ws} {flag = 1;}
{ws}[bB][uU][tT]{ws} {flag = 1;}
%%
int main()
{
    printf("Enter a sentence and press Ctrl + D to execute:\n");
    yylex();
    if (flag == 0)
        printf("Simple sentence.\n");
    else
        printf("Compound sentence.\n");
    return 0;
}