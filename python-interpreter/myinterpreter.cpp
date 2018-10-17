#include<stdio.h>
#include"myScanner.h"

using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext;

char* names[] = {NULL, "variable", "integer", "comment"};

int main(void) {

    int ntoken, vtoken;

    ntoken = yylex();

    while(ntoken) {
        printf("%d %s\n", ntoken, yytext);
        ntoken = yylex();
    }
    printf("\n");

	return 0;
}
