#include <iostream>
using namespace std;

class Bug{
public:
    void up();
    void reset();
    int get_position();
private:
    int position;
};

void Bug::up()
{
    position += 10;
    if (position == 100){reset();}
}
void Bug::reset()
{
    position = 0;
}
int Bug::get_position()
{
    return position;
}

int main()
{
   Bug bugsy;
   Bug itsy_bitsy;
   bugsy.reset();
   itsy_bitsy.reset();
   bugsy.up();
   bugsy.up();
   cout << bugsy.get_position() << endl;
   cout << "Expected: 20" << endl;
   itsy_bitsy.up();
   itsy_bitsy.up();
   itsy_bitsy.up();
   cout << itsy_bitsy.get_position() << endl;
   cout << "Expected: 30" << endl;
   for (int i = 1; i <= 8; i++) { bugsy.up(); }
   cout << bugsy.get_position() << endl;
   cout << "Expected: 0" << endl;
   bugsy.up();
   cout << bugsy.get_position() << endl;
   cout << "Expected: 10" << endl;
   
   return 0;
}