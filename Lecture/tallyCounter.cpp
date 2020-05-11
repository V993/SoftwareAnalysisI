#include <iostream> 
using namespace std;

class Counter {
public: //function prototype statements, interface of the class to be used in main()
    void reset();
    void count();
    int get_value() const;
private: //data members. data stored in object.
    int value;
};

void Counter::count()
{
    value++;
}
void Counter::reset()
{
    value = 0;
}
//required so that users can know the count. users are not able to access data members in private.
int Counter::get_value() const
{
    return value;
}

int main() //define and use two Counter objects to test class
{
    Counter tally;
    tally.reset();
    tally.count();
    tally.count();
    int result = tally.get_value();
    cout << "Value of tally: " << result << endl;
    tally.count();
    tally.count();
    result = tally.get_value();
    cout << "Value of tally: " << result << endl;

    Counter concert_counter;
    concert_counter.reset();
    concert_counter.count();
    concert_counter.count();
    concert_counter.count();
    result = concert_counter.get_value();
    cout << "Value of concert_counter: " << result << endl;
    return 0;
}

