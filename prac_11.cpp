//
#include <iostream>
using namespace std;

class Employee_Experience
{
private: 
    float Experience;

public:
//  Parameterised Constructor
    Employee_Experience(int y, int m)
    {
        Experience = y + (m / 12.0);
    }
    float Get_Experience()
    {
        return Experience;
    }
};
int main()
{
    int Years, Months;
    char C;
label:
    // getting the data of the employee
    cout << "Enter Employee Experience in Years and Months " << endl;
    cout << "Year:";
    cin >> Years;
    cout << "Month:";
    cin >> Months;
    // Creation of the object
    Employee_Experience Employee_Exp(Years, Months);

    cout << "Employee's experience: " << Employee_Exp.Get_Experience() << " Years " << endl;
    // for further operation on the program
    cout << "Do you want to continue further:" << endl;
    cout << "Enter Y for yes or N for No:";
    cin >> C;
    if (C == 'Y' || C == 'y')
    {
        goto label;
    }
    else
    {
        exit(0);
    }
    return 0;
}
