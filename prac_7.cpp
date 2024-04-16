#include <iostream>
#include <cmath>
using namespace std;

class complex
{
    float x, y;

public:
    void getdata()
    {
        cout << "Enter real part : ";
        cin >> x;
        cout << "Enter imaginary part : ";
        cin >> y;
    }
    void putdata()
    {
        if (y >= 0)
            cout << x << "+" << y << "i\n";
        else
            cout << x << y << "i\n";
    }
    complex operator+(complex c)
    {
        complex temp;
        temp.x = x + c.x;
        temp.y = y + c.y;
        return temp;
    }
    complex operator-(complex c)
    {
        complex temp;
        temp.x = x - c.x;
        temp.y = y - c.y;
        return temp;
    }
    complex operator!()
    {
        complex temp;
        temp.x = -x;
        temp.y = -y;
        return temp;
    }
    friend complex operator*(complex &, complex &);
    friend complex operator/(complex &, complex &);
};
complex operator*(complex &a, complex &b)
{
    complex temp;
    temp.x = (a.x * b.x) - (a.y * b.y);
    temp.y = (a.x * b.y) + (b.x * b.y);
    return temp;
}
complex operator/(complex &a, complex &b)
{
    complex temp;
    // temp.x=(a.x+a.y)*
    temp.x = ((a.x * b.x) + (a.y * b.y)) / ((b.x * b.x) + (b.y * b.y));
    temp.y = ((b.x * a.y) - (a.x * b.y)) / ((b.x * b.x) + (b.y * b.y));
    return temp;
}
int main()
{
    complex c1, c2, c3, c4;
    char choice;
    c1.getdata();
    c2.getdata();
    cout << "Choose operation\n(+) Addition\n(-) Subtraction\n(*) Multiplication\n(/) Division\n(!) negative\n";
    cin >> choice;
    switch (choice)
    {
    case '+':
        char C;
        label:
        c3 = c1 + c2; // c3=c1.operator+(c2)
        c3.putdata();
        cout << "Do you want to continue further:" << endl;
        cout << "Enter Y for yes or n for no:";
        cin >> C;
        if (C == 'Y' || C == 'y')
        {
            c1.getdata();
            c2.getdata();
            goto label;
        }
        // else{
        //     return 0;
        // }
        break;
    case '-':
        c3 = c1 - c2; // c3=c1.operator-(c2)
        c3.putdata();
        break;
    case '*':
        c3 = c1 * c2;
        c3.putdata();
        break;
    case '/':
        c3 = c1 / c2;
        c3.putdata();
        break;
    case '!':
        c3 = !c1;
        c3.putdata();
        c4 = !c2;
        c4.putdata();
        break;
    default:
        cout << "invalid choice! Enter Valid choice!\n";
        break;
    }
    return 0;
}
