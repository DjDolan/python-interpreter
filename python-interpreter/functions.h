#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <iostream>
#include <vector>
#include "expressions.h"
#include "print.h"

using namespace std;

//function to scan the function and return an output
void FunctionScanner(vector<string> func, vector<string>& func_ins, vector<int>& func_res, vector<char> var, vector<int> res) {
    char remove_ch[3] = {'(', ')', '"'}; //array of characters to remove
    int i = 0; //iterator variables to read instructions

    //loop through the instructions and interpret
    while(i != func_ins.size()) {
        //clean and parse the instructions
        string instruction = func_ins[i];

        //if print then clean the contents and print value in ""
        if(instruction.find("print") != string::npos)
            print(instruction, var, res, remove_ch);

        //else if assignment then clean content and parse
        else if(instruction.find("=") != string::npos)
            parse(instruction, var, res);

        i++; //increment through instructions
    }

    func_ins.clear();
}

#endif // FUNCTIONS_H_INCLUDED
