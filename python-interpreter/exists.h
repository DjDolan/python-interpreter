#ifndef EXISTS_H_INCLUDED
#define EXISTS_H_INCLUDED

/* Functions to determine if variables exist in containers already */

//checks variables container and returns true/false
//and gives back position of the variable to find
//the value in the results container with the same
//position
bool inVariables(char var, vector<char> vars, int& pos) {

    for(int i = 0; i != vars.size(); i++) {
        //if found then return true return position
        if(var == vars[i]) {
            //cout << "Item exists in container!" << endl;
            pos = i;
            return true;
        }
        else {
            //cout << "Item does not exist in container." << endl;
            return false;
        }
    }

}

#endif // EXISTS_H_INCLUDED
