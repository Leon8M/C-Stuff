#include <iostream>

using namespace std;

class Furniture{
    public:
       void make(){
           cout << "We make chairs and tables" << endl;
       }
};

class Table: public Furniture{
    public:
        void tablemaking(){
            cout << "We making tables." << endl;
        }
};

class Dining_Table: public Table{
    public:
        void dining(){
            cout << "Now its just dining tables." << endl;
        }
};

int main(){
    Dining_Table d;
    d.make();
    d.tablemaking();
    d.dining();

    return 0;
}
