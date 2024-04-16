// Write a program to convert years of a Experience into years and months
#include <iostream>
using namespace std;

class Converter
{
    int years, months;

public:
    Converter()
    {
        years = 0;
        months = 0;
    }
    Converter(float Exp)
    {
        years = Exp;
        months = (Exp - years) * 12;
    }
    void PutData()
    {
        cout << "\nEmployee Experience is " << years << " years and " << months << " months";
    }
};
int main()
{
    float Experience;
    cout << "Enter your Experience:";
    cin >> Experience;
    Converter converter(Experience);
    converter.PutData();
    return 0;
}