#include "player1.h"
#include <iostream>
using namespace std;
Move player1_move(GameBoard mGameBoard){
	mGameBoard.show();
	int row, col;
	cin >> row >> col;
	return Move(row, col, 'O');
}
