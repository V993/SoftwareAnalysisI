/*
Author: Leonardo Matone
Instructor: Katherine Howitt

Assignment: Lab12A

Goal: create a function to make a vector
*/

#include <iostream> 
#include <vector>
using namespace std; 

vector<int> makeVector(int n);

int main()
{
    int n;
    cout << "enter a vector size: ";
    cin >> n; //get size

    vector<int> nVector = makeVector(n); //make vector

    for (int i = 0; i <n; i++)
    {
        cout << nVector[i] << endl; //cout vector
    }

}

vector<int> makeVector(int n)
{
    //establish new vector
    vector<int> newVector(n);

    for (int i = 0; i < n; i++)
    {
        newVector[i] = i; //make each element in newVector = 0 -> n - 1
    }
    return newVector; //return vector
}

