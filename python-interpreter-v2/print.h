#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED

#include <iostream>
#include <string>
#include <string.h>
#include <vector>

void print(string ins, vector<string> var, vector<int> val) {
    //remove any uneccessary characters
    vector<char> rm = { '(', ')', '"'};

    //parse the line
    string new_line = ins.substr(ins.find('('), ins.find(')'));

    //clean the line
    for(int i = 0; i < rm.size(); i++)
        new_line.erase(remove(new_line.begin(), new_line.end(), rm[i]), new_line.end());

    //check if the single variable call is in the containers already
    bool found = false;
    int pos = 0;
    for(int j = 0; j < var.size(); j++) {
        if(new_line == var[j]) {
            found = true;
            pos = j;
            break;
        }
    }

    if(new_line.find(',') != string::npos) {
        //parse this line now using the ',' delimeter
        string print_line = new_line.substr(0, new_line.find(','));
        string var_line = new_line.substr(new_line.find(',')+1, new_line.size()-1);
        var_line.erase(remove(var_line.begin(), var_line.end(), ' '), var_line.end());

        bool found = false;
        int pos = -1;
        for(int n = 0; n != var.size(); n++) {
            if(var[n] == var_line) {
                found = true;
                pos = n;
                break;
            }
        }

        //error checking
        if(pos == -1) {
            cerr << "unexpected error" << endl;
            return;
        }

        cout << print_line << val[pos] << endl;

    }
    else if(found == true) {
        cout << val[pos] << endl;
    }
    else
        cout << new_line << endl;
}

#endif // PRINT_H_INCLUDED
