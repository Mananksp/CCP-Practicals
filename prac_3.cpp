#include <iostream>
#include <iomanip>
using namespace std;

class CAR
{
public:
    int number_of_car, seating, i;
    char c;
    string Model_name, Fuel_Type, Transmission_value;
    float Showroom_Price, Mileage, Tank_Capacity;
    int GetData()
    {

        fflush(stdin);
        cout << "Enter model name of the car :" << endl;
        getline(cin, Model_name);
        // cin>>Model_name;
        fflush(stdin);
        cout << "Enter the fuel type used by the car: ";
        getline(cin, Fuel_Type);
        fflush(stdin);
        cout << "Enter the showroom price of the car:";
        cin >> Showroom_Price;
        fflush(stdin);
        cout << "Enter the Tank capacity of the car:";
        cin >> Tank_Capacity;
        cout << "Enter the Mileage of the car:";
        cin >> Mileage;
        cout << "Enter the Transmission mode of the car:";
        cin >> Transmission_value;
        fflush(stdin);
        cout << "Enter the seating capacity of the car:";
        cin >> seating;
        cout << "Airbags present in the car:?\n";
        cout << "Enter y or Y for yes and N for no:\n";
        cin >> c;
    }
    void Display_Model_name(int i)//mOdel name functoin
    {

        cout << i + 1 << " ) " << Model_name<<" "; // display all the model name
    }
    int Display_Fuel_Cars(int n)//functoin to find the type of fuel used by the user
    {
        switch (n)
        {
        case 1:
            if (Fuel_Type == "Petrol" || Fuel_Type == "petrol")
            {
                Display_Details();

                break;
            case 2:
                if (Fuel_Type == "Diesel" || Fuel_Type == "diesel")
                {
                    Display_Details();
                }
                break;
            case 3:
                if (Fuel_Type == "CNG" || Fuel_Type == "cng")
                {
                    Display_Details();
                }
                break;
            case 4:
                if (Fuel_Type == "Electric" || Fuel_Type == "electric")
                {
                    Display_Details();
                }
                break;
            }
        }
    }
    int Put_Price(float pr)//display to price
    {
        if (Showroom_Price < pr) // check the condition if model is in budeget of user than display
        {
            Display_Details();
        }
    }
    int Display_Details()//Display the fnal output
    {
        cout << left << setw(8) << "Model" << left << setw(7) << "Fuel" << left << setw(6) << " ShowPrice" <<left<< setw(9)<<right<<"Mileage" << left << setw(15)<< "Transmission" << left << setw(15) << "Tank Capacity" << left << setw(8) << "Seating" << left << setw(7) << "Airbag" << endl;
        cout << endl;
        cout << left << setw(8) << Model_name << left << setw(11) << Fuel_Type << left << setw(8) << Showroom_Price << left << setw(15) << Mileage << left << setw(13) << Transmission_value << left << setw(14) << Tank_Capacity << left << setw(8) << seating << left << setw(8) << c << endl;
        // goto label;
    }
};
int main()
{
    int opt, number, i, choice, price,m;
label:
    cout << "\nEnter the number of cars:(max 999)\n";
    cin >> number;
    if (number < 0 || number > 1000)
    {
        cout << "Enter the car number under the limit of 1 to 1000:";
        goto label;
    }
    CAR C[number];//Here C is the object of the class
    cout << "Enter data of the cars:\n";
    for (i = 0; i < number; i++)
    {
        C[i].GetData(); //calling the getdata function
    }

    cout << "WELCOME TO TATA MOTORS:\n";
    cout << "GET CAR DETAILS AS PER  YOUR PREFRENCE:\n";
    cout << "Option 1:Model Name...\n";
    cout << "Option 2:Fuel Type...\n";
    cout << "Option 3:Price Range...\n";
    cout << "Enter your Option:\n";
    cin >> opt;
    cout << "-----------------------\n";
    switch (opt)
    {
    case 1:
        cout << "\nLISTS OF TATA CARS:";
        // C->Display_Model_name(number);
        for (int i = 0; i < number; i++)
        {
            C[i].Display_Model_name(i);
        }
        cout << "Enter the number of the car you want to find the details of which:";
        cin >> number;
        C[number - 1].Display_Details();
        break;
    case 2:
        cout << "\nTATA MOTORS ARE AVAILABLE WITH FUEL OPTIONS:";
        cout << "\n1) Petrol  2) Diesel  3) CNG  4) Electric";
        cout << "\nENTER YOUR FUEL PREFERENCE:";
        cin >> choice;
        for (int i = 0; i < number; i++)
        {
            
        C[i].Display_Fuel_Cars(choice);//function to display the name of cars with a specific fuel out of the following 4 
        }
        
        break;
    case 3:
    {
        cout << "ENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS : ";
        cin >> m;

        for (i = 0; i < number; i++)
        {

           C[i].Put_Price(m);
        }
    }
        return 0;
    }
}