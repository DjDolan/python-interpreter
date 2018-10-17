#ifndef EXPRESSIONS_H_INCLUDED
#define EXPRESSIONS_H_INCLUDED

#include <stdio.h>
#include "InfixToPostfix.h"
#include <string>

using namespace std;

//this function will evaluate the lines that have a variable assignment
void eval_exp(string line, vector<char>& var, vector<int>& res) {

    char arr[line.size() + 1];

    //if the first character in the line is between
    //'a' and 'z' it will store it in the variables
    //container (vector<char> variables)
    if(line[0] >= 'a' || line[0] <= 'z') {
        var.push_back(line[0]);
    }

    //remove the blank spaces in the expression for
    //easier computation
    for(int i = 0; i != line.size(); i++) {
        line.erase(remove(line.begin(), line.end(), ' '), line.end());
    }

    //remove the variable and assignment for postfix
    //evaluation and store in containers
    line.erase(line.begin(), line.begin() + 2);

    //change to char array and evaluate
    for(int i = 0; i != line.size(); i++) {
        arr[i] = line[i];
    }

    //store result into result container
    int result = evaluate(arr);
    res.push_back(result);

}

#endif // EXPRESSIONS_H_INCLUDED
