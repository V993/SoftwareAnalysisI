/*
Author: Leonardo Matone
Instructor: Katherine Howitt

Assignment: Lab 12C

Goal: merge vectors

*/

#include <iostream>
#include <vector>

using namespace std;


void gogeta(vector<int> &goku, vector<int> &vegeta);

int main()
{
    //establishing both vectors
    vector<int> goku = {1, 2, 3};
    vector<int> vegeta = {4, 5};

    //appending and deleting
    gogeta(goku, vegeta);

    //cout the fused vector
    for (int i = 0; i < goku.size(); i++)
    {
        cout << goku[i] << " ";
    }
    cout << endl;
    //test if the second vector is empty
    if (vegeta.empty())
    {
        cout << "Second vector empty." << endl;
    }

}

void gogeta(vector<int> &goku, vector<int> &vegeta)
{
    //establish both vector lengths
    int lenGoku = goku.size(); //establishing the size of vector 1
    int lenVegeta = vegeta.size(); //establishing the size of vector 2

    //add the elements of vector 2 to vector 1
    for (int i = 0; i < lenVegeta; i++) //starting at the last element of goku we're going to add each element of vegeta
    {
        goku.push_back(vegeta[i]);
    }
    //pop back the vector elements of vector 2
    for (int i = 0; i < lenVegeta; i++)
    {
        vegeta.pop_back();
    }
}