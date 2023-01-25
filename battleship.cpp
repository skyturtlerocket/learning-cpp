/*
Battleship Program, you can play against a computer bot.
*/
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int main() {
  // cout << generate_num() << endl;
  int n_turns = 0;
  int n_ships_left_usr = 20;
  int computer_ships_left = 20;
  bool board[7][7] = {
      // This is placement of computer's board.
      {0, 0, 1, 0, 1, 1, 1}, 
      {0, 0, 1, 0, 0, 1, 0}, 
      {1, 0, 1, 0, 0, 1, 0},
      {1, 0, 1, 0, 0, 1, 0}, 
      {0, 0, 1, 0, 0, 1, 0}, 
      {0, 0, 0, 0, 0, 0, 0},
      {0, 1, 1, 1, 0, 0, 0},
  };
  bool usr_board[7][7] = {
      {0, 0, 0, 0, 0, 0, 0}, 
      {0, 0, 0, 0, 0, 0, 0}, 
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0}, 
      {0, 0, 0, 0, 0, 0, 0}, 
      {0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0},
  };
  char usr_guess[7][7] = {
      // This shows what you've guessed.
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'}, 
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'}, 
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'}, 
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
  };
  char computer_guess[7][7] = {
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'}, 
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'}, 
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'}, 
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
      {'O', 'O', 'O', 'O', 'O', 'O', 'O'},
  };
  int row, column, row1, column1;
  cout << "This is a 7 x 7 game of Battleship! There are 5 ships to hit. (lengths 5, 4, 3, 3, and 2).\n"  << "0 means it has not been explored yet, M means miss, and X means hit!. Have fun!" << endl; // I'm pretty sure those are the original ship lengths too
  cout << "Choose the placement of your ships." << "\n" << endl;
  cout << "  1 2 3 4 5 6 7 " << endl;
  for (int i = 0; i < 7; i++) {
    cout << i + 1 << " ";
    for (int j = 0; j < 7; j++) {
      cout << usr_board[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n" << "Choose which row to place endpoint 1 of battleship (length 4): ";
  cin >> row;
  cout << "Choose which column to place endpoint 1 of battleship (length 4): ";
  cin >> column;
  cout << "Choose which row to place endpoint 2 of battleship (length 4): ";
  cin >> row1;
  cout << "Choose which column to place endpoint 2 of battleship (length 4): ";
  cin >> column1;
  cout << "\n";
  if (row == row1) {
    for (int i = 0; i < 4; i++) {
      if (usr_board[row - 1][column + i - 1] == false) {
        usr_board[row - 1][column + i - 1] = true;
      } else if (usr_board[row + i][column] == true) {
        cout << "Hey, ships can't collide!" << endl;
      }
    }
  } else if (column == column1) {
    for (int i = 0; i < 4; i++) {
      if (usr_board[row + i - 1][column - 1] == false) {
        usr_board[row + i - 1][column - 1] = true;
      } else if (usr_board[row + i][column] == true) {
        cout << "Hey, ships can't collide!" << endl;
      }
    }
  }
  cout << "  1 2 3 4 5 6 7 " << endl;
  for (int i = 0; i < 7; i++) {
    cout << i + 1 << " ";
    for (int j = 0; j < 7; j++) {
      cout << usr_board[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n" << "Choose which row to place endpoint 1 of carrier (length 5): ";
  cin >> row;
  cout << "Choose which column to place endpoint 1 of carrier (length 5): ";
  cin >> column;
  cout << "Choose which row to place endpoint 2 of carrier (length 5): ";
  cin >> row1;
  cout << "Choose which column to place endpoint 2 of carrier (length 5): ";
  cin >> column1;
  cout << "\n";
  if (row == row1) {
    for (int i = 0; i < 5; i++) {
      if (usr_board[row - 1][column + i - 1] == false) {
        usr_board[row - 1][column + i - 1] = true;
      } else if (usr_board[row + i][column] == true) {
        cout << "Hey, ships can't collide!" << endl;
      }
    }
  } else if (column == column1) {
    for (int i = 0; i < 5; i++) {
      if (usr_board[row + i - 1][column - 1] == false) {
        usr_board[row + i - 1][column - 1] = true;
      } else if (usr_board[row + i][column] == true) {
        cout << "Hey, ships can't collide!" << endl;
      }
    }
  }
  cout << "  1 2 3 4 5 6 7 " << endl;
  for (int i = 0; i < 7; i++) {
    cout << i + 1 << " ";
    for (int j = 0; j < 7; j++) {
      cout << usr_board[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\n" << "Choose which row to place endpoint 1 of cruiser (length 3): ";
  cin >> row;
  cout << "Choose which column to place endpoint 1 of cruiser (length 3): ";
  cin >> column;
  cout << "Choose which row to place endpoint 2 of cruiser (length 3): ";
  cin >> row1;
  cout << "Choose which column to place endpoint 2 of cruiser (length 3): ";
  cin >> column1;
  cout << "\n";
  if (row == row1) {
    for (int i = 0; i < 3; i++) {
      if (usr_board[row - 1][column + i - 1] == false) {
        usr_board[row - 1][column + i - 1] = true;
      } else if (usr_board[row + i][column] == true) {
        cout << "Hey, ships can't collide!" << endl;
      }
    }
  } else if (column == column1) {
    for (int i = 0; i < 3; i++) {
      if (usr_board[row + i - 1][column - 1] == false) {
        usr_board[row + i - 1][column - 1] = true;
      } else if (usr_board[row + i][column] == true) {
        cout << "Hey, ships can't collide!" << endl;
      }
    }
  }
  cout << "  1 2 3 4 5 6 7 " << endl;
  for (int i = 0; i < 7; i++) {
    cout << i + 1 << " ";
    for (int j = 0; j < 7; j++) {
      cout << usr_board[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\n" << "Choose which row to place endpoint 1 of submarine (length 3): ";
  cin >> row;
  cout << "Choose which column to place endpoint 1 of submarine (length 3): ";
  cin >> column;
  cout << "Choose which row to place endpoint 2 of submarine (length 3): ";
  cin >> row1;
  cout << "Choose which column to place endpoint 2 of submarine (length 3): ";
  cin >> column1;
  cout << "\n";
  if (row == row1) {
    for (int i = 0; i < 3; i++) {
      if (usr_board[row - 1][column + i - 1] == false) {
        usr_board[row - 1][column + i - 1] = true;
      } else if (usr_board[row + i][column] == true) {
        cout << "Hey, ships can't collide!" << endl;
      }
    }
  } else if (column == column1) {
    for (int i = 0; i < 3; i++) {
      if (usr_board[row + i - 1][column - 1] == false) {
        usr_board[row + i - 1][column - 1] = true;
      } else if (usr_board[row + i][column] == true) {
        cout << "Hey, ships can't collide!" << endl;
      }
    }
  }
  cout << "  1 2 3 4 5 6 7 " << endl;
  for (int i = 0; i < 7; i++) {
    cout << i + 1 << " ";
    for (int j = 0; j < 7; j++) {
      cout << usr_board[i][j] << " ";
    }
    cout << "\n";
  }

  cout << "\n" << "Choose which row to place endpoint 1 of destroyer (length 2): ";
  cin >> row;
  cout << "Choose which column to place endpoint 1 of destroyer (length 2): ";
  cin >> column;
  cout << "Choose which row to place endpoint 2 of destroyer (length 2): ";
  cin >> row1;
  cout << "Choose which column to place endpoint 2 of destroyer (length 2): ";
  cin >> column1;
  cout << "\n";
  if (row == row1) {
    for (int i = 0; i < 2; i++) {
      if (usr_board[row - 1][column + i - 1] == false) {
        usr_board[row - 1][column + i - 1] = true;
      } else if (usr_board[row + i][column] == true) {
        cout << "Hey, ships can't collide!" << endl;
      }
    }
  } else if (column == column1) {
    for (int i = 0; i < 2; i++) {
      if (usr_board[row + i - 1][column - 1] == false) {
        usr_board[row + i - 1][column - 1] = true;
      } else if (usr_board[row + i][column] == true) {
        cout << "Hey, ships can't collide!" << endl;
      }
    }
  }
  cout << "  1 2 3 4 5 6 7 " << endl;
  for (int i = 0; i < 7; i++) {
    cout << i + 1 << " ";
    for (int j = 0; j < 7; j++) {
      cout << usr_board[i][j] << " ";
    }
    cout << "\n";
  }

  while (n_ships_left_usr > 0 || computer_ships_left > 0) {
    cout << "\n" << "These are your guesses:" << "\n" << endl;
    cout << "  1 2 3 4 5 6 7 " << endl;
    for (int i = 0; i < 7; i++) {
      cout << i + 1 << " ";
      for (int j = 0; j < 7; j++) {
        cout << usr_guess[i][j] << " ";
      }
      cout << "\n";
    }
    cout << "\n" << "These are the computer guesses:" << "\n" << endl;
    cout << "  1 2 3 4 5 6 7 " << endl;
    for (int i = 0; i < 7; i++) {
      cout << i + 1 << " ";
      for (int j = 0; j < 7; j++) {
        cout << computer_guess[i][j] << " ";
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
      continue;
    }

    if (usr_guess[row - 1][column - 1] == 'M') {
      cout << "\n" << endl;
      cout << "You already missed this in this spot!" << endl;
      continue;
    } else if (usr_guess[row - 1][column - 1] == 'X') {
      cout << "\n" << endl;
      cout << "You already hit this place!" << endl;
    } else if (board[row - 1][column - 1]) {
      board[row - 1][column - 1] = 0;
      usr_guess[row - 1][column - 1] = 'X';
      n_turns += 1;
      n_ships_left_usr -= 1;
      cout << "Hit! Turn number " << n_turns << " complete." << " There are " << n_ships_left_usr << " places to hit left." << endl;
      cout << "\n" << endl;

    } else {
      n_turns++;
      usr_guess[row - 1][column - 1] = 'M';
      cout << "Miss! Turn number " << n_turns << " complete." << endl;
      cout << "\n" << endl;
    }

    if (computer_ships_left <= 0) {
      cout << "Good game, I won!" << endl;
      break;

    } else if (n_ships_left_usr <= 0) {
      cout << "Good game, you won!" << endl;
      break;
    }

    cout << "Now I will guess your positions." << endl;
    // insert stuff here
    row = 1 + (rand() % 7);
    column = 1 + (rand() % 7);
    if (computer_guess[row - 1][column - 1] == 'M' ||
        computer_guess[row - 1][column - 1] == 'X') {
      row = 1 + (rand() % 7);
      column = 1 + (rand() % 7);
      continue;
    } else if (usr_board[row - 1][column - 1]) {

      usr_board[row - 1][column - 1] = 0;
      computer_guess[row - 1][column - 1] = 'X';
      n_turns += 1;
      n_ships_left_usr -= 1;
      cout << "Yay I hit you!" << endl;
      cout << "\n" << endl;

    } else {

      computer_guess[row - 1][column - 1] = 'M';
      cout << "\n"
           << "Oops I missed!" << endl;
    }
  }
  if (computer_ships_left <= 0) {
    cout << "Good game, I won!" << endl;
  } else if (n_ships_left_usr <= 0) {
    cout << "Good game, you won!" << endl;
  }
}
