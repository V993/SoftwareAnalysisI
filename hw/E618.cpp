/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: HW E618

Goal: make a vector that appends one vector after another.
*/

#include <iostream> 
#include <vector>

using namespace std;

//establishing a function append() which takes two vectors as input and ouputs the two as one organized vector. 
vector<int> append(vector<int> a, vector<int> b);

int main()
{
    //vector a contains 1, 4, 9, and 16.
    vector<int> a;
    a = {1, 4, 9, 16};
    //vector b contains 9, 7, 4, 9, and 11. 
    vector<int> b;
    b = {9, 7, 4, 9, 11};

    vector<int> appended = append(a, b);

    for (int i = 0; i < appended.size(); i++)
    {
        cout << appended[i] << " ";
    }
    cout << endl;
}

vector<int> append(vector<int> a, vector<int> b)
{
    vector<int> appended;

    for (int i = 0; i < a.size(); i++)
    {
        int iter_num_a = a[i];
        appended.push_back(iter_num_a);
    }
    for (int i = 0; i < b.size(); i++)
    {
        int iter_num_b = b[i];
        appended.push_back(iter_num_b);
    }
    return appended;
}