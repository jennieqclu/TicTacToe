Lab 2
Jennie Lu, j.q.lu@wustl.edu
ReadMe.txt
the answers to lab questions

Warnings:
Warning	C4806	'!=': unsafe operation: no value of type 'bool' promoted to type 'pieces' can equal the given constant	
Warning	C4715	'TicTacToeGame::turn': not all control paths return a value
Error	C4700	uninitialized local variable 'x' used	
Error	C4700	uninitialized local variable 'y' used	
Warning	C6001	Using uninitialized memory 'x'.			
Warning	C6001	Using uninitialized memory 'y'.	

Case 1: Draw game

H:\ARep\lab3-jennieqclu\Lab3\Debug>Lab3.exe TicTacToe

---------------------------
4
3
2
1
0
 01234

---------------------------

2,2

---------------------------
4
3
2  O
1
0
 01234

---------------------------


Player O: 2,2

1,2

---------------------------
4
3
2 XO
1
0
 01234

---------------------------


Player X: 1,2

3,3

---------------------------
4
3   O
2 XO
1
0
 01234

---------------------------


Player O: 2,2   3,3

2,3

---------------------------
4
3  XO
2 XO
1
0
 01234

---------------------------


Player X: 1,2   2,3

1,3

---------------------------
4
3 OXO
2 XO
1
0
 01234

---------------------------


Player O: 2,2   1,3   3,3

3,1

---------------------------
4
3 OXO
2 XO
1   X
0
 01234

---------------------------


Player X: 3,1   1,2   2,3

3,2

---------------------------
4
3 OXO
2 XOO
1   X
0
 01234

---------------------------


Player O: 2,2   3,2   1,3   3,3

1,1

---------------------------
4
3 OXO
2 XOO
1 X X
0
 01234

---------------------------


Player X: 1,1   3,1   1,2   2,3

2,1

---------------------------
4
3 OXO
2 XOO
1 XOX
0
 01234

---------------------------


Player O: 2,1   2,2   3,2   1,3   3,3

9 turns have been played
it's a draw





Case 2: O wins:

H:\ARep\lab3-jennieqclu\Lab3\Debug>Lab3.exe TicTacToe

---------------------------
4
3
2
1
0
 01234

---------------------------

2,2

---------------------------
4
3
2  O
1
0
 01234

---------------------------


Player O: 2,2

1
1,1

---------------------------
4
3
2  O
1 X
0
 01234

---------------------------


Player X: 1,1

2,1

---------------------------
4
3
2  O
1 XO
0
 01234

---------------------------


Player O: 2,1   2,2

1,3

---------------------------
4
3 X
2  O
1 XO
0
 01234

---------------------------


Player X: 1,1   1,3

2,3

---------------------------
4
3 XO
2  O
1 XO
0
 01234

---------------------------


Player O: 2,1   2,2   2,3

O has won




Case 3: X has won:

H:\ARep\lab3-jennieqclu\Lab3\Debug>Lab3.exe TicTacToe

---------------------------
4
3
2
1
0
 01234

---------------------------

1,1

---------------------------
4
3
2
1 O
0
 01234

---------------------------


Player O: 1,1

2,2

---------------------------
4
3
2  X
1 O
0
 01234

---------------------------


Player X: 2,2

3,1

---------------------------
4
3
2  X
1 O O
0
 01234

---------------------------


Player O: 1,1   3,1

2,1

---------------------------
4
3
2  X
1 OXO
0
 01234

---------------------------


Player X: 2,1   2,2

1,2

---------------------------
4
3
2 OX
1 OXO
0
 01234

---------------------------


Player O: 1,1   3,1   1,2

2,3

---------------------------
4
3  X
2 OX
1 OXO
0
 01234

---------------------------


Player X: 2,1   2,2   2,3

X has won






Case 4: O quits

H:\ARep\lab3-jennieqclu\Lab3\Debug>Lab3.exe TicTacToe

---------------------------
4
3
2
1
0
 01234

---------------------------

1,1

---------------------------
4
3
2
1 O
0
 01234

---------------------------


Player O: 1,1

2,2

---------------------------
4
3
2  X
1 O
0
 01234

---------------------------


Player X: 2,2

quit
O has quit the game
2 turns have been played
Game Over




Case 5: Wrong Game

H:\ARep\lab3-jennieqclu\Lab3\Debug>Lab3.exe NotAGame
usage : Lab3.exe <name_of_game>

H:\ARep\lab3-jennieqclu\Lab3\Debug>echo %errorlevel%
7



Case 6: no capitals on "TicTacToe"

H:\ARep\lab3-jennieqclu\Lab3\Debug>Lab3.exe tictactoe
usage : Lab3.exe <name_of_game>

H:\ARep\lab3-jennieqclu\Lab3\Debug>echo %errorlevel%
7



Case 7: Combination of wrong/occupied coordinates and diagonal win for O

H:\ARep\lab3-jennieqclu\Lab3\Debug>Lab3.exe TicTacToe

---------------------------
4
3
2
1
0
 01234

---------------------------

2,2

---------------------------
4
3
2  O
1
0
 01234

---------------------------


Player O: 2,2

4,4
Out of bounds coordinates, try again
3,3

---------------------------
4
3   X
2  O
1
0
 01234

---------------------------


Player X: 3,3

3,3
Coordinates are occupied, try again
3,1

---------------------------
4
3   X
2  O
1   O
0
 01234

---------------------------


Player O: 3,1   2,2

2,3

---------------------------
4
3  XX
2  O
1   O
0
 01234

---------------------------


Player X: 2,3   3,3

1,3

---------------------------
4
3 OXX
2  O
1   O
0
 01234

---------------------------


Player O: 3,1   2,2   1,3

O has won





Case 8: X quits the game

H:\ARep\lab3-jennieqclu\Lab3\Debug>Lab3.exe TicTacToe

---------------------------
4
3
2
1
0
 01234

---------------------------

2,2

---------------------------
4
3
2  O
1
0
 01234

---------------------------


Player O: 2,2

quit
X has quit the game
1 turns have been played
Game Over


