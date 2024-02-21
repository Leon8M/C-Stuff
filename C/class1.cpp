#include <iostream>

using namespace std;


int add (int a ,int b){
    int c = a + b;
    return c;
}

int sub (int a, int b) {
    int c = a - b;
    return c;
}


int main(){
    int x, y, z, v;

    cout << "Enter first: ";
    cin >> x;
    cout << "Enter second: ";
    cin >> y;

    z = add(x, y);
    v = sub(x, y);

    cout << "Sum is: " << z << " and Difference is: " << v;
    x--;
    y++;
    cout << " First less one is: " << x << " and Second one over is: " << y;
    x -= 4;
    y /=2;
    cout << " minus 4: " << x << " divide 2: " << y;

    return 0;
}


