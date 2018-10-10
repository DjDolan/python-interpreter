/*
    Author(s): Donald Aguinaldo | 1455130
               Duncan Moore     | 1465434

    Title: My Python Interpreter

    This program will simulate a python interpreter
    by comprehending the syntax that is created and
    displays what should be properly displayed in
    the console
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {

    //variable containers
	int t=0;
	int x=0;
	int y=0;
    string line;
    ifstream in_file;
    vector<char> char_remove = { '"', '(', ')' };

    //open file to read lines as instructions
    in_file.open("python-code.txt");

    //loop through lines and perform different functions
    while(getline(in_file, line)) {

        //catches comments and skips line
        if(line.find("#") != string::npos)
            continue;

        //if its a print line then we send to print function
        else if(line.find("print") != string::npos) {

            //iterate through container for characters to remove for print function
            for(int i = 0; i != char_remove.size(); i++)
                line.erase(remove(line.begin(), line.end(), char_remove[i]), line.end());
                line.erase(line.begin(), line.begin() + 5);

            cout << line << endl;
        }
		else if (line.find(':')) // to incorporate the colon operator
		{
			//if its a def use a function to read the function

			//if its a variable then store in variable container

			//if its an operator then store in operator container

			if (line.find("return")) {
				t = x + y;
				continue;
			}
		}
    }

    //close file once done
    in_file.close();

    //deallocate and dynamic variables

    return 0;
}
