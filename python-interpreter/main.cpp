/*
    Author(s): Donald Aguinaldo | 1455130
               Duncan Moore     |

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
#include <algorithm>
#include <stack>
#include "InfixToPostfix.h"

using namespace std;

void print_statements(string line, vector<char>, vector<string>&);

int main(int argc, char* argv[]) {

    //variable containers
    ifstream in_file;
    string line;
    vector<char> char_remove = { '"', '(', ')', ' ' };
    vector<char> operators = { '+', '-', '*', '/', '=' };
    vector<char> math_exp;
    vector<string> strings;
    vector<char> variables;

    //open file to read lines as instructions
    in_file.open(argv[1]);

    //loop through lines and perform different functions
    while(getline(in_file, line)) {

        //catches comments and skips line
        if(line.find("#") != string::npos)
            continue;

        //if its a print line then we send to print function
        else if(line.find("print") != string::npos) {

            //iterate through container for characters to remove for print function
            print_statements(line, char_remove, strings);
        }

        //if its a def use a function to read the function
        else if(line.find("=") != string::npos) {
            variables.push_back(line[0]);
            for(int i = 0; i < char_remove.size(); i++)
                line.erase(remove(line.begin(), line.end(), char_remove[i]), line.end());
            line.erase(line.begin(), line.begin() + 2);

            string result = InfixToPostfix(line);
            cout << result << endl;
        }

        else continue;
    }

    //close file once done
    in_file.close();

    //deallocate and dynamic variables
//    for(auto i = strings.begin(); i != strings.end(); ++i)
//        cout << *i << endl;
//
    for(auto j = math_exp.begin(); j != math_exp.end(); ++j)
        cout << *j << " ";
    cout << endl;

    return 0;
}

//this function will take in a text line and remove everythin that
//needs to be removed so that there will be nothing but the output
void print_statements(string line, vector<char> ch_rm, vector<string>& s) {

    //loop through and search for characters to remove
    //will implement if statements to read variables and
    //function reading as an output
    for(int i = 0; i != ch_rm.size(); i++)
        line.erase(remove(line.begin(), line.end(), ch_rm[i]), line.end()); //removes (, ), and "
    line.erase(line.begin(), line.begin() + 5); //removes 'print'

    //push to list of strings
    s.push_back(line);
}
