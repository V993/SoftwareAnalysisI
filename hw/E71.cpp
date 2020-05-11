/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: HW E7.1

function void sort2 receives two pointers and sorts the values to which they point.

*/


#include <iostream>
using namespace std;

void sort2(double* p, double* q);

int main()
{
    double x, y;
    
    cout << "Enter x: ";
    cin >> x;
    cout << endl;

    cout << "Enter y: ";
    cin >> y;
    cout << endl;
    
    double* p = &x;
    double* q = &y;

    cout << *p;
    cout << " ";
    cout << *q;
    cout << endl;
    
    sort2(p, q);

    cout << *p;
    cout << " ";
    cout << *q;
    cout << endl;

}

void sort2(double* p, double* q)
{
    if (*p > *q)
    {    
        double tmp = *p; 
        *p = *q;
        *q = tmp;
    }
}