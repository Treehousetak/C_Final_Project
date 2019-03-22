#include<iostream>
#include<iomanip>
#include<string>
#include"classes.h"

using namespace std;

//********************************************************************
//This array stores the memory of each tile in the tic tac toe board *
//Each number represents a tile in the board                         *
//Each number then gets replaces by either an X or an O              *
//********************************************************************

char b[10] = { '0', '1', '2' , '3', '4', '5', '6' , '7' , '8', '9'};


//***************************************************************
//The winner integer represents the state the game is ended on  *
//A 0 means the game is ongoing                                 *
//A 1 means that player 1 has won the game                      *
//A 2 means that player 2 has won the game                      *
//A -1 means that the game was a tie                            *
//***************************************************************
int winner = 0;


//game_board() outputs the board
//game_winner() checks if anyone has won the game or if the game is a tie
void game_board();
int game_winner();

int main()
{
	
	//The players class helps to choose the player's name
	players OX;
	
	
	srand((unsigned int)time(NULL));

	//The game_state bool determines if the game is running or not
	//The turn bool determines who's turn it is. True is player 1 and false is player 2. 
	bool game_state = true;
	bool turn = true;
	
	//Ch integer is short for choice. Ch determines which tile the player chooses.
	int ch;
	//The ti integer is the turn timer
	int ti = 0;
	//The inputs array is used to store memory of which tile has been used
	int inputs[10];

	//Player names
	string player1;
	string player2;
	

	//This lets the user(s) choose their names
	cout << "Welcome to the Tic Tac Toe Game, user! \n";
	cout << "Player 1 is X and Player 2 is O \n";
	cout << "Player 1's name? \n";
	cin >> player1;
	OX.setplayer1(player1);
	player1 = OX.getplayer1();
	cout << "Player 2's name? (enter \"bot\", case sensitive, to face off against a bot!) \n";
	cin >> player2;
	OX.setplayer2(player2);
	player2 = OX.getplayer2();


	//The main part of the code
	while (game_state == true)
	{
		//Declaration of turns
		if (turn == true)
			cout << player1 << "'s Turn!" << endl << endl;
		else
			cout << player2 << "'s Turn!" << endl << endl;


		//The next two if loop determines if the game is running a 1 or 2 player game 
		if (turn == true || turn == false && player2 != "bot")
		{
		game_board();
		cin >> ch;

		//Checks if the tile is used
		while (ch == inputs[ch])
		{
			cout << "That space is already filled! \n";
			cin >> ch;
		}
		
		//Stores memory of which tile was used in the inputs array
		inputs[ch] = { ch };
	
		}
		

		//The if loop that is used for the bot
		if (turn == false && player2 == "bot")
		{ch = rand() % 9;
		//Checks if tile was used and then stores memory of which tile was used by the bot
		while (ch == inputs[ch])
		{
			ch = rand() % 9;
		}
		inputs[ch] = { ch };
		}
			

		//These while loops are used to catch wrong inputs
		while (ch > 8 || ch < 0)
		{
			cout << "Please input 0-8, please! \n";
			cin.clear();
			cin.ignore();
			cin >> ch;
			
			while (cin.fail())
			{
				cin.clear();
				cin.ignore();
				cout << "Please input 0-8, please! \n";
				cin >> ch;
			}
			while (ch == inputs[ch])
			{
				cout << "That space is already filled! \n";
				cin >> ch;
			}
			ch == inputs[ch];
		}
		
		while(cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "Please input 0-8, please! \n";
			cin >> ch;
			while (ch == inputs[ch])
			{
				cout << "That space is already filled! \n";
				cin >> ch;
			}
			ch == inputs[ch];
			
		}


		//*********************************************************************************
		//These if loops are used to replace the numbered tiles with either an X or an O  *
		//It determines if it is an X or an O with the use of the turn bool               *
		//*********************************************************************************
		if (ch == 0 && b[0] == '0' && turn == true)
		{
			b[0] = 'X';
		}
		else if(ch == 0 && b[0] == '0' && turn == false)
		{
			b[0] = 'O';
		}

		
		
		else if (ch == 1 && b[1] == '1' && turn == true)
		{
			b[1] = 'X';
		}
		else if (ch == 1 && b[1] == '1' && turn == false)
		{
			b[1] = 'O';
		}
		
		
		else if (ch == 2 && b[2] == '2' && turn == true)
		{
			b[2] = 'X';
		}
		else if (ch == 2 && b[2] == '2' && turn == false)
		{
			b[2] = 'O';
		}


		
		else if (ch == 3 && b[3] == '3' && turn == true)
		{
			b[3] = 'X';
		}
		else if (ch == 3 && b[3] == '3' && turn == false)
		{
			b[3] = 'O';
		}

		
		else if (ch == 4 && b[4] == '4' && turn == true)
		{
			b[4] = 'X';
		}
		else if (ch == 4 && b[4] == '4' && turn == false)
		{
			b[4] = 'O';
		}

		else if (ch == 5 && b[5] == '5' && turn == true)
		{
			b[5] = 'X';
		}
		else if (ch == 5 && b[5] == '5' && turn == false)
		{
			b[5] = 'O';
		}

		else if (ch == 6 && b[6] == '6' && turn == true)
		{
			b[6] = 'X';
		}
		else if (ch == 6 && b[6] == '6' && turn == false)
		{
			b[6] = 'O';
		}

		else if (ch == 7 && b[7] == '7' && turn == true)
		{
			b[7] = 'X';
		}
		else if (ch == 7 && b[7] == '7' && turn == false)
		{
			b[7] = 'O';
		}

		else if (ch == 8 && b[8] == '8' && turn == true)
		{
			b[8] = 'X';
		}
		else if (ch == 8 && b[8] == '8' && turn == false)
		{
			b[8] = 'O';
		}
		
		//Displays board after bot has made his turn
		if (turn == false && player2 == "bot")
		{game_board();}
		
		
		//Switches turns by changing the turn bool
		if (turn == true)
		{
			turn = false;
		}
		else 
		{
			turn = true;
		}

		//Turn timer accumulation
		ti++;
		
		//Trying to determine if anyone won or if the game was tied by the end of the turn
		game_winner();
		
		//***************************************************************************************
		//It then returns a value of -1, 1, or 2 if something happened by the end of the turn   *
		//If the game is won or tied then the code shuts down                                   *
		//***************************************************************************************
		if (winner == -1)
		{
			cout << "Game is a tie!" << endl;
			game_board();
			cout << "This game took " << ti << " turns! \n";
			system("pause");
			return 0;

		}
		if (winner == 1)
		{
			cout << player1 << " Wins!" << endl;
			game_board();
			cout << "This game took " << ti << " turns! \n";
			system("pause");
			return 0;
		
		}
		if (winner == 2)
		{
			cout <<  player2 << " Wins!" << endl;
			game_board();
			cout << "This game took " << ti << " turns! \n";
			system("pause");
			return 0;
		
		}

		
	}
	system("pause");
	return 0;
}


