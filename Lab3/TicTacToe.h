//Jennie Lu j.q.lu@wustl.edu
//TicTacToe.h
//contains TicTacToeGame class with its private variables and public declartions methods
//also has declarations for the ostream overload and error message 


#pragma once
#include <iostream>
#include <iomanip>
#include "Enum.h"

class TicTacToeGame {
private:
	pieces board[width * length];
	friend std::ostream& operator << (std::ostream& ost, const TicTacToeGame& Game);
	int count=0;

public:
	TicTacToeGame();
	bool done();
	bool draw();
	int prompt(unsigned int& x, unsigned int& y);
	int turn();
	int play();
};

int usagemess(char* name);
std::ostream& operator << (std::ostream& ost, const TicTacToeGame& Game);
