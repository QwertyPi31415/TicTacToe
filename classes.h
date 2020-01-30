#include <array>

#ifndef CLASSES_H
#define CLASSES_H

enum class GameState{
	PLAYER_1_WIN,
	PLAYER_2_WIN,
	DRAW,
	NOT_ENDED
};

// TODO: Would it be better to use pure integer? 
// If the count of player increases, It is difficult to manage

enum class Player{
	PLAYER_1,
	PLAYER_2
};

enum class PlayerType{
	Computer,
	Human
};

struct Move{
	char row, col, c;
	Move();
	Move(char mRow, char mCol, char mC);
};

class GameBoard{
	public:
		std::array<std::array<char, 3>, 3> board;
		GameBoard();
		GameState getGameState(void);
		bool update(Move mMove);
		void show(void);
};

Player next_player(Player p);
void update(GameBoard & mGameBoard, Move mMove);
#endif
