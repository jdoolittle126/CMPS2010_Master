/*
 * Jonathan Doolittle
 * CMPS 2010
 * Professor Toothman
 * Homework #3
 *
 * A simple command-line game of tic-tac-toe
 */


#include <iostream>
#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void draw_board(){

	std::cout << "\n *************\n";
	for(int i = 0; i < BOARD_SIZE; i++){
		std::cout << " * ";
		for(int j = 0; j < BOARD_SIZE; j++){
			std::cout << board[i][j] << " * ";
		}
		std::cout << "\n *************\n";
	}
}

bool check_win(bool p1) {
	char c;
	if(p1) c = 'X';
	else c = 'O';

	//Hardcoded for wins :| sorry
	for(int i = 0; i < BOARD_SIZE; i++) {
		if(board[i][0] == c && board[i][1] == c  && board[i][2] == c) return true;
		if(board[0][i] == c && board[1][i] == c  && board[2][i] == c) return true;
	}
	if(board[1][1] == c) {
		if(board[0][0] == c && board[2][2] == c) return true;
		if(board[2][0] == c && board[0][2] == c) return true;
	}
	return false;
}

bool check_tie() {
	for(int i = 0; i < BOARD_SIZE; i++){
		for(int j = 0; j < BOARD_SIZE; j++){
			if(board[i][j] != ' ') return false;
		}
	}
	return true;
}

void play_round(int r, bool p1) {
	char c;
	int x, y;

	do {
		std::cout << "ROUND " << r << "!\n";
		draw_board();
		std::cout << "\nEnter row and col for Player ";
		if(p1) {
			std::cout << "1 (X)";
			c = 'X';
		}
		else {
			std::cout << "2 (O)";
			c = 'O';
		}
		std::cout << ": ";
		std::cin >> x >> y;
		if(board[x][y] != ' ') std::cout << "\nInvalid Slot!\n";
	} while(board[x][y] != ' ');
	board[x][y] = c;

}

int main(int argc, char ** argv) {
	int round = 1;
	bool player = true, win = false, tie = false;

	while(!win && !tie) {
		std::cout << "----------------------------------------\n";
		play_round(round, player);
		win = check_win(player);
		tie = check_tie();
		if(!win && !tie){
			player = !player;
			if(player) round++;
		}
	}
	draw_board();
	if(tie) {
		std::cout << "\nThe game ends in a tie!";
	} else {
		if(player) std::cout << "\nPlayer 1 Wins!";
		else std::cout << "\nPlayer 2 Wins!";
	}


}
