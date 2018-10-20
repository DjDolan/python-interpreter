#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include "expressions.h"

using namespace std;

void print(string line, vector<char> var, vector<int> res, char* rm_ch) {

        //parse the line
        string new_line = line.substr(line.find('('), line.find(')'));

        //clean the line
        for(int i = 0; i < sizeof(rm_ch)/sizeof(rm_ch[0]); i++)
            new_line.erase(remove(new_line.begin(), new_line.end(), rm_ch[i]), new_line.end());

        //case where there are variables called with strings attached
        if(new_line.find(',') != string::npos) {

            //parse this line now using the ',' delimeter
            string print_line = new_line.substr(0, new_line.find(','));
            string var_line = new_line.substr(new_line.find(',')+1, new_line.size()-1);
            var_line.erase(remove(var_line.begin(), var_line.end(), ' '), var_line.end());


            //copy variable in the string to char array
            char arr[var_line.size()];
            strcpy(arr, var_line.c_str());

            //check if the variable is in the container
            int pos = -1; //temporary position variable
            for(int i = 0; i != var.size(); i++) {
                //if yes, then find corresponding result in result container
                if(arr[0] == var[i])
                    pos = i;
            }
            //error checking
            if(pos == -1) {
                cerr << "unexpected error" << endl;
                return;
            }

            cout << print_line << res[pos] << endl;

        }
        //case where only the variable is called
        else if(new_line.length() == 1) {

            //convert the string to char array for comparison
            char arr[new_line.length()-1];
            strcpy(arr, new_line.c_str());

            //if its a variable print its value
            if(IsVariable(arr[0])) {
                //check containers if it exists
                for(int k = 0; k != var.size(); k++) {
                    if(arr[0] == var[k])
                        cout << res[k] << endl;
                }
            }
            //if its a number then print it out
            else if(IsOperand(arr[0]))
                cout << arr[0] << endl;
            //else it is not a variable or a number
            else {
                cout << "unexpected error" << endl;
                exit(1);
            }

        }
        //case where only the function is called
        //case where there is no variable called
        else
            cout << new_line << endl;
}

#endif // PRINT_H_INCLUDED
