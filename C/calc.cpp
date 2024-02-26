#include <iostream>

using namespace std;

int add(int x, int y){
    int sum = x + y;
    cout << sum << endl;
    return 0;
}

int sub(int x, int y){
    int diff =  x - y;
    cout << diff << endl;
    return 0;
}

int mul(int x, int y){
    int mult = x * y;
    cout << mult << endl;
    return 0;
}

int dividing(int x, int y){
    int quout = x / y;
    cout << quout << endl;
    return 0;
}

int main (){
    int x, y;
    int z;

    cout << "Welcome to the Calculation World" << endl;
    cout << "Options are as below: " << endl;
    cout << "1. Addition" << endl;
    cout << "2, Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exit" << endl;

    do{
        cout << "Select operation for the two numbers: ";
        cin >> z;
        cout << "Enter your two numbers below, each on their own line: " << endl;
        cin >> x;
        cin >> y;
        
        switch (z){
            case 1: add(x, y);
            break;
            case 2: sub(x, y);
            break;
            case 3: mul(x, y);
            break;
            case 4: dividing(x, y);
            break;
            default: cout << "Invalid choice!" << endl;
        }
        }while(z != 5);
        return 0;
    }
