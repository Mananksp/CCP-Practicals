#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
    string Student_ID,name,sem;
    int theory_mark[3]={0},practical_mark[3]={0},credit[3]={0};
    string theory_grade[3],practical_grade[3];
    int theory_grade_point[3]={0},practical_grade_point[3]={0};
    cout<<"Student Id   : ";
    cin>>Student_ID;
    fflush(stdin);
    cout<<"Student Name : ";
    cin>>name;
    fflush(stdin);
    cout<<"sem     : ";
    cin>>sem;
    fflush(stdin);
    cout<<"Enter Subject Names :-"<<endl;
    string subject[3];
    cout<<"Enter Name Of Subject 1 : ";
    getline(cin,subject[0]);
    fflush(stdin);
    cout<<"Enter Name Of Subject 2 : ";
    getline(cin,subject[1]);
    fflush(stdin);
    cout<<"Enter Name Of Subject 3 : ";
    getline(cin,subject[2]);
    fflush(stdin);
    for(int i=0; i<3; i++)
    {
        cout<<"Enter The Marks Of "<<subject[i]<<endl;
        cout<<"Theory Marks : ";
        cin>>theory_mark[i];
        fflush(stdin);
        cout<<"practical Marks : ";
        cin>>practical_mark[i];
        fflush(stdin);
//        cout<<"Enter The Credit Of The Subject : ";
//        cin>>credit[i];
//        fflush(stdin);
    }
    for(int i=0;i<3;i++){
        if(theory_mark[i]>=80){
            theory_grade[i]="AA";
            theory_grade_point[i]=10;
        }
        if(practical_mark[i]>=80){
            practical_grade[i]="AA";
            theory_grade_point[i]=10;
        }
        if(theory_mark[i]<80 && theory_mark[i]>=73){
            theory_grade[i]="AB";
            theory_grade_point[i]=9;
        }
        if(practical_mark[i]<80 && practical_mark[i]>=73){
            practical_grade[i]="AB";
            practical_grade_point[i]=9;
        }
        if(theory_mark[i]<73 && theory_mark[i]>=66){
            theory_grade[i]="BB";
            theory_grade_point[i]=8;
        }
        if(practical_mark[i]<73 && practical_mark[i]>=66){
            practical_grade[i]="BB";
            practical_grade_point[i]=8;
        }
        if(theory_mark[i]<66 && theory_mark[i]>=60){
            theory_grade[i]="BC";
            theory_grade_point[i]=7;
        }
        if(practical_mark[i]<66 && practical_mark[i]>=60){
            practical_grade[i]="BC";
            practical_grade_point[i]=7;
        }
        if(theory_mark[i]<60 && theory_mark[i]>=55){
            theory_grade[i]="CC";
            theory_grade_point[i]=6;
        }
        if(practical_mark[i]<60 && practical_mark[i]>=55){
            practical_grade[i]="CC";
            practical_grade_point[i]=6;
        }
        if(theory_mark[i]<55 && theory_mark[i]>=50){
            theory_grade[i]="CD";
            theory_grade_point[i]=5;
        }
        if(practical_mark[i]<55 && practical_mark[i]>=50){
            practical_grade[i]="CD";
            practical_grade_point[i]=5;
        }
        if(theory_mark[i]<50 && theory_mark[i]>=45){
            theory_grade[i]="DD";
            theory_grade_point[i]=4;
        }
        if(practical_mark[i]<50 && practical_mark[i]>=45){
            practical_grade[i]="DD";
            practical_grade_point[i]=4;
        }
        if(theory_mark[i]<45){
            theory_grade[i]="FF";
            theory_grade_point[i]=0;
        }
        if(practical_mark[i]<45){
            practical_grade[i]="FF";
            practical_grade_point[i]=0;
        }

    }
//calculating SGPA
    float SGPA=0;
    float sum=0;
    for(int i=0;i<3;i++){
        sum=sum+theory_grade_point[i]+practical_grade_point[i];
    }
 SGPA=(float)sum/(float)6;
//printing the content;
    cout<<endl<<endl<<"Printing The Details Of The Student :-"<<endl<<endl;
    cout<<"Student Id   : "<<Student_ID<<endl;
    cout<<"Student Name : "<<name<<endl;
    cout<<"Sem     : "<<sem<<endl;
    cout<<endl<<endl;
    cout<<fixed<<setw(50)<<"Theory";
    cout<<fixed<<setw(23)<<"practical"<<endl;
    for(int i=0;i<3;i++){
        cout<<subject[i];
        cout<<fixed<<setw(47-subject[i].size())<<theory_grade[i];
        cout<<fixed<<setw(21)<<practical_grade[i];
        cout<<endl;
    }
    cout<<endl<<" SGPA :"<<setprecision(4)<< SGPA;
    return 0;
}
