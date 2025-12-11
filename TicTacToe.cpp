#include <iostream>
#include <ctime>
using namespace std;

void drawing(char*space);
void player_move(char player, char*space);
void computer_move(char computer, char*space);
bool checking(char*space, char player, char computer);
bool draw(char*space);

int main (){
    srand(time(NULL));
    char space[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player='X';
    char computer='O';
    bool running = true;

    drawing(space);
    while (running) {
        player_move(player, space);
        drawing(space);
        if (checking(space, player, computer) || draw(space)) break;

        computer_move(computer, space);
        drawing(space);
        if (checking(space, player, computer) || draw(space)) break;
    }

    cout << "Game Over!\n";
    return 0;
}

void drawing(char*space){
    cout<<"___________________\n";
    cout<<"  "<<space[0]<<"   |  "<<space[1]<<"   |  "<<space[2]<<"   \n"; 
    cout<<"______|______|_____\n";
    cout<<"  "<<space[3]<<"   |  "<<space[4]<<"   |  "<<space[5]<<"   \n";
    cout<<"______|______|_____\n";
    cout<<"  "<<space[6]<<"   |  "<<space[7]<<"   |  "<<space[8]<<"   \n"; 
}

void player_move(char player, char*space){
    int number;
    do {
        cout << "Enter your number (1-9): ";
        cin >> number;
        number--;
        if (number >= 0 && number < 9 && space[number] == ' ') {
            space[number] = player;
            break;
        } else {
            cout << "Invalid move! Try again.\n";
        }
    } while (true);
}

void computer_move(char computer, char*space){
    int number;
    do {
        number = rand() % 9;
    } while (space[number] != ' ');
    space[number] = computer;
}

bool checking(char*space, char player, char computer){
    int win_combo[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8},
        {0,3,6}, {1,4,7}, {2,5,8},
        {0,4,8}, {2,4,6}
    };
    for (int i = 0; i < 8; i++) {
        int a = win_combo[i][0];
        int b = win_combo[i][1];
        int c = win_combo[i][2];
        if (space[a] != ' ' && space[a] == space[b] && space[b] == space[c]) {
            if (space[a] == player) cout << "You WIN!\n";
            else cout << "You LOSE!\n";
            return true;
        }
    }
    return false;
}

bool draw(char*space){
    for(int i = 0; i < 9; i++){
        if (space[i] == ' ') return false;
    }
    cout << "DRAW!\n";
    return true;
}
