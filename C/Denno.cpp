#include <iostream>
using namespace std;

int fact(int i){
    if (i == 0){
        return 1;

    } else{
        return i*fact(i - 1);
    }
}

int main(){
    int x;
    cout <<"Enter number: " << endl;
    cin >> x;

    cout << "Factorial of your number is: " << fact(x);
    return 0;
}
