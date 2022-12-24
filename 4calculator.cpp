#include <iostream>
#include <string>

using namespace std;

int main() {
    typedef long long ll; //doing long long incase input decides to be really big 
    ll n1, n2, answer;
    string operation; //did string because it also supports mod
    bool calculation_done = false; //this is for the loop
    cout << "This is a 4-function calculator." << endl;
    cout << "To end, type in any number, the character ! and another number, on the same line." << endl;
    cout << "Do note that division rounds to the nearest WHOLE number." << endl;
    while (calculation_done == false) { 
        cout << "Type in your first number, operation, and second number, in the order stated: ";
        cin >> n1 >> operation >> n2;
        if (operation == "+") { //addition
            answer = n1 + n2;
            cout << "The answer is: " << answer << "\n";
        } 
        else if (operation == "-") { //subtraction
            answer = n1 - n2;
            cout << "The answer is: " << answer << endl;
        }
        else if (operation == "*") { //multiplication
            answer = n1 * n2;
            cout << "The answer is: " << answer << endl;
        }
        else if (operation == "/") { //division, rounds to nearest whole number
            answer = n1 / n2;
            cout << "The answer is: " << answer << endl;
        }
        else if (operation == "!") { //ending loop, from beginning of instructions it says to use the character "!"
            calculation_done = true;
            cout << "Powering off..." << endl;
        }
        else if (operation == "mod") { //I added it so it also does something that isn't 4-fucntion
            answer = n1 % n2;
            cout << "The answer is: " <<  answer << endl;
        } else { //in case you typo the character or something
            cout << "I don't understand that, please try again!" << endl;
        }
    }
}