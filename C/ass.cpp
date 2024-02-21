#include <iostream>
using namespace std;

char calculateGrade(int score) {
    if (score >= 90 && score <= 100) {
        return 'A';
    } else if (score >= 80 && score < 90) {
        return 'B';
    } else if (score >= 70 && score < 80) {
        return 'C';
    } else if (score >= 60 && score < 70) {
        return 'D';
    } else if (score >= 0 && score < 60) {
        return 'F';
    } else {
        return 'I';
    }
}

int main() {
    int score;
    cout << "Enter the score: ";
    cin >> score;

    char grade = calculateGrade(score);

    if (grade == 'I') {
        cout << "Invalid input! Please enter a score between 0 and 100." << endl;
    } else {
        cout << "The grade for score " << score << " is " << grade << endl;
    }

    return 0;
}
