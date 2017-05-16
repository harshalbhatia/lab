%{
    #include<stdio.h>
    int cc = 0;
%}
%x CMNT
%%
"/*" {BEGIN CMNT; cc++;}
<CMNT>. ;
<CMNT>\n ;
<CMNT>"*/" {BEGIN 0;}
. ECHO;
%%
int main(int argc, char **argv)
{
    if (argc < 3)
    {
        printf("Please enter 2 files:\n");
        exit(0);
    }
    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2], "w");
    yylex();
    printf("The no. of comment lines = %d\n", cc);
    return(0);
}
