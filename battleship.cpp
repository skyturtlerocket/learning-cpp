#include <iostream>

using namespace std;

int main() {
    int n_turns = 0;
    int n_ships_left = 14;
    bool board[6][6] = {
        {1, 0, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 1},
        {0, 1, 1, 1, 0, 0},
    };
    cout << "This is a 6 x 6 game of Battleship! There are 4 ships to hit." << endl;
    int row, column;
    while (n_ships_left > 0) {
        cout << "Select which row (1 - 6): ";
        cin >> row;
        cout << "Select which column (1 - 6): ";
        cin >> column;
        if (board[row-1][column-1]) { 
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
