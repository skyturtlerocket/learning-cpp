//age guessing program using binary search algorithm
#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "This is a age guessing programming using the binary search algorithm. It guesses anyones age between 0 and 120." << endl;
    int max = 120;
    int min = 0;
    int middle = max/2;
    int n_tries = 0;
    string usr_input;
    bool guess_correct = false;
    while (guess_correct == false) {
        cout << "Is your age above or below " << middle << " [yes/above/below]: ";
        cin >> usr_input;
        if (usr_input == "yes") {
            cout << "Your age is " << middle << ". It took me " << n_tries << " tries to guess it!" << endl;
            guess_correct = true;
        }
        else if (usr_input == "above") {
            n_tries += 1;
            min = middle;
            middle = (min + max)/2;
        }
        else if (usr_input == "below") {
            n_tries += 1;
            max = middle;
            middle = (min + max)/2;
        }
    }
}