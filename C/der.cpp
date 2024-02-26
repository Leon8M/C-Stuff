#include <iostream>

using namespace std;

class Vehicle{
    public:
        void move(){
            cout << "Vehicle moves" << endl;
        }
};

class Car: public Vehicle{
public:
    void fast(){
        cout << "Car moves fast" << endl;
    }
};

int main(){
    Vehicle x;
    Car y;

    x.move();
    y.fast();

    return 0;
}
