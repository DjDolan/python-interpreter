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
#include "if_statements.h"
#include "functions.h"

using namespace std;

int main(int argc, char* argv[]) {

    //variables for manipulation of data
    ifstream file_in; //to read in the file
    string line; //line for reading python instructions
    char remove_ch[3] = {'(', ')', '"'}; //array of characters to remove
    bool inHere = false; //bool to check multiple containers

    //containers for data manipulation
    vector<char> variables; //stores the variables from the expression
    vector<int> results; //stores the evaluated results of the expression
    vector<string> file_copy; //stores a copy of instructions for manipulation
    vector<string> if_instructions; //stores the lines where it is part of the if statement
    vector<string> else_instructions; //stores the lines where it is part of the else statement
    vector<string> functions; //stores the function name and function id
    vector<string> functions_instructions; //stores the instructions for a function
    vector<int> functions_results; //stores the functions evaluated result

    file_in.open(argv[1]); //opens the next argument in the command line

    //loop to read the instructions line by line
    while(getline(file_in, line)) {
        file_copy.push_back(line);

        //if # then ignore
        if(line.find("#") != string::npos)
            continue;

        //if print then clean the contents and print value in ""
        if(line.find("print") != string::npos) {
            //if there are three blank spaces in the front then part
            //of if statement or function block
            if(isspace(line[2]) && !isspace(line[3])) {
                //check previous lines if its if or function
                for(int i = file_copy.size()-1; i != 0; i--) {
                    //if find def then push to functions container
                    if(file_copy[i].find("def") != string::npos) {
                        functions_instructions.push_back(line);
                        break;
                    }
                    //else if find if then push to if_instructions container
                    else if(file_copy[i].find("if") != string::npos) {
                        if_instructions.push_back(line);
                        break;
                    }
                }
            }
            //else perform regular instructions
            else
                print(line, variables, results, remove_ch, inHere);
        }
        //else if its a variable assignment then evaluate and store
        else if(line.find("=") != string::npos) {
            //if there are three blank spaces in the front then part
            //of if statement or function block
            if(isspace(line[2]) && !isspace(line[3])) {
                //check previous lines if its if or function
                for(int i = file_copy.size()-1; i != 0; i--) {
                    //if find def then push to functions container
                    if(file_copy[i].find("def") != string::npos) {
                        cout << line << endl;
                        cout << file_copy[i] << endl;
                        functions_instructions.push_back(line);
                        break;
                    }
                    //else if find if then push to if_instructions container
                    else if(file_copy[i].find("if") != string::npos) {
                        cout << line << endl;
                        cout << file_copy[i] << endl;
                        if_instructions.push_back(line);
                        break;
                    }
                }
            }
            //else perform regular instructions
            else
                parse(line, variables, results);
        }
        //else if its an if statement then read the whole if statement
        else if(line.find("if") != string::npos) {
            if_instructions.push_back(line);
        }
        //else if its a function push to functions container
        else if(line.find("def") != string::npos) {
            functions.push_back(line);
        }

    }

    file_in.close(); //closes the instruction file

    //catch all the if statements and anything that needs to be
    //evaluated here so nothing gets left out from output
    if(!if_instructions.empty())
        IfStatement(if_instructions, variables, results);

    //Evaluate functions and store results for output
    if(!functions_instructions.empty())
        FunctionScanner(functions, functions_instructions, functions_results, variables, results);

    //deallocate all dynamic containers
    variables.clear();
    results.clear();
    functions.clear();
    functions_results.clear();

    return 0; //end of program
}

