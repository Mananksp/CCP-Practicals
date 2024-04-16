#include <iostream>
#include <iomanip>
using namespace std;

// CLASS EMPLOYEE
class Employee
{
private:
    int ID;
    string NAME;
    string Qualification;
    float Experience;
    long long int Contact_Number;
    static float Avg_Experience;
    static int Count;

protected:
    int Get_ID()
    {
        return ID;
    }
    void Get_Data()
    {
        cout << "Enter the Employee Detail:" << endl;
        fflush(stdin);
        cout << "Enter the Employee ID(Numbers only):";
        cin >> ID;
        fflush(stdin);
        cout << "Enter Employee Name:";
        cin >> NAME;
        fflush(stdin);
        cout << "Enter the Qualification:";
        cin >> Qualification;
        fflush(stdin);
        cout << "Enter Experience:";
        cin >> Experience;
        fflush(stdin);
        cout << "Enter the Contact Number of the Employee:";
        cin >> Contact_Number;
        fflush(stdin);
        Avg_Experience += Experience;
        Count++;
        // fflush(stdin);
    }
    void Put_Data()
    {

        cout << "Employee ID:" << ID << endl;
        cout << "Employee Name:" << NAME << endl;
        cout << "Qualification:" << Qualification << endl;
        cout << "Experince:" << Experience << endl;
        cout << "Contact Number:" << Contact_Number << endl;
    }
    int Search_Employee1(int Employee_ID)
    {
        if (Employee_ID == ID)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

public:
    static void Experience_Avg()
    {
        cout << "Average Experince of Employee " << Avg_Experience << " Years" << endl;
    }

} e;

float Employee ::Avg_Experience;
int Employee::Count;

// CLASS NON TEACHING EMPLOYEE
class Non_Teaching_Employee : public Employee
{
    long int Salary;

public:
    void Get_Data()
    {
        cout << "\nEnter the data of Non_Teaching_Employee:\n";
        Employee::Get_Data();
        cout << "Enter the Salary of the Employee:" << endl;
        cin >> Salary;
        cin.ignore();
    }
    void Put_Data()
    {
        Employee::Put_Data();
        cout << "Salary:" << Salary << endl;
    }
    int Search_Temp_2(int E_ID)
    {
        return Search_Employee1(E_ID);
    }
};

// CLASS TEACHING EMPLOYEE
class Teaching_Employee : public Employee
{
    string Designation, Specialization, Pay_Scale;

public:
    void Get_Data()
    {
        Employee::Get_Data();
        cout << "Enter the Designation:";
        cin >> Designation;
        cout << "Enter the Specialization:";
        cin >> Specialization;
        cout << "Enter the Pay Scale:";
        cin >> Pay_Scale;
    }
    void Put_Data()
    {
        Employee::Put_Data();

        cout << "Designation:" << Designation << endl;
        cout << "Specialization:" << Specialization << endl;
        cout << "Pay Scale:" << Pay_Scale << endl;
    }

    int Search_Temp(int Emp_ID)
    {
        return Search_Employee1(Emp_ID);
    }
};
int main()
{
    int n, i, TN, NTN;
    char ch;
    cout << "Enter the Number of Teaching Employee :";
    cin >> TN;
    Teaching_Employee TE[TN];
    cout << "Enter the Number of Non Teaching Employee :";
    cin >> NTN;
    Non_Teaching_Employee Nte[NTN];
    for (int i = 0; i < TN; i++)
    {
        TE[i].Get_Data();
    }
    for (int i = 0; i < NTN; i++)
    {
        Nte[i].Get_Data();
    }

    int emp_id, g, flag = 0;
    do
    {
        cout << "Enter Employee id:" << endl;
        cin >> emp_id;
        for (i = 0; i < TN; i++)
        {
            g = TE[i].Search_Temp(emp_id);

            if (g == 1)
            {
                TE[i].Put_Data();
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            for (i = 0; i < NTN; i++)
            {
                g = Nte[i].Search_Temp_2(emp_id);

                if (g == 1)
                {
                    Nte[i].Put_Data();
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            cout << "ERROR:ENTERED Employee ID DOSE NOT EXIST!!!!" << endl;
        }
        cout << "Press Y for another Employee detail:";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');
    Employee::Experience_Avg();
}
