#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <stack>
#include "postfixcalculator.h"

using namespace std;

int HasHigherPrecedence(char operator1, char operator2);

int IsRightAssociative(char op);

int GetOperatorWeight(char op);

void evaluateExp(string, vector<string>&, vector<int>&);

void parser(string exp, vector<string>& variables, vector<int>& values) {
    string ins = exp; //temporary container for manipulation

    ins.erase(remove(ins.begin(), ins.end(), ' '), ins.end()); //cleans line

    //parses the instructions
    string var_line = ins.substr(0, ins.find("="));
    string val_line = ins.substr(ins.find("=")+1, ins.size()-1);

    variables.push_back(var_line); //stores into variable container

    bool isExp = false; //bool to check if expression

    //loop to check if expression
    //must contain an operator
    for(int i = 0; i != val_line.length(); i++) {
        if(IsOperator(val_line[i])) {
           isExp = true;
           break;
        }
        else continue;
    }

    if(isExp == true) {
        //if it is an expression evaluate expression
        evaluateExp(val_line, variables, values);
    }
    else {
        //if not an expression and just a string of numbers
        //then cast to int and push to value container
        values.push_back(stoi(val_line));
    }

}

//function to evaluate the expression
void evaluateExp(string exp, vector<string>& var, vector<int>& val) {

    //stack to evaluate the expression
    stack<char> s;

    //temporary variables
    string postfix;
    string variable;

    for(int i = 0; i != exp.length(); i++) {
        if(IsNumber(exp[i]) || IsVariable(exp[i])) {
            postfix += exp[i];
        }
        else if(IsOperator(exp[i])) {
            //use '@' as separator
            postfix += '@';
            while(!s.empty() && HasHigherPrecedence(s.top(), exp[i])) {
				postfix += s.top();
				s.pop();
			}
			s.push(exp[i]);
        }
    }

    while(!s.empty()) {
        postfix += s.top(); s.pop();
    }

    //PostfixCalculate(postfix, var, val);
    val.push_back(PostfixCalculate(postfix, var, val));

}

// Function to verify whether an operator is right associative or not.
int IsRightAssociative(char op) {
	if(op == '$') return true;
	return false;
}

// Function to perform an operation and return output.
int HasHigherPrecedence(char op1, char op2) {
	int op1Weight = GetOperatorWeight(op1);
	int op2Weight = GetOperatorWeight(op2);

	// If operators have equal precedence, return true if they are left associative.
	// return false, if right associative.
	// if operator is left-associative, left one should be given priority.
	if(op1Weight == op2Weight) {
		if(IsRightAssociative(op1)) return false;
		else return true;
	}
	return op1Weight > op2Weight ?  true: false;
}

// Function to get weight of an operator. An operator with higher weight will have higher precedence.
int GetOperatorWeight(char op) {
	int weight = -1;
	switch(op) {
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
		weight = 2;
		break;
	case '$':
		weight = 3;
		break;
	}
	return weight;
}

#endif // PARSER_H_INCLUDED
