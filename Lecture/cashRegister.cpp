#include <iostream>
#include <iomanip>
#include "cashregister.h"
using namespace std;

    void clear();

    void add_items(int qnt, double prc);

    void add_item(double price);

    double get_total();

    int get_count();

//constructor
CashRegister::CashRegister()
{
    item_count = 0;
    total_price = 0;
}

int main()
{
    CashRegister register1;
    CashRegister register2;

    register1.clear();
    register1.add_item(1.95);
    display(register1);
    register1.add_item(0.95);
    display(register1);
    register1.add_item(2.50);
    display(register1);
    return 0;
}

void CashRegister::clear()
{
    item_count = 0;
    total_price = 0;
}

void CashRegister::add_items(int qnt, double prc)
{
    for (int i = 0; i <= qnt; i++)
    {
        add_item(prc);
    }
}

void CashRegister::add_item(double price)
{
    item_count++;
    total_price += price;
}

double CashRegister::get_total() const
{
    return total_price;
}

int CashRegister::get_count() const
{
    return item_count;
}