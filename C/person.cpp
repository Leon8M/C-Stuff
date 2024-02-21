#include <iostream>

using namespace std;

enum class Salary{
    low,
    mid,
    high
};

struct Person{
    string name;
    int age;
    int salary;

    Salary getSalaryEnum() const{
        if (salary < 20000){
            return Salary::low;
        } else if(salary > 50000){
            return Salary::high;
        } else{
            return Salary::mid;
        }
    }
};

ostream& operator<<(ostream& os, const Salary& salary) {
    switch (salary) {
        case Salary::low: os<< "low"; break;
        case Salary::mid: os<< "mid"; break;
        case Salary::high: os<< "high"; break;
       }
       return os;
    }


int main(){
    Person p1 = {"Steve", 20, 70000};
    Person p2 = {"Joy", 21, 10000};

    cout << p1.name << " has a " << p1.getSalaryEnum() << " salary" << endl;

    return 0;
}
