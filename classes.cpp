#include "classes.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

Player next_player(Player p){
	if(p == Player::PLAYER_1){
		return Player::PLAYER_2;
	}else{
		return Player::PLAYER_1;
	}
}

GameState GameBoard::getGameState(){
	
	static vector<vector<pair<int, int>>> win_patterns = {
		{{0, 0}, {0, 1}, {0, 2}},
		{{1, 0}, {1, 1}, {1, 2}},
		{{2, 0}, {2, 1}, {2, 2}},
		{{0, 0}, {1, 0}, {2, 0}},
		{{0, 1}, {1, 1}, {2, 1}},
		{{0, 2}, {1, 2}, {2, 2}},
		{{0, 0}, {1, 1}, {2, 2}},
		{{2, 0}, {1, 1}, {0, 2}}
	};
	for(auto pattern : win_patterns){
		map<char, int> cnt;
		for(auto pos : pattern){
			cnt[board[pos.first][pos.second]]++;
		}
		for(auto i : cnt){
			if(i.first != '.' && i.second == 3){
				if(i.first == 'O'){
					return GameState::PLAYER_1_WIN;
				}else if(i.first == 'X'){
					return GameState::PLAYER_2_WIN;
				}
			}
		}
	}
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[i][j] != '.'){
				return GameState::NOT_ENDED;
			}
		}
	}
	return GameState::DRAW;
}

GameBoard::GameBoard(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			board[i][j] = '.';
		}
	}
}

bool GameBoard::update(Move mMove){
	if(board[mMove.row][mMove.col] != '.'){
		cerr << "Position Occupied! Please try again." << endl;
		return false;
	}
	board[mMove.row][mMove.col] = mMove.c;
	return true;
}

void GameBoard::show(void){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
Move::Move(){}
Move::Move(char mRow, char mCol, char mC) : row(mRow), col(mCol), c(mC){}
