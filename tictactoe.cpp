// This program allows the user to play a game of Tic Tac Toe
#include <iostream>

using namespace std;

class TicTacToe{

	public:
		TicTacToe();
		void play();

	private:
		char sigil[3];
		int board[9];
		int winner();
		bool isGameOver();
		void drawBoard();
		bool isMoveLegal(int row, int column);
};

TicTacToe::TicTacToe(){
	for(int i = 0; i < 9; i++){
		board[i] = 0;
	}
	sigil[0] = '.';
	sigil[1] = 'X';
	sigil[2] = 'O';
}

// checks for possible wins
int TicTacToe::winner(){

// CHECKS FOR HORIZONTAL WIN X
if(board[0] == 1 && board[1] == 1 && board[2] == 1){
	return 1;
}
// CHECKS FOR HORIZONTAL WIN FOR 0
if(board[0] == 2 && board[1] == 2 && board[2] == 2){
	return 2;
}
// CHECKS FOR HORIZONTAL WIN X
if(board[3] == 1 && board[4] == 1 && board[5] == 1){
	return 1;
}
// CHECKS FOR HORIZONTAL WIN O
if(board[3] == 2 && board[4] == 2 && board[5] == 2){
	return 2;
}
// CHECKS FOR HORIZONTAL WIN X
if(board[6] == 1 && board[7] == 1 && board[8] == 1){
	return 1;
}
// CHECKS FOR HORIZONTAL WIN O
if(board[6] == 2 && board[7] == 2 && board[8] == 2){
	return 2;
}
// CHECKS FOR VERTICAL WIN X
if(board[0] == 1 && board[3] == 1 && board[6] == 1){
	return 1;
}
// CHECKS FOR VERTICAL WIN 0
if(board[0] == 2 && board[3] == 2 && board[6] == 2){
	return 2;
}
// CHECKS FOR VERTICAL WIN X
if(board[1] == 1 && board[4] == 1 && board[7] == 1){
	return 1;
}
// CHECKS FOR VERTICAL WIN O
if(board[1] == 2 && board[4] == 2 && board[7] == 2){
	return 2;
}
// CHECKS FOR VERTICAL WIN X
if(board[2] == 1 && board[5] == 1 && board[8] == 1){
	return 1;
}
// CHECKS FOR VERTICAL WIN O
if(board[2] == 2 && board[5] == 2 && board[8] == 2){
	return 2;
}
// CHECKS FOR DIAGONAL WIN X
if(board[0] == 1 && board[4] == 1 && board[8] == 1){
	return 1;
}
// CHECKS FOR DIAGONAL WIN O
if(board[0] == 2 && board[4] == 2 && board[8] == 2){
	return 2;
}
// CHECKS FOR DIAGONAL WIN X
if(board[2] == 1 && board[4] == 1 && board[6] == 1){
	return 1;
}
// CHECKS FOR DIAGONAL WIN O
if(board[2] == 2 && board[4] == 2 && board[6] == 2){
	return 2;
}
	return 0;
	}

// allows players to make moves and outputs winner
void TicTacToe::play(){
	
	int player = 1;
	int row;
	int column;
	bool legalMove;
	
	drawBoard();
	
	while(!isGameOver()){
		cout << "Player " << player << "(" << sigil[player] << "), your move?";
		cin >> row >> column;
		legalMove = isMoveLegal(row, column);
	while(!legalMove){
		cout << "Player " << player << "(" << sigil[player] << "), your move?";
		cin >> row >> column;
		legalMove = isMoveLegal(row, column);
		}
		board[row * 3 + column] = player;
		drawBoard();
		player = 3 - player;
	}
	if(winner() == 1){
		cout << "Player one wins" << endl;
	} else if(winner() == 2){
		cout << "Player two wins" << endl;
	} else {
		cout << "Tie game" << endl;
	}
	
}

// checks if the game is over
bool TicTacToe::isGameOver(){
	if(winner() > 0){return true;}
	for(int i = 0; i < 9; i++){
	 if(board[i] == 0){
	 	return false;
	   }
	}
	return true;
}

// This draws the tic-tac-toe board
void TicTacToe::drawBoard(){

  cout << "  0 1 2" << endl;
  cout << "0" << " " << sigil[board[0]] << " " << sigil[board[1]] << " " << sigil[board[2]] << endl;
  cout << "1" << " " << sigil[board[3]] << " " << sigil[board[4]] << " " << sigil[board[5]] << endl;
  cout << "2" << " " << sigil[board[6]] << " " << sigil[board[7]] << " " << sigil[board[8]] << endl;

}
// checks if the move a player made is legal
bool TicTacToe::isMoveLegal(int row, int column){
	
	if(row < 0 || row > 2){
		return false;
	}
	if(column < 0 || column > 2){
		return false;
	}
	if(board[row * 3 + column] == 1|| board[row * 3 + column] == 2){
		return false;
	}
	return true;
}



int main(){


TicTacToe game;

game.play();

	return 0;

}
