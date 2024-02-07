/*  C++ Program to find employee data based on its id number */
#include <iostream>
#include <iomanip>
using namespace std;

struct Employee
{
private://Access specifiers
    string Employee_Name, Employee_Qualification;
    float Experience;
    long double Contact_Number;

public:
    int Employee_ID;
    int GetData()
    {
        cout << "\nEnter employee ID:";
        cin >> Employee_ID;
        cin.ignore();
        cout << "\nEnter employee Name:";
        getline(cin, Employee_Name);
        fflush(stdin);
        cout << "\nEnter employee Qualification:";
        cin >> Employee_Qualification;
        fflush(stdin);
        cout << "Enter the experience of the employee:";
        cin >> Experience;
        fflush(stdin);
        cout << "\nEnter employee Contact Number:";
        cin >> Contact_Number;
    }

    int PutData()
    {
        char c, id;
        cout << "Employee ID is:" << Employee_ID;
        cout << "--------------------------------";
        cout << "\nEmployee Name :" << Employee_Name;
        cout << "\nQualification  :" << Employee_Qualification;
        cout << "\nExperience  :" << Experience << setw(5) << "years";
        cout << "\nContact Number  :" << Contact_Number;
        cout << "\n-----------------------------";
        cout << "\nPress Y to get detail of another employee,Press N to exit:";
        // c = getchar();
        cin >> c;
        fflush(stdin);
        if (c == 'y' || c == 'Y')
        {
            cout << "\nEnter another employee ID:";
            cin >> id;
            fflush(stdin);
            FindID(id);
        }
        else
            exit(0);//same as return 0 
    }
    int FindID(int ID)
    {
        if (ID == Employee_ID)
        {
            PutData();
        }
        else
        {
            cout << "Invalid Employee ID." << endl;
            // goto label;
            return -1;
        }
        return 0;
    }
} E[1000];

int main()
{
    int opt, GetID;
    while (true)
    {
        cout << "\nChoose any one option from below:";
        cout << "\n1) Get Employee Data:";
        cout << "\n2) Put Employee Data:";
        cout << "\n3) Exit: ";
        cin >> opt;

        switch (opt)
        {
        case 1:
            cout << "Enter Employee ID:";
            cin >> GetID;
            if (E->FindID(GetID) == 0)
            {
                // Employee data found, go back to the main menu
                continue;
            }
            break;

        case 2:
            E->GetData();
            break;

        case 3:
            return 0;

        default:
            cout << "Invalid option. Please choose again." << endl;
        }
    }
}
