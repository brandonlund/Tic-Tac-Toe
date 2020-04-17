// tictactoe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void make_move(char board[3][3], bool turn, char &player);
void draw_board(char board[3][3]);
void check_win(char board[3][3], int &winner);

int main()
{
	char board[3][3] = { 0 
					   /*{ 'X', 'X', 'X' },
						 { 'X', 'X', 'X' }, 
						 { 'X', 'X', 'X' }*/ };
	char player = 0;
	bool turn = 1;
	int winner = 0; // 0 no winner, 1 winner, 2 tie

	draw_board(board);

	while (!winner)
	{
		turn = !turn;
		make_move(board, turn, player);
		draw_board(board);
		check_win(board, winner);
	}

	if ( winner == 1 )
	{
		cout << "Congrats, Player " << player << "! You've won!!" << endl;
	}
	else
	{
		cout << "Better luck next time! It was a tie!" << endl;
	}

	return 0;
}

void make_move(char board[3][3], bool turn, char &player)
{
	int row, col;

	if (!turn)
	{
		player = 'X';
	}
	else
	{
		player = 'O';
	}

	cout << "Player " << player << ", Please enter your row: ";
	cin >> row;
	cout << "Player " << player << ", Please enter your column: ";
	cin >> col;

	row -= 1;
	col -= 1;

	while (board[row][col] == 'X' || board[row][col] == 'O')
	{
		cout << "Coordinate taken. Please choose new coordinates." << endl;

		cout << "Player " << player << ", Please enter your row: ";
		cin >> row;
		cout << "Player " << player << ", Please enter your column: ";
		cin >> col;

		row -= 1;
		col -= 1;
	}

	board[row][col] = player;
}

void draw_board(char board[3][3])
{
	int r, c;

	system("cls");

	cout << endl;
	cout << "    1   2   3" << endl;

	for (r = 0; r < 3; r++)
	{
		cout << " ";
		for (c = 0; c < 3; c++)
		{
			if (c == 0)
			{
				cout << " " << r + 1 << " ";
			}

			cout << board[r][c];

			if ( c < 2)
			{
				cout << " | ";
			}
		}
		if (r < 2)
		{
			cout << endl << " " << "  -----------" << endl;
		}
	}

	cout << endl << endl;

}
void check_win(char board[3][3], int & winner)
{
	if (   // ROWS X
		   (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
		|| (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
		|| (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
		   // COLS X
		|| (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
		|| (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
		|| (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
		   // DIAGS X
		|| (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
		|| (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')
		   // ROWS O
		|| (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
		|| (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
		|| (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
		   // COLS O
		|| (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
		|| (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
		|| (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
		   // DIAGS O
		|| (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
		|| (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')
		)
	{
		winner = 1;
	}
	else if ((board[0][0] == 'X' || board[0][0] == 'O')
			&& (board[0][1] == 'X' || board[0][1] == 'O')
			&& (board[0][2] == 'X' || board[0][2] == 'O')
			&& (board[1][0] == 'X' || board[1][0] == 'O')
			&& (board[1][1] == 'X' || board[1][1] == 'O')
			&& (board[1][2] == 'X' || board[1][2] == 'O')
			&& (board[2][0] == 'X' || board[2][0] == 'O')
			&& (board[2][1] == 'X' || board[2][1] == 'O')
			&& (board[2][2] == 'X' || board[2][2] == 'O')
		)
	{
		winner = 2;
	}
	else
	{
		winner = 0;
	}
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
