/*
Author: Leonardo Matone
Instructor: KAtherine Howitt

Assignment: Lab 12B

Goal: Positive vector

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> goodVibes(vector<int> v);

int main()
{
    //establishing vector
    vector<int> numbers = {1, 2, -1, 3, 4, -1, 6};

    //cout original vector for comparison
    cout << "Original: ";
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    //establish positive vector
    vector<int> positive = goodVibes(numbers);

    //cout positive vector
    cout << "Positives: ";
    for (int i = 0; i < positive.size(); i++)
    {
        cout << positive[i] << " ";
    }
    cout << endl;
}

vector<int> goodVibes(vector<int> v)
{   
    //determine size of inputted vector
    int len = v.size();
    vector<int> positive; //establish new vector

    //determine contents
    for (int i = 0; i < len; i++)
    {
        if (v[i] > 0) //if the element in original vector is positive,
        {
            positive.push_back(v[i]); //push back into new vector.
        }
    }
    return positive; //return vector
}