#include <iostream>
using namespace std;

class Millimeter {
private:
    float millimeters;

public:
    Millimeter(float mm) : millimeters(mm) {}

    float toCentimeters() {
        return millimeters / 10.0;
    }
};

class Centimeter {
private:
    float centimeters;

public:
    Centimeter(float cm) : centimeters(cm) {}

    float toMillimeters() {
        return centimeters * 10.0;
    }
};

int main() {
    int choice;
    cout<<"Enter 1 : mm to cm converter:"<<endl;
    cout<<"Enter 2 : cm to mm converter:"<<endl;
    if (choice == 1)
    {
        // cout<<"Enter the";
    }
    float millimeterValue = 250.0;
    Millimeter mm(millimeterValue);
    cout << millimeterValue << " millimeters is equal to " << mm.toCentimeters() << " centimeters" << endl;

    float centimeterValue = 25.0;
    Centimeter cm(centimeterValue);
    cout << centimeterValue << " centimeters is equal to " << cm.toMillimeters() << " millimeters" << endl;

    return 0;
}
