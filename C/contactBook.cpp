#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


struct Contact{
    string name;
    string phoneNumber;
    string email;
};

vector <Contact> contacts;

void addContact(){
    Contact newContact;

    cout << "Enter the name: ";
    cin.ignore();
    getline(cin, newContact.name);
    cout << "Enter the phone number: ";
    getline(cin, newContact.phoneNumber);
    cout << "Enter the email address: ";
    getline(cin, newContact.email);


    contacts.push_back(newContact);

    cout << "Contact added successfully" << endl;
}

void displayContacts(){
    if(contacts.empty()){
        cout << "No contacts present" << endl;
    } else{
        cout << "**Contact List**" << endl;
        for(int i = 0; i < contacts.size(); i++){
            cout << "Name: " << contacts[i].name << endl;
            cout << "Phone Number: " << contacts[i].phoneNumber << endl;
            cout << "Email: " << contacts[i].email << endl << endl;
        }
    }
}

void searchContact(){
    string searchItem;
    cout << "Enter phone number or name to search: ";
    getline(cin, searchItem);

    bool found = false;
    for(int i = 0; i < contacts.size(); i++){
        if(contacts[i].name.find(searchItem)!= string::npos ||
           contacts[i].phoneNumber.find(searchItem) != string::npos){
            found = true;
            cout << "**Contact Found**"<< endl;
            cout << "Name: " << contacts[i].name << endl;
            cout << "Phone number: " << contacts[i].phoneNumber << endl;
            cout << "Email: " << contacts[i].email << endl;
            break;
           }
    }
    if(!found){
        cout << "No such contact" << endl;
    }
}

int main(){
    int choice;

    while(true){
        cout << "** Contact Book **" << endl;
        cout << "1. Add Contact." << endl;
        cout << "2. Display Contacts." << endl;
        cout << "3. Search Contact." << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice){
            case 1: addContact();
            break;
            case 2: displayContacts();
            break;
            case 3: searchContact();
            break;
            case 4: cout << "Exiting......"<< endl;
            return 0;
            default: cout << "Invalid Option." << endl;
        }
        cin.ignore();
    }
}
