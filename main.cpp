#include <bits/stdc++.h>
#include "player1.h"
#include "player2.h"
using namespace std;

GameState mGameState = GameState::NOT_ENDED;
GameBoard mGameBoard;
Player mPlayer = Player::PLAYER_1;
map<Player, string> getPlayerName;
map<Player, PlayerType> getPlayerType;
bool mMoveSuccess = true;
// https://stackoverflow.com/questions/15891781/how-to-call-on-a-function-found-on-another-file
// Remember this
int main(){
	/* default */
	getPlayerName[Player::PLAYER_1] = "Player 1";
	getPlayerName[Player::PLAYER_2] = "Player 2";
	getPlayerType[Player::PLAYER_1] = PlayerType::Human;
	getPlayerType[Player::PLAYER_2] = PlayerType::Computer;
	while(mGameState == GameState::NOT_ENDED){
		Move mMove;
		cout << getPlayerName[mPlayer] << "'s turn." << endl;
		mMove = player_move(mGameBoard, getPlayerName[Player]);
		mMoveSuccess = mGameBoard.update(mMove);
		if(mMoveSuccess == 1){
			mGameState = mGameBoard.getGameState();
			mPlayer = next_player(mPlayer);
		}else{
			std::chrono::milliseconds dura(100);
			std::this_thread::sleep_for(dura);
			cout << endl;
		}
	}
	if(mGameState == GameState::PLAYER_1_WIN){
		cout << getPlayerName[Player::PLAYER_1] << " wins!" << endl;
	}else if(mGameState == GameState::PLAYER_2_WIN){
		cout << getPlayerName[Player::PLAYER_2] << " wins!" << endl;
	}else{
		cerr << "Draw!" << endl;
	}
}
