#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class employee
{
private:
    int id;
    string name, quali;
    float exp;
    long int contcat;
    static float avgexp;

protected:
    void getdata()
    
    {
        cout << "enter employee id :";
        cin >> id;
        cout << "enetr employee name :";
        fflush(stdin);
        getline(cin, name);
        cout << "enter qualification :";
        fflush(stdin);
        getline(cin, quali);
        cout << "enter experience"
             << " :";
        fflush(stdin);
        cin >> exp;
        cout << "enter contact number"
             << " :";
        fflush(stdin);
        cin >> contcat;
        avgexp += exp;
    }
    void putdata()
    {
        cout << "------------------------------------------------------" << endl;
        cout << left << setw(20) << "Name"
             << ":   " << name << endl
             << endl;
        cout << left << setw(20) << "Qualification"
             << ":   " << quali << endl
             << endl;
        cout << left << setw(20) << "Experience"
             << ":   " << exp << endl
             << endl;
        cout << left << setw(20) << "Contact Number"
             << ":   " << contcat << endl
             << endl;
    }
    int searchemp()
    {
        return id;
    }

public:
    static void averageexperience(int n)
    {
        avgexp = avgexp / n;
        cout << "Average exprience : " << avgexp;
    }
};
class teaching : public employee
{
private:
    string desi, speci, payscale;

public:
    int searchtemp()
    {
        int a;
        a = searchemp();
        return a;
    }
    void gettemdata()
    {
        getdata();
        cout << "enter desigination : ";
        fflush(stdin);
        getline(cin, desi);
        cout << "enter specification : ";
        fflush(stdin);
        getline(cin, speci);
        cout << "enter payscale : ";
        fflush(stdin);
        getline(cin, payscale);
    }
    void puttemdata()
    {
        putdata();
        cout << left << setw(20) << "Desigination"
             << ":   " << desi << endl
             << endl;
        cout << left << setw(20) << "Specifiaction"
             << ":   " << speci << endl
             << endl;
        cout << left << setw(20) << "Pay Scale"
             << ":   " << payscale << endl
             << endl;
        cout << "------------------------------------------------------" << endl;
    }
};
class nonteaching : public employee // derived class
{
private:
    int salary;

public:
    int searchntemp()
    {
        int b;
        b = searchemp();
        return b;
    }
    void getntempdata()
    {
        getdata();
        cout << "enter salary of non-teaching employee : ";
        cin >> salary;
    }
    void putntempdata()
    {
        putdata();
        cout << left << setw(20) << "Salary"
             << ":   " << salary << endl
             << endl;
        cout << "------------------------------------------------------" << endl;
    }
};
float employee ::avgexp = 0;

int main()
{
    teaching t[500];
    nonteaching nt[500];
    int n, i, p, id;
    char Input;
    cout << "Enter number of teaching employee : ";
    cin >> n;
    cout << "Enter number of non-teaching employee : ";
    cin >> p;
    int w;
    w = n + p;
    for (i = 0; i < n; i++)
    {
        cout << "Enter teaching employeee data " << endl;
        cout << "---------------------------------------------------" << endl;
        t[i].gettemdata();
    }
    cout << "---------------------------------------------------" << endl;
    for (i = 0; i < p; i++)
    {
        cout << "Enter non-teaching employeee data : " << endl;
        cout << "---------------------------------------------------" << endl;
        nt[i].getntempdata();
    }
    cout << "---------------------------------------------------" << endl;
    int h;
    cout << "(1) for get deatils of employees : " << endl;
    cout << "(2) for average experience of employee : ";
    cin >> h;
    switch (h)
    {
    case 1:
        if (Input == 'Y' || Input == 'y')
        {
            cout << "enter id that you wnat to search : ";
            cin >> id;
            for (i = 0; i < n; i++)
            {
                t[i].searchtemp();
                if (t[i].searchtemp() == id)
                {
                    cout << "Displaying data of teaching staff" << endl;
                    t[i].puttemdata();
                }
            }
            for (i = 0; i < p; i++)
            {
                nt[i].searchntemp();
                if (nt[i].searchntemp() == id)
                {
                    cout << "Displaying data of non-teachinf staff" << endl;
                    nt[i].putntempdata();
                }
            }
            cout << "Press Y to get another employee detail, Press N to exit : ";
            cin >> Input;
        }
        else
        {
            cout << "**********************************************" << endl;
            cout << "ERROR : ENTERED EMPLOYEE ID DOES NOT EXIST" << endl;
            cout << "**********************************************" << endl;
        }
        break;
    case 2:
        employee ::averageexperience(w);
        break;
    }

    return 0;
}
