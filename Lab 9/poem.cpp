/*
Author: Leonardo Matone
Course: CSCI-136
Instructor: Katherine Howitt
Assignment: LAb 9D

Task: Fix the program so that it does not crash your computer:

*/

#include <iostream>
using namespace std;

string * createAPoemDynamically() {
    string *p = new string; 
    *p = "Roses are red, violets are blue";
    return p;
}

int main() {
    while(true) {
        string * p;
        p = createAPoemDynamically();
        delete p;
    }
}