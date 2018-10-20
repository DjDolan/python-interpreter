Donald Aguinaldo - 1455130 - cosc2954
Duncan Moore - 1465434

To compile you simply run:
g++ main.cpp -o mypython

and then:
./mypython <inputfile>.py

Our program cannot run the following:
- single operand variable assignments (x = 2)
- long integer variable assignments (x = 1234)
- function reading
- function assigning (x = f())
- variable operation (x = y + z)

The way we did it was simply reading each line from the text file and manipulatin
g it according to what was read. For example, we can read print() statements and
used the string class to clean the line and parse it into the correct output. As
for storing our variables with used vectors for an indefinite amount of variables
used. Although we did not get some of the test cases working we were able to do avariable association by using the positions of the variables in the vector to be linked together. For example, the position of variable 'z' in the variables vector is 1. The same position, 1, is found in the results vector and contains the val
ue of 'z' which could be any integer.

