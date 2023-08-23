//Jennie Lu j.q.lu@wustl.edu
//TicTacToe.cpp
//contains definition of TicTacToeGame class methods

//constructor of the class which makes the middle 3x3 board to be waiting and other parts be empty
//done() method which checks if the the X or O is in a row(diagonal,horizontal,vertical)
//draw() method which checks if the game ends in a draw. (No wins and no more moves on the board)
//prompt(unsigned int &x, unsigned int &y) method that takes the user input and uses it to place the X or O on the board
//turn() method keeps track of whos turn it is and which coordinates the X or O has played
//play() method checks if the game has a clear winner, a draw, or someone has quit and prints out the appropriate message
//ostream operator overload prints out the board and the Xs or Os
//int usagemess(char* name) prints out the error message with the correct way of inputing the game


#include "TicTacToe.h"
#include "Enum.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

TicTacToeGame::TicTacToeGame() : board{} {
	for (int i = width - 1; i >= 0; --i) {
		for (int j = 0; j < length; ++j) {
			board[width * i + j] = pieces::empty;
		}
	}

	for (int i = lowy; i <= highy; ++i) { //y
		for (int j = leftx; j <= rightx; ++j) { //x
			board[width * i + j] = pieces::waiting;
		}
	}
};

bool TicTacToeGame::done() {
	if (board[toprightc] == board[topmid]&& board[topmid] == board[topleftc] && board[topleftc] != waiting) {
		return true;
	}
	if (board[midright] == board[midmid]&& board[midmid] == board[midleft] && board[midleft] != waiting) {
		return true;
	}
	if (board[botrightc] == board[botmid] && board[botmid] == board[botleftc] && board[botleftc] != waiting) {
		return true;
	}
	if (board[toprightc] == board[midright] && board[midright] == board[botrightc] && board[botrightc] != waiting) {
		return true;
	}
	if (board[midmid] == board[topmid] && board[topmid] == board[botmid] && board[botmid] != waiting) {
		return true;
	}
	if (board[midleft] == board[botleftc] && board[botleftc] == board[topleftc] && board[topleftc] != waiting) {
		return true;
	}
	if (board[toprightc] == board[midmid] && board[midmid] == board[botleftc] && board[botleftc] != waiting) {
		return true;
	}
	if (board[botrightc] == board[midmid] && board[midmid] == board[topleftc] && board[topleftc] != waiting) {
		return true;
	}
	else {
		return false;
	}
}

bool TicTacToeGame::draw() {
	if (done() == true) {
		return false;
	}
	int count = 0;
	for (int i = lowy; i <= highy; ++i) { //y
		for (int j = leftx; j <= rightx; ++j) { //x
			if (board[width * j + i] != waiting) {
				++count;
			}
		}
	}
	if (count == 9) {
		return true;
	}
	else {
		return false;
	}
}

int TicTacToeGame::prompt(unsigned int &x, unsigned int &y) {
	string command;
	cin >> command;
	if (command == "quit") {
		return quit;
	}
	if (command[now] == ',') {
		command.replace(now, now, " ");
	}
	istringstream iss (command);
	if (iss >> x && iss >> y) {
		return success;
	}
	prompt(x, y);
	return error;
}

int TicTacToeGame::turn() {
	unsigned int x, y;

	if (prompt(x, y) == quit) {
		return quit;
	}

	int place = width * y + x;

	if (x >= leftx && x <= rightx && y <= highy && y >= lowy) {
		if (board[place] == waiting) {
			if (this->count % 2 == 0) {
				board[place] = O;
				cout << *this;
				cout << "\nPlayer O: ";
				for (int i = lowy; i <= highy; ++i) { //y
					for (int j = leftx; j <= rightx; ++j) { //x
						if (board[width*i+j] == O) {
							cout << j << "," << i<<"   ";
						}
					}
				}
			}
			else {
				board[place] = X;
				cout << *this;
				cout << "\nPlayer X: ";

				for (int i = lowy; i <= highy; ++i) { //y
					for (int j = leftx; j <= rightx; ++j) { //x
						if (board[width * i + j] == X) {
							cout << j << "," << i<<"   ";
						}
					}
				}
			}
			cout << "\n";
			++this->count;
			cout << endl;
			return success;
		}
		else {
			cout << "Coordinates are occupied, try again" << endl;
			return occupied;
		}
	}
	else {
		cout << "Out of bounds coordinates, try again" << endl;
		return wrong_coordinates;
	}
	turn();
	return error;
}

int TicTacToeGame::play() {
	if (done()) {
		if (this->count % 2 == 0) {
			cout << "X has won"<<endl;
		}
		else {
			cout << "O has won" << endl;
		}
		return success;
	}
	if (draw()) {
		cout << this->count << " turns have been played\nit's a draw" << endl;
		return game_draw;
	}
	if (turn() == quit) {
		if (this->count % 2 == 0) {
			cout << "O has quit the game" << endl;
		}
		else {
			cout << "X has quit the game" << endl;
		}
		cout << this->count << " turns have been played\nGame Over" << endl;
		return quit;
	}
	play();
	return error;
}

ostream& operator << (ostream& ost, const TicTacToeGame & Game) {

	cout << "\n---------------------------\n";
	for (int i = length-1; i >=0; --i) {
		cout << i;
		for (int j = 0; j < length; ++j) {
			if (Game.board[width * i + j] == X) {
				cout << "X";
			}
			else if (Game.board[width * i + j] == O) {
				cout << "O";
			}
			else {
				cout << " ";
			}
			
		}
		cout << endl;

	}
	cout << " 01234 \n";
	cout << "\n---------------------------\n" << endl;


	return ost;

};

int usagemess(char* name) {
	cout << "usage : " << name << " <name_of_game> " << endl;
	return arg_wrong;
}

