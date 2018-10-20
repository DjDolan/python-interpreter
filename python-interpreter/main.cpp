/*
    Author(s): Donald Aguinaldo | 1455130
               Duncan Moore     | 1465434

    Title: My Python Interpreter

    This program will simulate a python interpreter
    by comprehending the syntax that is created and
    displays what should be properly displayed in
    the console.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include "expressions.h"
#include "print.h"

using namespace std;

int main(int argc, char* argv[]) {

    //variables for manipulation of data
    ifstream file_in; //to read in the file
    string line; //line for reading python instructions
    char remove_ch[3] = {'(', ')', '"'}; //array of characters to remove

    //containers for data manipulation
    vector<char> variables; //stores the variables from the expression
    vector<int> results; //stores the evaluated results of the expression
    vector<char> expressions; //stores the characters of the expression
    vector<string> functions; //stores the function name and function id
    vector<int> functions_results; //stores the functions evaluated result

    file_in.open(argv[1]); //opens the next argument in the command line

    //loop to read the instructions line by line
    while(getline(file_in, line)) {

        //if # then ignore
        if(line.find("#") != string::npos)
            continue;

        //if print then clean the contents and print value in ""
        if(line.find("print") != string::npos)
            print(line, variables, results, remove_ch);

        //else if its a variable assignment then evaluate and store
        else if(line.find("=") != string::npos)
            parse(line, variables, results);

    }

    file_in.close(); //closes the instruction file

    //deallocate all dynamic containers
    variables.clear();
    results.clear();
    expressions.clear();
    functions.clear();
    functions_results.clear();

    return 0; //end of program
}

