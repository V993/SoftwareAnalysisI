#ifndef CASHREGISTER H
#define CASHREGISTER_H

class CashRegister {
public: 
    void clear();
    void add_item(double price);
    void add_items(int qnt, double prc);
    double get_total() const;
    int get_count() const;
    CashRegister(); //constructor
private:
    int item_count;
    double total_price;
};

void display(CashRegister reg)
{
    cout << "Item " << reg.get_count() << ": $"
         << fixed << setprecision(2)
         << reg.get_total() << endl;
}

#endif