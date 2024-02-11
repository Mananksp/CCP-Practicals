#include <iostream>
#define PI 3.14
using namespace std;
int Area(int, int);
float Area(float);
int Area(int);
int main()
{
    int opt, length, breath, area;
    float radius, FloatValaArea;
    cout << "Welcome to area calcluator\n";
    // Calculation of area of rectangle
    cout << "Enter the length and breath of the rectangle:\n";
    cin >> length >> breath;
    area = Area(length, breath);
    cout << "Area of rectangle is:" << area << "\n"; 
    // Calculation of area of square
    cout << "Enter the length of the side of square:";
    cin >> length;
    area = Area(length);
    cout << "Area of square:" << area;
    // Calculation of area of circle
    cout << "\nEnter the radius of the circle:";
    cin >> radius;
    FloatValaArea = Area(radius);
    cout << "Area of Circle:" << FloatValaArea << endl;
    return 0;
}
// Function definition for calculating the area of a rectangle
int Area(int l, int b)
{
    int area;
    area = l * b;
    return area;
}
// Function definition for calculating the area of a circle
float Area(float radius)
{
    float a;
    a = PI * radius * radius;
    return a;
}
// Function definition for calculating the area of a square
int Area(int l)
{
    int b;
    b = l * l;
    return b;
}
