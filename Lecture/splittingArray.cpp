#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//creates an array of arrays in a triangular array, an increasing number of values
	//as you go down the initial array.
	int* counts[10];
	for (int i = 0; i < 10; i++)
	{
		counts[i] = new int[i + 1];
        for (int j = 0; j <= i; j++)
        {
            counts[i][j] = 0;
        }
	}
    const int RUNS = 12; //simulate 7 balls
    for (int run = 0; run < RUNS; run++)
    {
        counts[0][0]++;
        int j = 0;
        for (int i = 1; i < 10; i++)
        {
            if (rand() % 2)
            {
                j++;
            }
            counts[i][j]++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= i; i++)
        {
            cout << setw(4) << counts[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < 10; i++)
    {
        delete[] counts[i];
        //counts[i] = nullptr;
    }
    return 0;
}
