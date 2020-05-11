/* 
Author: Leonardo Matone
Assignment: Quiz 13

*/

// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> makeVector(int n);

// int main()
// {
//     int n = 5;
//     vector<int> newVector = makeVector(n);
//     for (int i = 0; i < newVector.size(); i++)
//     {
//         cout << newVector[i] << " ";
//     }
//     cout << endl;
// }

// vector<int> makeVector(int n)
// {

// }

#include <iostream> 
#include <vector>
using namespace std; 

vector<int> makeVector(int n);

int main()
{
    int n = 3;
    // cout << "enter a vector size: ";
    // cin >> n; //get size

    vector<int> nVector = makeVector(n); //make vector

    for (int i = 0; i <n; i++)
    {
        cout << nVector[i] << endl; //cout vector
    }

}

vector<int> makeVector(int n)
{
    //establish new vector
    vector<int> newVector;

    for (int i = 0; i < n; i++)
    {
        newVector.push_back(i); //make each element in newVector = 0 -> n - 1
    }
    return newVector; //return vector
}


