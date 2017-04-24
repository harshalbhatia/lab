%{
    #include<stdio.h>
    int pc = 0, sc = 0, mc = 0, dc = 0, valid = 0, i = 0;
%}
opnd [A-Za-z0-9]+
opr [+*/-]
%%
{opnd}({opr}{opnd})+[\n] {
            valid = 1;
            for (i = 0; yytext[i]!= '\0'; i++)
            {
                switch(yytext[i])
                {
                    case '+': pc++; break;
                    case '-': sc++; break;
                    case '*': mc++; break;
                    case '/': dc++; break;
                }
            }
            return(0);
        }
^{opnd}[\n] {
                printf("Only operand given.\n");
                exit(0);
            }
%%
int main()
{
    printf("Enter an expression:\n");
    yylex();
    if (valid == 1)
    {
        printf("Valid expression.\n");
        printf("No. of + are %d\n", pc);
        printf("No. of - are %d\n", sc);
        printf("No. of * are %d\n", mc);
        printf("No. of / are %d\n", dc);
        printf("No. of operands are %d\n", pc + sc + mc + dc+1);
    }
    else
    {
        printf("Invalid expression.");
    }
}