#ifndef IF_STATEMENTS_H_INCLUDED
#define IF_STATEMENTS_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include "InfixToPostfix.h"
#include "expressions.h"

using namespace std;

//function to verify comparators in if statement
bool IsComp(char comp) {
    if(comp == '>') return true;
    else if(comp == '<') return true;
    else return false;
}

//function will evaluate the expression to determine the comparison
void IfStatement(string exp, vector<char>& var, vector<int>& res) {

    //if there exists a less than symbol
    if(exp.find("<") != string::npos) {
        //parse it to get the variables or numbers
        exp.erase(remove(exp.begin(), exp.end(), ' '), exp.end());

        char var1 = exp[exp.find('<')-1]; //first variable being compared
        char var2 = exp[exp.find('<')+1]; //second variable being compared

        //check if they are variables or integers
        bool compare = false; //temporary boolean trigger initialized to false

        //two integers
        if(IsOperand(var1) && IsOperand(var2))
            compare = (var1) < (var2);

        //integer and variable
        else if(IsOperand(var1) && IsVariable(var2)) {
            //find value of var2 and compare to var1
            for(int i = 0; i != var.size(); i++) {
                if(var2 == var[i])
                    compare = var1 < res[i];
            }
        }
        //variable and integer
        else if(IsVariable(var1) && IsOperand(var2)) {
            //find value of var2 and compare to var1
            for(int i = 0; i != var.size(); i++) {
                if(var1 == var[i])
                    compare = res[i] < var2;
            }
        }
        //variable and variable
        else if(IsVariable(var1) && IsVariable(var2)) {
            int int1, int2;
            //find value of var1 and var2 and compare
            for(int i = 0; i != var.size(); i++) {
                if(var1 == var[i])
                    int1 = res[i];
                else if(var2 == var[i])
                    int2 = res[i];
            }
            compare = int1 < int2;

        }
        //if cannot read then error
        else
            cout << "unexpected error" << endl;

        //evaluate the condition
        switch(compare) {
            case true:
                cout << "Statement was true" << endl;
                break;
            case false:
                cout << "Statement was false" << endl;
                break;
        }
    }
    //if there exists a greater than symbol
    else if(exp.find(">") != string::npos) {
        //parse it to get the variables or numbers
        exp.erase(remove(exp.begin(), exp.end(), ' '), exp.end());

        char var1 = exp[exp.find('<')-1]; //first variable being compared
        char var2 = exp[exp.find('<')+1]; //second variable being compared
    }
    //if no comparator terminate
    else {
        cout << "Error: no comparator" << endl;
        exit(1);
    }
}

#endif // IF_STATEMENTS_H_INCLUDED
