#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include "parser.h"
#include "print.h"

using namespace std;

int main(int argc, char* argv[]) {

    ifstream file_in;
    string line;
    vector<string> instructions;
    vector<string> variables;
    vector<int> values;

    file_in.open(argv[1]);

    while(getline(file_in, line))
        instructions.push_back(line);

    file_in.close();

    for(int i = 0; i != instructions.size(); i++) {

        //if 'print' then its a print statement
        if(instructions[i].find("print") != string::npos) {
            //check for variable calls and function calls
            print(instructions[i], variables, values);
        }

        //if contains "#" or line is empty then ignore
        else if(instructions[i].find("#") != string::npos) { continue; }

        //if '=' then its an assignment operator
        else if(instructions[i].find("=") != string::npos) {
            //clean and parse the line
            parser(instructions[i], variables, values);
        }

    }

    return 0;
}
