#include<iostream>

using namespace std;

class Car {
    //Attributes/Properties/Member Variables/Data
    private:
        string name = "";
        double speed = 0.0;
        int xPos = 0;
        int yPos = 0;

    public:
    //Default Constructors
    Car() {
        cout << "Car is getting created by default constructor..." << endl;
    }


    //Parameterized Constuctors
    Car(string name, double speed, int xPos, int yPos){
        cout << "Car is getting created by 4 Parameterized constructor..." << endl;
        this->name = name;
        this->speed = speed;
        this->xPos = xPos;
        this->yPos = yPos;
    }

    Car(string name, int xPos, int yPos){
        cout << "Car is getting created by 3 Parameterized constructor..." << endl;
        this->name = name;
        this->xPos = xPos;
        this->yPos = yPos;
    }

    Car(string name, double speed){
        cout << "Car is getting created by 2 Parameterized constructor..." << endl;
        this->name = name;
        this->speed = speed;
    }

    Car(int xPos, int yPos){
        cout << "Car is getting created by 2 Parameterized constructor..." << endl;
        this->xPos = xPos;
        this->yPos = yPos;
    }

    Car(string name){
        cout << "Car is getting created by single (1) Parameterized constructor..." << endl;
        this->name = name;
    }

    //Destructor
    ~Car() {
        cout << "Car named:" << this->name << "is getting destroyed..." << endl;
    }

    //Other Functions/Methods
    void start() {
        cout << "Car is starting..." << endl;
        cout << "Bhoom Bhoom..." << endl << endl;
    }

    void stop() {
        cout << "Car is stopping..." << endl;
        cout << "Zzz..." << endl << endl;
    }

    void horn() {
        cout << "Car is horning..." << endl;
        cout << "Peep Peep..." << endl << endl;
    }

    void showInfo() {
        cout << "\t\tCar Information:" << endl;
        cout << "--------------------------------" << endl;
        cout << "Name: " << this->name << endl;
        cout << "Speed : " << this->speed << endl;
        cout << "X Position : " << this->xPos << endl;
        cout << "Y Position : " << this->yPos << endl << endl;
    }
};

int main() {
    Car mercidies("Mercidies", 0.0, 0, 0);
    Car ferrari("Ferrari");
    Car porsche("Porsche", 20, 30);
    Car bmw("BMW", 20);
    Car unknownName(20, 30);
    Car unknownDefault;

    mercidies.showInfo();
    ferrari.showInfo();
    porsche.showInfo();
    bmw.showInfo();
    unknownName.showInfo();
    unknownDefault.showInfo();

    mercidies.start();
    mercidies.horn();
    mercidies.stop();

    return 0;
}