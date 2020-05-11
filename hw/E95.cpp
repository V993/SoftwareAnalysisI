/* 
Author: Leonardo Matone
Instructor: Katherine Howitt
Assignment: HW E9.3

Goal: Implement class Rectangle. Provide constuctor to 
constuct a rectangle with a given width and height.
Member functions get_perimeter and get_area that compute the 
perimeter and area, and member function void resize(double factor)
that resizes the rectangle by multiplying the width and height.
*/

#include <iostream>
using namespace std;

class Rectangle{
public:
    double get_perimeter();
    double get_area();
    void resize(double factor);
    Rectangle();
    Rectangle(double h, double w);
private:
    double width;
    double height;
};

Rectangle::Rectangle(double h, double w)
{
    width = w;
    height = h;
}

Rectangle::Rectangle()
{
    width = 0;
    height = 0;
}

double Rectangle::get_perimeter()
{
    double perimeter = (width * 2) + (height * 2);
    return perimeter;
}

double Rectangle::get_area()
{
    double area = width * height;
    return area;
}

void Rectangle::resize(double factor)
{
    width = width * factor;
    height = height * factor;
}

int main()
{
    int h, w;
    cout << "enter height: ";
    cin >> h;
    cout << endl;
    cout << "enter width: ";
    cin >> w;
    cout << endl;
    Rectangle rectangle = Rectangle(h, w);
    cout << "area: " << rectangle.get_area() << endl;
    rectangle.resize(2.0);
    cout << "area: " << rectangle.get_area() << endl;
}