//This draws the board using the b array
void game_board()
{
	cout << " " << b[0] << " | " << b[1] << " | " << b[2] << endl;
	cout << "___|___|___" << endl;
	cout << " " << b[3] << " | " << b[4] << " | " << b[5] << endl;
	cout << "___|___|___" << endl;
	cout << " " << b[6] << " | " << b[7] << " | " << b[8] << endl;
	cout << "   |   |   " << endl;
}

//*****************************************************************
//This determines the outcome of the game                         *
//It does this by checking different combinations of the b array  *
//If there are no combinations available then it ends in a tie    *
//*****************************************************************
int game_winner()
{
	if (b[0] == b[1] && b[1] == b[2])
	{
		if (b[0, 1, 2] = 'X')
		{
			winner = 1;
			return winner;
		}
		if (b[0, 1, 2] = 'O')
		{
			winner = 2;
			return winner;
		}
		
	}
	else if (b[3] == b[4] && b[4] == b[5])
	{
		if (b[3, 4, 5] = 'X')
		{
			winner = 1;
			return winner;
		}
		if (b[3, 4, 5] = 'O')
		{
			winner = 2;
			return winner;
		}

	}
	else if (b[6] == b[7] && b[7] == b[8])
	{
		if (b[6, 7, 8] = 'X')
		{
			winner = 1;
			return winner;
		}
		if (b[6, 7, 8] = 'O')
		{
			winner = 2;
			return winner;
		}

	}
	else if (b[0] == b[3] && b[3] == b[6])
	{
		if (b[0, 3, 6] = 'X')
		{
			winner = 1;
			return winner;
		}
		if (b[0, 3, 6] = 'O')
		{
			winner = 2;
			return winner;
		}

	}
	else if (b[1] == b[4] && b[4] == b[7])
	{
		if (b[1, 4, 7] = 'X')
		{
			winner = 1;
			return winner;
		}
		if (b[1, 4, 7] = 'O')
		{
			winner = 2;
			return winner;
		}

	}
	else if (b[2] == b[5] && b[5] == b[8])
	{
		if (b[2, 5, 8] = 'X')
		{
			winner = 1;
			return winner;
		}
		if (b[2, 5, 8] = 'O')
		{
			winner = 2;
			return winner;
		}

	}
	else if (b[0] == b[4] && b[4] == b[8])
	{
		if (b[0, 4, 8] = 'X')
		{
			winner = 1;
			return winner;
		}
		if (b[0, 4, 8] = 'O')
		{
			winner = 2;
			return winner;
		}

	}
	else if (b[2] == b[4] && b[4] == b[6])
	{
		if (b[2, 4, 6] = 'X')
		{
			winner = 1;
			return winner;
		}
		if (b[2, 4, 6] = 'O')
		{
			winner = 2;
			return winner;
		}

	}

	//If there are no combinations available then it ends in a tie 
	else if (b[0] != '0' && b[1] != '1' && b[2] != '2' && b[4] != '4' && b[5] != '5' && b[5] != '5' && b[6] != '6' && b[7] != '7' && b[8] != '8')
	{
		winner = -1;
		return winner;
	}
	

}