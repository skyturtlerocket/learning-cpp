#include <iostream>

using namespace std;

int main() {
    int n_turns = 0;
    int n_ships_left = 20;
    bool board[7][7] = { //I'm pretty sure 7 x 7 board is the standard size
        {0, 0, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 0, 0},
    };
    cout << "This is a 7 x 7 game of Battleship! There are 5 ships to hit. (lengths 5, 4, 3, 3, and 2)" << endl; //I'm pretty sure those are the original ship lengths too
    int row, column; //initializing variables
    while (n_ships_left > 0) {
        cout << "Select which row (1 - 7): ";
        cin >> row; 
        cout << "Select which column (1 - 7): ";
        cin >> column;
        if (board[row-1][column-1]) { //checking if the element in the list at that position is true or not, if it's true then it executes the below lines
            board[row-1][column-1] = 0;
            n_turns += 1;
            n_ships_left -= 1;
            cout << "Hit! Turn number " << n_turns << " complete." << " There are " << n_ships_left<< " places to hit left." << endl;
        } else {
            n_turns++;
            cout << "Miss! Turn number " << n_turns << " complete." << endl; 
        }
    }
    cout << "Congratulations! You beat the game in " << n_turns << " turns!" << endl;
    //the following lines are there so it gives you a rating based on how many turns you took
    if (n_turns <= 20) {
        cout << "Amazing job, you beat the game with a rating 3/3!" << endl;
    }
    else if (n_turns > 20 && n_turns <= 30) {
        cout << "Nice job, You beat the game with a rating 2/3!" << endl;
    }
    else if (n_turns > 30 && n_turns < 36) {
        cout << "You beat the game with a rating 1/3! Try again to do better!" << endl;
    } else {
        cout << "You beat the game with a rating 0/3! Better luck next time!" << endl;
    }
}

