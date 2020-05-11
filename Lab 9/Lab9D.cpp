/*
Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: LAb 9D

Task: Fix the program so that it does not crash your computer:

*/

#include <iostream>

using namespace std;

string * createAPoemDynamically()
{
    string *p = new string; //declare a pointer to string which will store the adderss
                            //dynamically allocate memory for a poem string and store its address in the pointer
                            //this DYNAMICALLY allocated memory will remain persistently in the computer memory 
                            //throughout the program execution. 

    *p = "Roses are red, violets are blue"; //define the actual poem
    return p; //return the address where the poem is
}

int main()
{
    while(true)
    {
        string * p;
        p = createAPoemDynamically(); //the memory at the address p still has the poem

        //cout << *p << endl;           //dereference operator allows us to access what is still stored in 
                                      //address p.
        delete p;                     //we now need to DEALLOCATE the memory address of p, releasing this memory
                                      //back to the system.
    }
}