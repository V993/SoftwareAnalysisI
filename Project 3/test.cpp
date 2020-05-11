#include <iostream>
using namespace std;

int main()
{
    int row = 5, col = 5;
    int a = 0;
    while (a < 10)
    {
        for (int i = row - a; i < row + a+1; i++)
        {
            for(int j = col - a; j < col + a+1; j++)
            {
                if ((i == row) && (j == col))
                {
                    cout << "o ";
                }
                else{
                cout << "x ";
                }
            }
            cout << endl;
        }
        a++;
    }
}
