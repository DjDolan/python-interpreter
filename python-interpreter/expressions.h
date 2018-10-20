#ifndef EXPRESSIONS_H_INCLUDED
#define EXPRESSIONS_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>
#include "InfixToPostfix.h"

using namespace std;

/* simple postfix calculator */

int performOperation(int opd1, int opd2, char op) {

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

int PostfixCalculator(string exp) {

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
        //if operator pop two values from stack and operate on them
        else if(IsOperator(exp[i])) {
            int operand1 = s.top(); s.pop(); //top element becomes operand 1 and pop from stack
            int operand2 = s.top(); s.pop(); //top element becomes operand 2 and pop from stack

            result = performOperation(operand1, operand2, exp[i]); //performs the op and returns result
            s.push(result); //push back to stack to continue operating and find final result
        }
        //if expression is a function then perform function and append to result
        //else ignore
        else { continue; }

    }

    return s.top(); //end
}

//this funcition will evaluate the postfix expression
void evaluate(string expression) {

    //store the postfix expression
    string postfix = InfixToPostfix(expression);

    //postfix calculations
    cout << PostfixCalculator(postfix) << endl;
}

#endif // EXPRESSIONS_H_INCLUDED
