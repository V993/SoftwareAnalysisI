#include <iostream>

double scores[5] = {10, 4, 21, 30, 4}

double sum(scores[], 5); //scores is the array, 5 is the size 

int main()
{
    double summation = sum(scores[], 5);
    cout << "Summation is: " << summation << endl;
}

double sum(scores[], 5)
{
    int total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += scores[i];
    }
    return total;
}