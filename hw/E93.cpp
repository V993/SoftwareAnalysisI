/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: HW E9.3

Goal: Simulates a circuit for controlling a hallway light that
has switches at both ends of the hallway. Each switch can be up
or down, and the light can be on or off. Provide member functions:
*/

#include <iostream>
using namespace std;

class Circuit{
public:
    // 0 for down, 1 for up
    int get_first_switch_state();
    int get_second_switch_state();
    // 0 for off, 1 for on
    int get_lamp_state();
    void toggle_first_switch();
    void toggle_second_switch();
    Circuit();
private:
    int switch_state1;
    int switch_state2;
    int lamp_state;
};

Circuit::Circuit()
{
    switch_state1 = 0;
    switch_state1 = 0;
    lamp_state = 0;
}

// 0 for down, 1 for up
int Circuit::get_first_switch_state()
{
    return switch_state1;
}
int Circuit::get_second_switch_state()
{
    return switch_state2;
}
// 0 for off, 1 for on
int Circuit::get_lamp_state()
{
    return lamp_state;
}

void Circuit::toggle_first_switch()
{
    if (switch_state1 == 1)
    {
        switch_state1 = 0;
        if (lamp_state == 1)
        {
            lamp_state = 0;
        }
        else
        {
            lamp_state = 1;
        }
    }
    else 
    {
        switch_state1 = 1;
        if (lamp_state == 1)
        {
            lamp_state = 0;
        }
        else
        {
            lamp_state = 1;
        }
    }
}
void Circuit::toggle_second_switch()
{
   if (switch_state2 == 1)
   {
       switch_state2 = 0;
       if (lamp_state == 1)
       {
           lamp_state = 0;
       }
       else
       {
           lamp_state = 1;
       }
   }
   else{
       switch_state2 = 1;
       if (lamp_state == 1)
       {
           lamp_state = 0;
       }
       else
       { 
           lamp_state = 1;
       }
   }
}

int main()
{
    Circuit light;
    Circuit();
    int switch1 = light.get_first_switch_state();
    cout << switch1 << endl;

    light.toggle_first_switch();
    int testOn = light.get_lamp_state();
    cout << testOn << endl;

    int switch2 = light.get_second_switch_state();
    cout << switch2 << endl;

    testOn = light.get_lamp_state();
    cout << testOn << endl;
}

