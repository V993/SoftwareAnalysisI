/*
Author: Leonardo Matone
Instructor: Katherine Howitt

Assignment: Lab 12D

Goal: sum vector elements

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2);

int main()
{
    //establishing both vectors
    vector<int> v1 = {1, 2, 3};
    vector<int> v2 = {4, 5};

    //summing elements pairwise
    vector<int> sum = sumPairWise(v1, v2);

    //cout the resulting summed vector
    for (int i = 0; i < sum.size(); i++)
    {
        cout << sum[i] << " ";
    }
    cout << endl;
}

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2)
{
    //establish bpth sizes
    int len1 = v1.size();
    int len2 = v2.size();
    int diff, len;
    vector<int> sum;

    //conditionals for different vectors 
    if (len1 > len2){ //if the first vector is larger
        diff = len1 - len2; //determine the difference
        for (int i = 0; i < diff; i++) 
        {
            v2.push_back(0); //add a zero element into the smaller vector to match the size
        }
        len = len1; //the length we want for our new vectoris that of the larger vector
    }
    else{
        diff = len2 - len1; //vice versa for the second case
        for (int i = 0; i < diff; i++)
        {
            v1.push_back(0);
        }
        len = len2;
    }


    for (int i = 0; i < len; i++) //cycle through the length of the larger vector
    {
        sum.push_back(v1[i] + v2[i]); //sum vector is pushed back the sum of both elements in index i. empty slots are now zeros, and add fine.
    }

    return sum; //return summation vector
}