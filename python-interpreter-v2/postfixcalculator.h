#ifndef POSTFIXCALCULATOR_H_INCLUDED
#define POSTFIXCALCULATOR_H_INCLUDED

#include <stdio.h>
#include <stack>
#include "parser.h"

using namespace std;

bool IsNumber(char c) {
    if(c >= '0' && c <= '9') return true;
    else return false;
}

bool IsVariable(char c) {
    if(c >= 'a' && c <= 'z') return true;
    else return false;
}

bool IsOperator(char c) {
    if(c == '+'
    || c == '-'
    || c == '*'
    || c == '/') return true;
    else return false;
}

bool IsDelimeter(char c) {
    if(c == ' '
    || c == '\n'
    || c == '\0') return true;
    else return false;
}

int operation(char, int, int);

int PostfixCalculate(string postfix, vector<string>& var, vector<int>& val) {
    int result = 0; //return this
    stack<int> s; //stack for manipulation

    for(int i = 0; i != postfix.length(); i++) {
        //if a digit then push to stack
        if(IsNumber(postfix[i])) {
            int operand = 0;

            //check if its a long integer
			while(i < postfix.length() && IsNumber(postfix[i])) {
				operand = (operand * 10) + (postfix[i] - '0');
				i++;
			}
            i--;
			s.push(operand);
        }
        //if operator then pop two ints and evaluate
        else if(IsOperator(postfix[i])) {
            int op1 = s.top(); s.pop();
            int op2 = s.top(); s.pop();

            result = operation(postfix[i], op1, op2);

            s.push(result);
        }
    }

    while(!s.empty()) {
        result = s.top();
        s.pop();
    }

    return result;
}

int operation(char op, int op1, int op2) {
    int result = 0;

    switch(op) {
        case '+':
            result = op2 + op1;
            break;
        case '-':
            result = op2 - op1;
            break;
        case '*':
            result = op2 * op1;
            break;
        case '/':
            result = op2 / op1;
            break;
        default:
            break;
    }

    return result;
}

#endif // POSTFIXCALCULATOR_H_INCLUDED
