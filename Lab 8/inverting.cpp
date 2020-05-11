#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

int invert(int num);

int main()
{
    int num1 = 0;
    int num2 = 100;
    int num3 = 255;
    int num4 = 254;

    int inverted = invert(num1);
    cout << num1 << " " << inverted << endl;

    int inverted2 = invert(num2);
    cout << num2 << " " << inverted2 << endl;

    int inverted3 = invert(num3);
    cout << num3 << " " << inverted3 << endl;

    int inverted4 = invert(num4);
    cout << num4 << " " << inverted4 << endl;

}

int invert(int num)
{
    int numMod = num - 255;
    int num2  = abs(numMod);

    return(num2);
}