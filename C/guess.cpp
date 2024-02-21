#include<iostream>
#include<random>
#include<ctime>

using namespace std;

int main(){
    srand((unsigned) time(NULL));

    int random = rand() % 100;
    int guess;
    int attempts = 0;

    do{
        cout << "Guess number between 1 and 100: " << endl;
        cin >> guess;
        attempts++;

        if (guess < random){
            cout << "Too low" << endl;
        }else if(guess > random){
            cout << "Too high" << endl;
        }else{
            cout << "Congrats Man. You guessed " << attempts << " times"<< endl;
            break;
        }
    }while(true);
    return 0;
}

