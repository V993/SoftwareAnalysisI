/*
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: Quiz 11

Goal:

*/

#include <iostream>

using namespace std;

class Money{
public:
    int dollars;
    int cents;
};

Money add_money(Money a, Money b);

int main()
{
    Money a = {4, 80};
    Money b = {3, 90};
    Money sum = add_money(a, b);

    cout << "Sum is: " << sum.dollars << " dollars and " << sum.cents << " cents." << endl;
}

Money add_money(Money a, Money b)
{
    int dollars1 = a.dollars;
    int dollars2 = b.dollars;

    int cents1 = a.cents;
    int cents2 = b.cents;

    int newDollars = dollars1 + dollars2;

    int newCents = cents1 + cents2;

    if (newCents >= 100)
    {
        newCents -= 100;
        newDollars += 1;
    }
    Money sum = {newDollars, newCents};

    return sum;
}