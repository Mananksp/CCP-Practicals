#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Result;
class Student
{
    string Student_ID, Student_Name;
    int Semester;

public:
    void GetData();
    void PutData();
    void Get_Result(Result &r);
    void PutResult(Result &r);
    void SGPA_Result(Result &r);
};
void Student::GetData()
{
    cout << left << setw(21) << "Enter student ID "<< ":";
    fflush(stdin);
    cin >> Student_ID;

    cout << left << setw(21) << "Enter student name "<< ":";
    fflush(stdin);
    cin >> Student_Name;

    cout << left << setw(21) << "Enter Semester "<< ":";
    cin >> Semester;
    fflush(stdin);
}
void Student :: PutData()
{
    cout << "--------------Details--------------" << endl;
    cout << "Student ID" << setw(11) << ":   " << Student_ID << endl;
    cout << "Student name" << setw(9) << ":   " << Student_Name << endl;
    cout << "Semester" << setw(13) << ":   " << Semester << endl;
    cout << "------------------------------------------------------------" << endl;
}

// CLass Result starts here 
class Result
{
    int CreditSum = 0, Practical_grade[3], Theory_grade[3], Practical_Credit[3], Theory_Credit[3];
    string Sub_1, Sub_2, Sub_3;
    float sgpa, sumA = 0, sumB = 0;
    string a[3], b[3];
    int Theory[3];
    int practical[3];
    friend class Student;
};
void Student ::Get_Result(Result &Res)
{
    fflush(stdin);
    cout << "Enter name of subject 1 : ";
    cin >> Res.Sub_1;
    fflush(stdin);
    cout << "Enter name of subject 2 : ";
    cin >> Res.Sub_2;
    fflush(stdin);
    cout << "Enter name of subject 3 : ";
    cin >> Res.Sub_3;
    fflush(stdin);
    cout << "Credit of Theory" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Credit for Sub" << i + 1 << endl;
        cin >> Res.Theory_Credit[i];
    }
    cout << "Credit of Practical" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Credit for Sub" << i + 1 << endl;
        cin >> Res.Practical_Credit[i];
    }

    for (int i = 0; i < 3; i++) // input for practical marks
    {
        cout << "Enter practical marks " << i + 1 << ": ";
        cin >> Res.practical[i];
        fflush(stdin);
    }

    for (int j = 0; j < 3; j++) // input for marks of Theory
    {
        cout << "Enter marks of Theory  " << j + 1 << ": ";
        cin >> Res.Theory[j];
        fflush(stdin);
    }

    for (int j = 0; j < 3; j++) // b variable for Theory, garde_t for Theory
    {

        if (Res.Theory[j] >= 80)
        {
            Res.Theory_grade[j] = 10;
            Res.b[j] = "AA";
        }
        else if (Res.Theory[j] >= 73 && Res.Theory[j] < 80)
        {
            Res.Theory_grade[j] = 9;
            Res.b[j] = "AB";
        }
        else if (Res.Theory[j] >= 66 && Res.Theory[j] < 73)
        {
            Res.Theory_grade[j] = 8;
            Res.b[j] = "BB";
        }
        else if (Res.Theory[j] >= 60 && Res.Theory[j] < 66)
        {
            Res.Theory_grade[j] = 7;
            Res.b[j] = "BC";
        }
        else if (Res.Theory[j] >= 55 && Res.Theory[j] < 60)
        {
            Res.Theory_grade[j] = 6;
            Res.b[j] = "CC";
        }
        else if (Res.Theory[j] >= 50 && Res.Theory[j] < 55)
        {
            Res.Theory_grade[j] = 5;
            Res.b[j] = "CD";
        }
        else if (Res.Theory[j] >= 45 && Res.Theory[j] < 50)
        {
            Res.Theory_grade[j] = 4;
            Res.b[j] = "DD";
        }
        else
        {
            Res.Theory_grade[j] = 0;
            Res.b[j] = "FF";
        }
    }

    for (int i = 0; i < 3; i++) // a variable for practical, garde_p for practical
    {
        if (Res.practical[i] >= 80)
        {
            Res.Practical_grade[i] = 10;
            Res.a[i] = "AA";
        }
        else if (Res.practical[i] >= 73 && Res.practical[i] < 80)
        {
            Res.Practical_grade[i] = 9;
            Res.a[i] = "AB";
        }
        else if (Res.practical[i] >= 66 && Res.practical[i] < 73)
        {
            Res.Practical_grade[i] = 8;
            Res.a[i] = "BB";
        }
        else if (Res.practical[i] >= 60 && Res.practical[i] < 66)
        {
            Res.Practical_grade[i] = 7;
            Res.a[i] = "BC";
        }
        else if (Res.practical[i] >= 55 && Res.practical[i] < 60)
        {
            Res.Practical_grade[i] = 6;
            Res.a[i] = "CC";
        }
        else if (Res.practical[i] >= 50 && Res.practical[i] < 55)
        {
            Res.Practical_grade[i] = 5;
            Res.a[i] = "CD";
        }
        else if (Res.practical[i] >= 45 && Res.practical[i] < 50)
        {
            Res.Practical_grade[i] = 4;
            Res.a[i] = "DD";
        }
        else
        {
            Res.Practical_grade[i] = 0;
            Res.a[i] = "FF";
        }
    }
}
void Student :: SGPA_Result(Result &result)
{
    // sgpa=credit*grade/sum of credits
    for (int i = 0; i < 3; i++)
    {
        result.sumA = result.sumA + ((float)result.Theory_grade[i] * result.Theory_Credit[i]);
        result.sumB = result.sumB + ((float)result.Practical_grade[i] * result.Practical_Credit[i]);
        result.CreditSum += (result.Practical_Credit[i] + result.Theory_Credit[i]);
    }
    result.sgpa = float(result.sumA + result.sumB) / result.CreditSum; // dividing sgpa by sum of cerdits
}
void Student :: PutResult(Result &result)
{
    SGPA_Result(result);
    cout << left << setw(10) << "Subject" << setw(35) << right << "Theory" << setw(15) << "Practical" << endl;
    cout << left << setw(30) << result.Sub_1 << right << setw(15) << result.b[0] << right << setw(15) << result.a[0] << endl;
    cout << left << setw(30) << result.Sub_2 << right << setw(15) << result.b[1] << right << setw(15) << result.a[1] << endl;
    cout << left << setw(30) << result.Sub_3 << right << setw(15) << result.b[2] << right << setw(15) << result.a[2] << endl;
    cout << "SGPA" << setw(15) << ": " << setprecision(2) << result.sgpa;
}

int main()
{
    Student s;
    Result res;
    s.GetData();
    s.Get_Result(res);
    s.PutData();
    s.PutResult(res);
    return 0;
}