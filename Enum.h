//Jennie Lu j.q.lu@wustl.edu
//Enum.h
//Contains enumerations for the board,pieces, the 3x3 middle square coordinates, results and arguments

#pragma once

enum board {
	width = 5, length = 5
};
enum pieces {
	O, X, waiting, empty
};
enum mid_coordinates {
	leftx = 1, midx = 2, rightx = 3, highy = 3, midy = 2, lowy = 1
};
enum board_coordinates {
	toprightc = 16,topmid = 17, topleftc=18, 
	midright = 11 , midmid = 12, midleft = 13,
	botrightc = 6, botmid = 7, botleftc=8

};

enum results {
	success, quit, fail_to_input, wrong_coordinates, occupied, game_draw, error, wrong_game
};

enum arguments {
	proname, inputname, command_arg, now =1,arg_wrong
};