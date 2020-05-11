/*
Author: Leonardo Matone
Instructor: Katherine Howitt

Task: Quiz 12

Goal:v

*/

#include <iostream>

using namespace std;

class Customer{
private: 
    string name;
    string unique_id;
public:
    Customer();
    Customer(string name_input, string unique_id_input);
    string get_name();
    string get_unique_id();
    void set_name(string input);
    void set_unique_id(string input_unique_id);
};

Customer::Customer()
{
    name = "";
    unique_id = "";
}

Customer::Customer(string name_input, string unique_id_input)
{
    name = name_input;
    unique_id = unique_id_input;
}

string Customer::get_name()
{
    return name;
}

string Customer::get_unique_id()
{
    return unique_id;
}

void Customer::set_name(string input)
{
    name = input;
}

void Customer::set_unique_id(string input_unique_id)
{
    unique_id = input_unique_id;
}

int main()
{
    Customer();
    Customer newGuy;
    string input;
    cout << "Enter a name: ";
    cin >> input;

    newGuy.set_name(input);

    string ID;
    cout << "Enter unique ID: ";
    cin >> ID;

    newGuy.set_unique_id(ID);

    cout << "New customer: " << newGuy.get_name() << " ID: " << newGuy.get_unique_id() << endl;
}