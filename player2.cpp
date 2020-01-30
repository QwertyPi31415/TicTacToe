#include "player2.h"
#include <bits/stdc++.h>
using namespace std;

Move player2_move(GameBoard mGameBoard){
	std::chrono::milliseconds dura(1000);
	std::this_thread::sleep_for(dura);
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(mGameBoard.board[i][j] == '.'){
				return Move(i, j, 'X');
			}
		}
	}
	return Move(-1, -1, 'X');
}
