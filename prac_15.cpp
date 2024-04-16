#include <iostream>
#include <string>
// #include<iomanip>
using namespace std;
class product
{
protected:
    int ID;
    string name;
    string Manufacture;
    float price;

public:
    product(int a, string b, string c, float d)
    {
        ID = a;
        name = b;
        Manufacture = c;
        price = d;
    }
    virtual void putdata() = 0;
};
class SmartWatch : public product
{
protected:
    float dial_size;

public:
    SmartWatch(int a, string b, string c, float d, float t) : product(a, b, c, d)
    {
        dial_size = t;
    }
    void putdata()
    {
        cout << "ID " << ": " << ID << endl;
        cout << "NAME " << ": " << name << endl;
        cout << "ManufactureACTURER " << ": " << Manufacture << endl;
        cout << "PRICE " << ": " << price << endl;
        cout << "DIAL SIZE " << ": " << dial_size << endl;
    }
};
class bedsheet : public product
{
protected:
    float wIDth, height;

public:
    bedsheet(int a, string b, string c, float d, float u, float i) : product(a, b, c, d)
    {
        wIDth = u;
        height = i;
    }
    void putdata()
    {
        cout << "ID " << ": " << ID << endl;
        cout << "NAME " << ": " << name << endl;
        cout << "ManufactureACTURER " << ": " << Manufacture << endl;
        cout << "PRICE " << ": " << price << endl;
        cout << "WIDTH " << ": " << wIDth << endl;
        cout << "HEIGHT " << ": " << height << endl;
    }
};
int main()
{
    int choice;
    long int ID;
    string name,Manufacture;
    float price,dial_size,wIDth, height;
    cout << "Enter 1 for SmartWatch menu:" << endl;
    cout << "Enter 2 for bedsheet menu:" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter product ID : ";
        cin >> ID;
        cout << "Enter product name : ";
        fflush(stdin);
        getline(cin, name);
        cout << "Enter product Manufactureacturer : ";
        fflush(stdin);
        getline(cin, Manufacture);
        cout << "Enter product price : ";
        cin >> price;
        cout << "Enter product dail size : ";
        cin >> dial_size;
        // SmartWatch *s = new SmartWatch(ID,name,Manufacture,price,dial_size);
        SmartWatch *p;
        p = new SmartWatch(ID, name, Manufacture, price, dial_size);
        p->putdata();
        // s->putdata();
        break;
    case 2:
        cout << "Enter product ID : ";
        cin >> ID;
        cout << "Enter product Name : ";
        fflush(stdin);
        getline(cin, name);
        cout << "Enter product Manufacturer : ";
        fflush(stdin);
        getline(cin, Manufacture);
        cout << "Enter product Price : ";
        cin >> price;
        cout << "Enter product WIDth : ";
        cin >> wIDth;
        cout << "Enter product Heigth : ";
        cin >> height;
        // bedsheet b(ID,name,Manufacture,price,wIDth,height);
        // s.putdata();
        bedsheet *sheet;
        sheet = new bedsheet(ID, name, Manufacture, price, wIDth, height);
        sheet->putdata();
        break;
    }

    return 0;
}
