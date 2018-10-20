#ifndef EXPRESSIONS_H_INCLUDED
#define EXPRESSIONS_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include "InfixToPostfix.h"

using namespace std;

/* simple postfix calculator */

int PerformOperation(int opd1, int opd2, char op) {

    int res = 0; //temporary result

    //determine with operation to perform
    switch(op) {
        case '+':
            res = opd2 + opd1;
            break;
        case '-':
            res = opd2 - opd1;
            break;
        case '*':
            res = opd2 * opd1;
            break;
        case '/':
            res = opd2 / opd1;
            break;
        default:
            break;
    }

    return res;
}

int PostfixCalculator(string exp, vector<char> var, vector<int> res) {

    //result variable to return
    int result = 0;

    //create stack to push objects
    stack<int> s;

    if(!s.empty()) {
        cerr << "error stack overflow" << endl;
        return -1;
    }

    //if the length of the expression is 1 then append to result
    //to push to result container
    if(exp.length() == 1) {
        result = exp[0] - '0';
        s.push(result);
        return s.top();
    }

    //while going through the expression push numbers to stack and
    //when you read operators pop two operands from stack
    for(int i = 0; i != exp.length(); i++) {

        //if operand push to stack
        if(IsOperand(exp[i])) {

            int operand = exp[i] - '0'; //operand container

            s.push(operand); //push to stack

            /* Need to add function for long integers */
        }
        //if a variable search for its results in container if it exists
        else if(IsVariable(exp[i])) {

            bool exists = false; //temporary bool

            //if true then search variable container
            for(int j = 0; j != var.size(); j++) {
                if(exp[i] == var[j]) {
                    int operand = res[j];
                    exists = true;
                    s.push(operand);
                    break;
                }
            }

            if(exists == false) {
                cerr << "Error: [" << exp[i] << "] does not exist in container." << endl;
                exit(1);
            }

        }
        //if operator pop two values from stack and operate on them
        else if(IsOperator(exp[i])) {

            int operand1 = s.top(); s.pop(); //top element becomes operand 1 and pop from stack
            int operand2 = s.top(); s.pop(); //top element becomes operand 2 and pop from stack

            result = PerformOperation(operand1, operand2, exp[i]); //performs the op and returns result
            s.push(result); //push back to stack to continue operating and find final result
        }
        //if expression is a function then perform function and append to result
        //else ignore
        else { continue; }

    }

    return s.top(); //end
}

//this funcition will evaluate the postfix expression
void evaluate(string expression, vector<char> var, vector<int>& res) {

    //store the postfix expression
    string postfix = InfixToPostfix(expression);

    //store postfix results in results container
    int result = PostfixCalculator(postfix, var, res);
    res.push_back(result);

}

void parse(string line, vector<char>& var, vector<int>& res) {
    //parse the line to variable and expression line
    string var_line = line.substr(0, line.find('='));
    string exp_line = line.substr(line.find('='), line.size()-1);

    //clean the lines
    var_line.erase(remove(var_line.begin(), var_line.end(), ' '), var_line.end()); //removes blanks from variable
    exp_line.erase(remove(exp_line.begin(), exp_line.end(), ' '), exp_line.end()); //removes blanks from expression
    exp_line.erase(remove(exp_line.begin(), exp_line.end(), '='), exp_line.end()); //removes the '=' symbol

    //store the values in appropriate containers
    char arr[var_line.size()]; //temporary char array for conversion
    strcpy(arr, var_line.c_str()); //string copy to temporary char array
    var.push_back(arr[0]); //push the characters to variables container

    //evaluate expression using postfix notation
    evaluate(exp_line, var, res);

}

#endif // EXPRESSIONS_H_INCLUDED
