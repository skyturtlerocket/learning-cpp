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
    char usr_board[7][7] = {
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
    };
    cout << "This is a 7 x 7 game of Battleship! There are 5 ships to hit. (lengths 5, 4, 3, 3, and 2)\n" << "0 means it has not been explored yet, M means miss, and X means hit!. Have fun!"; //I'm pretty sure those are the original ship lengths too
    
    int row, column; //initializing variables
    while (n_ships_left > 0) {
        cout << "\n" << endl;
        for (int i = 0; i < 7; i++) { //printing the usr_board
            for (int j = 0; j < 7; j++) {
                cout << usr_board[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n" << endl;
        cout << "Select which row (1 - 7): ";
        cin >> row;
        if (row > 7) {
            cout << "The input is too big!" << endl;            
        } 
        cout << "Select which column (1 - 7): ";
        cin >> column;
        if (column > 7) {
            cout << "The input is too big!" << endl;
            break;
        }
        
        if (usr_board[row-1][column-1] == 'M') {
            cout << "\n" << endl;
            cout << "You already missed this in this spot!" << endl;
            break;
        }
        else if (usr_board[row-1][column-1] == 'X') {
            cout << "\n" << endl;
            cout << "You already hit this place!" << endl;
        }
        else if (board[row-1][column-1]) { //checking if the element in the list at that position is true or not, if it's true then it executes the below lines
            board[row-1][column-1] = 0;
            usr_board[row-1][column-1] = 'X';
            n_turns += 1;
            n_ships_left -= 1;
            cout << "Hit! Turn number " << n_turns << " complete." << " There are " << n_ships_left<< " places to hit left." << endl;
            cout << "\n" << endl;
        } else {
            n_turns++;
            usr_board[row-1][column-1] = 'M';
            cout << "Miss! Turn number " << n_turns << " complete." << endl; 
            cout << "\n" << endl;
        }
    }
    cout << "Congratulations! You beat the game in " << n_turns << " turns!" << endl;
    //the following lines are there so it gives you a rating based on how many turns you took
    if (n_turns <= 20) {
        cout << "Amazing job, you beat the game with a rating 5/5!" << endl;
    }
    else if (n_turns > 20 && n_turns <= 25) {
        cout << "Nice job, You beat the game with a rating 4/5!" << endl;
    }
    else if (n_turns > 25 && n_turns <= 30) {
        cout << "Congrats, you beat the game with a rating 3/5! Try again to do better!" << endl;
    }
    else if (n_turns > 30 && n_turns <= 35) {
        cout << "Nice, You beat the game with a rating 2/5! Try again to do better!" << endl;
    }
    else if (n_turns > 35 && n_turns <= 40) {
        cout << "Ok, you beat the game with a rating 1/5! Try again to do better!" << endl;
    } else {
        cout << "You beat the game with a rating 0/5! Better luck next time!" << endl;
    }
}
