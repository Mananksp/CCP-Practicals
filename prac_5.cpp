#include <iostream>
using namespace std;
class number
{
    float r, area;

public:
    static int c;
    number()
    {
        r = 1;
    }
    number(float x)
    {
        r = x;
    }
    number(number &N)
    {
        r = N.r;
    }
    static void Adder()
    {
        c++;
    }
    void PutData()
    {
        cout << "Circle with radius " << r << " has area " << (3.148 * r * r) << endl;
        Adder();
    }
    ~number()
    {
        cout << "One object is deleted." << endl;
        Remover();
        cout << "Total active objects are " << c << endl;
    }
    static void Remover()
    {
        c--;
    }
};
int number::c = 0;
int main()
{
    class number *A;
    A = new number;
    A->PutData();
    class number *B;
    B = new number(20);
    B->PutData();
    delete B;
    class number *C;
    C = new number(*A);
    delete A;
    C->PutData();
    delete C;
    return 0;
}
