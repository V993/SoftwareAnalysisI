#include <iostream>
using namespace std;

int main()  
{  
   int x, sum = 0;  
   while (x < 10)  
   {  
      cin >> x;  
      if (x > 5)
          sum = sum + x;
   }  
   cout << "The sum of values > 5 is: " << sum << endl;  
}