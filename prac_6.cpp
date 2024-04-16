#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Employee
{
     int ID;
     string Name;
     string Qualification;
     int Experience;
    long long int No;
     static float AvgExperience;
public:
     void GetData()
     {
          cout << "Enter Employee ID :";
          cin >> ID;
          cout << "Enter Employee Name :";
          fflush(stdin);
          getline(cin, Name);
          cout << "Enter Qualification :";
          fflush(stdin);
          getline(cin, Qualification);
          cout << "Enter Experience:"<< " :";
          fflush(stdin);
          cin >> Experience;
          cout << "Enter Contact Number:"<< " :";
          fflush(stdin);
          cin >> No;
          //count++;
          AvgExperience += Experience;
     }
     void PutData()
     {
          cout << "------------------------------------------------------" << endl;
          cout << left << setw(20) << "Name"<< ":   " << Name << endl<< endl;
          cout << left << setw(20) << "Qualification"<< ":   " << Qualification << endl<< endl;
          cout << left << setw(20) << "Experience"<< ":   " << Experience << endl<< endl;
          cout << left << setw(20) << "Contact Number"<< ":   " << No << endl<< endl;
          cout << "------------------------------------------------------" << endl;
     }
     static void AverageExperience(int n)
     {

          AvgExperience = AvgExperience / n;
          cout << "Average Experience : " << AvgExperience;
     }
     int returnID()
     {
          return ID;
     }
};
float Employee :: AvgExperience = 0;
int main()
{
     Employee E1[100];
     int i, n, ID, flag = 0;
     char a;
     int choose;
     cout << "Enter number of Employees"<< " :";
     cin >> n;
     for (i = 0; i < n; i++)
     {
          E1[i].GetData();
     }
     cout << "Enter 1 for get detail of Employee" << endl;
     cout << "Enter 2 for get average of Employee Experience" << endl;
     cin >> choose;
     switch (choose)
     {
     case 1:
          do
          {
               cout << "Enter employe ID to get employ detail"<< " :";
               cin >> ID;
               for (i = 0; i < n; i++)
               {
                    if (E1[i].returnID() == ID)
                    {
                         E1[i].PutData();
                         flag = 1;
                         break;
                    }
                    if (flag == 0)
                    {
                         cout << "*****" << endl;
                         cout << "Error: Entered Employee ID does not exist" << endl;
                         cout << "*****" << endl;
                    }
               }
               cout << "press y if you need another Employee detail or n for exit"<< " :";
               cin >> a;
          } while (a == 'y' || a == 'Y');
          break;
     case 2:
          Employee ::AverageExperience(n);
          break;
     }
     return 0;
}