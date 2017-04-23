%{
    #include<stdio.h>
    int wc = 0, cc = 0, lc = 0, sc = 0;
%}
wc [^ \n\t]+
sc [ ]
lc [\n]
%%
{wc} {wc++; cc+=yyleng;}
{lc} {lc++;}
{sc} {sc++; cc++;}
[\t] {sc+=6; cc+=6;}
%%
int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    yyin = fp;
    yylex();
    printf("Word count = %d\nCharacter count = %d\nSpace count = %d\nLine count = %d\n", wc, cc, sc, lc);    
}

// Execution:
//     $ lex b1a.l
//     $ gcc lex.yy.c -ll
//     $ ./a.out
//     (Then enter some text, press enter, then press Ctrl + D)
//     Hey, what's up with you?
//     I'm here man.
// Output:
//     Word count = 8
//     Character count = 37
//     Space count = 6
//     Line count = 2