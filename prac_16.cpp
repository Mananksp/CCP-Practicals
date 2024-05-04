// Concept of a file
#include <iostream>
#include <iomanip>
#include <conio.h>
#include <fstream>
using namespace std;
// non-member function
void print()
{
    cout << endl;
    cout << setw(17);
    cout << left << "Model";
    cout << setw(17);
    cout << left << "Fuel";
    cout << setw(17);
    cout << left << "price";
    cout << setw(17);
    cout << left << "Mileage";
    cout << setw(17);
    cout << left << "Transmission";
    cout << setw(17);
    cout << left << "Tank Capacity";
    cout << setw(17);
    cout << left << "Seating";
    cout << setw(17);
    cout << left << "Airbags" << endl;
    cout << setw(23) << "\t\t\t\t  (Lakhs)";
    cout << setw(34);
    cout << left << "(Km/L)";
    cout << setw(17);
    cout << left << "(Liters)";
    cout << setw(10);
    cout << left << "Capacity";
}
class cars // user defined data type
{
private:
    string model_name; // data member
    string fuel_type;
    float price;
    float milage;
    string trans;
    // int trans;
    float tank_cap;
    int seatno;
    string airbag;
    // bool airbag;

public:
    int g; // member functions
    void displaymm()
    {
        cout << model_name;
    }
    void findrange(int range)
    {
        if (price <= range)
            getdetails();
    }
    void checkg(int mm) // hear
    {
        if (mm == g)
            getdetails();
    }
    int gg()
    {
        return g;
    }
    void getdata(string m, string ftype, float p, float mil, string trann, float tankcap, int sin, string airb)
    {
        model_name = m;
        fuel_type = ftype;
        price = p;
        milage = mil;
        trans = trann;
        tank_cap = tankcap;
        seatno = sin;
        airbag = airb;
    }
    void getdetails()
    {
        cout << endl;
        cout << setw(17);
        cout << left << model_name;
        fflush(stdout);
        if (g == 1)
        {
            cout << setw(17);
            cout << left << "Petrol"; // fflush(stdout);
        }
        else if (g == 2)
        {
            cout << setw(17);
            cout << left << "Diesel"; // fflush(stdout);
        }
        else if (g == 3)
        {
            cout << setw(17);
            cout << left << "CNG"; // fflush(stdout);
        }
        else
        {
            cout << setw(17);
            cout << left << "Electric"; // fflush(stdout);
        }
        cout << setw(17);
        cout << left << price;
        fflush(stdout);
        cout << setw(17);
        cout << left << milage;
        fflush(stdout);
        cout << setw(17);
        cout << left;
        cout << trans;
        fflush(stdout);
        cout << setw(17);
        cout << left << tank_cap;
        fflush(stdout);
        cout << setw(17);
        cout << left << seatno;
        fflush(stdout);
        cout << setw(17);
        cout << left << airbag;
        fflush(stdout);
    }
};
int main()
{
    cars o[15]; // creating array of an object

    ifstream inf("cardata.txt"); // create the object named inf

    if (!inf)
    {                                  // checking that file is able to open or not
        cout << "Unable to open file"; // if unable program will be ended.
        return 1;
    }
    int count = 0; // for counting no. of created objects
    cout << "File opened successfully\n";
    string model_name, fuel_type, trans, airbag;
    string price, mileage, tc;
    float price1, mileage1, tc1;
    string seating;
    int seating1;
    while (inf) // read from the text file
    {
        getline(inf, model_name, ','); // 3rd syntax of getline()
        cout << "model name = " << model_name << endl;
        getline(inf, fuel_type, ',');
        cout << "fuel Type = " << fuel_type << endl;
        if (fuel_type == "Petrol")
            o[count].g = 1;
        else if (fuel_type == "Diesel")
            o[count].g = 2;
        else if (fuel_type == "CNG")
            o[count].g = 3;
        else
            o[count].g = 4;
        getline(inf, price, ',');
        price1 = stof(price); // conversion of string to float
        cout << "Price = " << price1 << endl;
        // price1 = stof(price);
        getline(inf, mileage, ',');
        mileage1 = stof(mileage);
        cout << "mileage = " << mileage1 << endl;
        getline(inf, trans, ',');
        cout << "Transmission = " << trans << endl;
        getline(inf, tc, ',');
        tc1 = stof(tc);
        cout << "Tank Capacity = " << tc1 << endl;
        getline(inf, seating, ',');
        seating1 = stod(seating); // string to integer
        cout << "Seating = " << seating1 << endl;
        getline(inf, airbag, ';');
        cout << "Airbags = " << airbag << endl;
        o[count].getdata(model_name, fuel_type, price1, mileage1, trans, tc1, seating1, airbag);
        count++;
    }

    inf.close(); // close the file

    getch();

    int z;
    cout << "WELCOME TO TATA MOTORS" << endl
         << "GET THE CAR DETAILS AS PER YOUR PREFERENCE\n"
         << endl;
    cout << "(1)Model Name(2)Fuel Type(3)Price Range\n"
         << endl;
    int option;
    cout << "Enter your option" << endl;
    cin >> option;
    cout << endl
         << "::::::::::::::::::::::::::::::::::" << endl
         << endl;
    switch (option)
    {
    case 1:
        cout << "LIST OF TATA CARS\n"
             << endl;
        for (int j = 0; j < count; j++)
        {
            // o[j].displaymm();
            setw(10);
            cout << left << "(" << j + 1 << ")";
            o[j].displaymm();
        }
        cout << endl;
        cout << "\nCHOOSE YOUR CAR TO GET DETAIL:" << endl;
        cin >> z;
        print();
        o[z - 1].getdetails();
        break;
    case 2:
        cout << "TATA MOTORS ARE AVAILABLE WITH FUEL OPTIONS\n"
             << endl;
        cout << "(1)Petrol (2)Diesel (3)CNG (4)Electric\n"
             << endl;
        cout << "ENTER YOUR FUEL PREFERENCE\n"
             << endl;
        cin >> z;
        print();
        for (int ty = 0; ty < count; ty++)
        {
            int xz = o[ty].gg();
            if (xz == z)
            {
                o[ty - 1].getdetails();
            }
        }
        break;
    case 3:
        cout << "\nENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS:" << endl;
        int range;
        cin >> range;
        print(); // To print format of hading
        for (int u = 0; u < count; u++)
        {
            o[u].findrange(range);
        }
        break;
        default :
        cout<<"Enter a valid option between 1 to 3.";
    }
}
