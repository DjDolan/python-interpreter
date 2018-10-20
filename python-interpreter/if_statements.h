#ifndef IF_STATEMENTS_H_INCLUDED
#define IF_STATEMENTS_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "InfixToPostfix.h"
#include "expressions.h"

using namespace std;

void IfBlock(vector<string>&); //prototype for if block instructions
void ElseBlock(); //prototype for else block instructions

//function to verify comparators in if statement
bool IsComp(char comp) {
    if(comp == '>') return true;
    else if(comp == '<') return true;
    else return false;
}

//function will evaluate the expression to determine the comparison
void IfStatement(vector<string>& if_ins, vector<char>& var, vector<int>& res) {
    //read the statement as its own program and evaluate
    //each line as its own set of instructions to run

    string condition = if_ins.front(); //the conditional statement whether or not to run
    bool compare = false; //comparison bool to determine which block to run

    //if there exists a less than symbol
    if(condition.find("<") != string::npos) {
        //parse it to get the variables or numbers
        condition.erase(remove(condition.begin(), condition.end(), ' '), condition.end());

        char var1 = condition[condition.find('<')-1]; //first variable being compared
        char var2 = condition[condition.find('<')+1]; //second variable being compared

        //check if they are variables or integers
        bool compare; //temporary boolean trigger initialized to false

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

        switch(compare) {
            case 1:
                IfBlock(if_ins);
                break;
            case 0:
                ElseBlock();
                break;
            default:
                break;
        }

    }
    //if there exists a greater than symbol
    else if(condition.find(">") != string::npos) {
        //parse it to get the variables or numbers
        condition.erase(remove(condition.begin(), condition.end(), ' '), condition.end());

        char var1 = condition[condition.find('>')-1]; //first variable being compared
        char var2 = condition[condition.find('>')+1]; //second variable being compared

        //check if they are variables or integers
        bool compare; //temporary boolean trigger initialized to false

        //two integers
        if(IsOperand(var1) && IsOperand(var2))
            compare = (var1) > (var2);

        //integer and variable
        else if(IsOperand(var1) && IsVariable(var2)) {
            //find value of var2 and compare to var1
            for(int i = 0; i != var.size(); i++) {
                if(var2 == var[i])
                    compare = var1 > res[i];
            }
        }
        //variable and integer
        else if(IsVariable(var1) && IsOperand(var2)) {
            //find value of var2 and compare to var1
            for(int i = 0; i != var.size(); i++) {
                if(var1 == var[i])
                    compare = res[i] > var2;
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
            compare = int1 > int2;
        }
        //if cannot read then error
        else
            cout << "unexpected error" << endl;

        switch(compare) {
            case 1:
                IfBlock(if_ins);
                break;
            case 0:
                ElseBlock();
                break;
            default:
                break;
        }
    }
    //if no comparator terminate
    else {
        cout << "Error: no comparator" << endl;
        exit(1);
    }

}

void IfBlock(vector<string>& if_ins) {
    //if statement block container variables
    vector<char> if_var; //if statement variables
    vector<int> if_res; //if statement results
    char remove_ch[3] = {'(', ')', '"'}; //array of characters to remove
    int i = 0; //iterator variables to read instructions

    //loop through instructions and read by line
    while(i != if_ins.size()) {
        string instruction = if_ins[i]; //temporary container for instruction line

        //if print then clean the contents and print value in ""
        if(instruction.find("print") != string::npos)
            print(instruction, if_var, if_res, remove_ch);

        //else if its a variable assignment then evaluate and store
        else if(instruction.find("=") != string::npos)
            parse(instruction, if_var, if_res);

        i++; //increments through vector
    }
}

void ElseBlock() {
    /* else block instructions */
}

#endif // IF_STATEMENTS_H_INCLUDED
