/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: HW E620

Goal: 
*/

#include <iostream> 
#include <vector>
using namespace std;

//establishing a function append() which takes two vectors as input and ouputs the two as one organized vector. 
vector<int> append(vector<int> a, vector<int> b);
vector<int> merge_sorted(vector<int> a, vector<int> b);

int main()
{
    //vector a contains 1, 4, 9, and 16.
    vector<int> a;
    a = {1, 4, 9, 16};
    //vector b contains 9, 7, 4, 9, and 11. 
    vector<int> b;
    b = {9, 7, 4, 9, 11};

    vector<int> appended = append(a,b);
    vector<int> sorted;

        sorted = merge_sorted(a, b);    

    for (int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i] << " ";
    }
    cout << endl;
}

vector<int> merge_sorted(vector<int> a, vector<int> b)
{
    vector<int> merged;

    int i = 0;
    int j = 0;

    for (i < a.size(); j < b.size();)
    {
        if(a[i] <= b[j])
        {
            merged.push_back(a[i++]);
            // i++;
        }
        else
        {
            merged.push_back(b[j++]);
            // j++;
        }
    }

    while(i < a.size())
    {
        merged.push_back(a[i++]);
    }
    while(j < b.size())
    {
        merged.push_back(b[j++]);
    }

    return merged;
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