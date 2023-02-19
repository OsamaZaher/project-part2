#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

const int ROW = 10;
const int COL = 10;

char board[ROW][COL];
int playerX, playerY;
int alienX, alienY;

void initBoard() {
for (int i = 0; i < ROW; i++) {
for (int j = 0; j < COL; j++) {
board[i][j] = '-';
}
}
playerX = ROW / 2;
playerY = COL / 2;
board[playerX][playerY] = 'P';
alienX = (ROW / 2) - 1;
alienY = (COL / 2) - 1;
board[alienX][alienY] = 'A';
}

void displayBoard() {
for (int i = 0; i < ROW; i++) {
for (int j = 0; j < COL; j++) {
cout << board[i][j] << " ";
}
cout << endl;
}
}

void movePlayer(char move) {
board[playerX][playerY] = '-';
if (move == 'w') {
playerX--;
} else if (move == 'a') {
playerY--;
} else if (move == 's') {
playerX++;
} else if (move == 'd') {
playerY++;
}
board[playerX][playerY] = 'P';
}

bool isWon() {
if (playerX == alienX && playerY == alienY) {
return true;
}
return false;
}

void saveGame() {
ofstream file;
file.open("game.txt");
file << playerX << " " << playerY << endl;
file << alienX << " " << alienY << endl;
for (int i = 0; i < ROW; i++) {
for (int j = 0; j < COL; j++) {
file << board[i][j] << " ";
}
file << endl;
}
file.close();
}

void loadGame() {
ifstream file;
file.open("game.txt");
file >> playerX >> playerY;
file >> alienX >> alienY;
for (int i = 0; i < ROW; i++) {
for (int j = 0; j < COL; j++) {
file >> board[i][j];
}
}
file.close();
}

int main() {
char move;
bool won = false;
initBoard();
displayBoard();
while (!won) {
cout << "Enter your move (w, a, s, d): ";
cin >> move;
movePlayer(move);
won = isWon();
displayBoard();
if (won) {
cout << "Congratulations! You have captured the alien." << endl;
}
} 
}
