// Alix Sampford

#define _CRTDBG_MAP_ALLOC  // memory leak detection.
#include <stdlib.h>		   // memory leak detection.
#include <crtdbg.h>		   // memory leak detection.
#include <ctime>		   // Used for the random function.
#include <iostream>
#include <fstream>
#include <vector>


#include "CSquareFactory.h"
#include "CSquare.h"
#include "CPlayer.h"
#include "CProperty.h"

typedef vector<unique_ptr<CSquare>> myVector; // TODO ask about this

using namespace std;


// Returns a random number in the range 1 .. 6
// Note that I am using casting to convert one data type to another 
int Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * SIDE_OF_DICE + 1);
}

void MovePlayer(shared_ptr<CPlayer> player, int roll, int boardSize)
{
	for (int j = 0; j < roll; j++) // move the player on square at a time
	{
		player->mPlayerPosition++; // move the player to the next square

		if (player->mPlayerPosition == boardSize) // if at the end of the vector list, loop back to start of list, this creates the effect of being on a board.
		{
			player->mPlayerPosition = 0;
			// pass go and collect 200
			player->mMoney += PASS_GO_AMOUNT;
			cout << *player << GO_MESSAGE << POUND << PASS_GO_AMOUNT << endl;
		}

	}
}

void PlayerLanding(shared_ptr<CPlayer> playerWhoLanded, CSquare& square) // TODO override each class function for landing on a square in each of the derived classes.
{
	square.OnLanding(playerWhoLanded);
}

int main()
{
	{
		myVector vSquareList;
		ifstream infile;

		infile.open("monopoly.txt");
		if (infile.is_open())
		{
			while (!infile.eof())
			{

				int type = 0;
				
				infile >> type;
				if (type != 0)
				{
					//cout << "Got square type : " << type;
					vSquareList.push_back(NewSquare(ESquareType(type), infile)); // cast type into enum
					//squareList.back()->DisplayName();

				}
				//cout << endl;

			}
		}
		infile.close();


		// The game


		{	// shared pointers. The property and station classes will share the player class.
			shared_ptr<CPlayer> player1 = make_shared<CPlayer>(PLAYER_1_NAME, STARTING_MONEY);
			shared_ptr<CPlayer> player2 = make_shared<CPlayer>(PLAYER_2_NAME, STARTING_MONEY);
		
			int diceRoll;
			int boardSize = vSquareList.size();
		
			cout << GAME_START_MESSAGE << endl;
		
			for (int round = 1; round <= MAX_NUM_ROUNDS; round++) // 
			{
				cout << endl << "<< Round " << round << " >>" << endl; // Output what round it is.
				
				

				// Player 1 turn
				cout << endl << "Player 1 turn begins" << endl;
		
				diceRoll = Random(); // obtain dice roll.
				cout << *player1 << " rolls : " << diceRoll << endl;
				// move the player to said property.
				MovePlayer(player1, diceRoll, boardSize);
		
				// acknowledge player position and then perform the appropriate actions for the square they landed on.
				cout << *player1 << " lands on "; vSquareList[player1->mPlayerPosition]->DisplayName(); cout << endl;
				// Proceed with square specific rules upon a player landing.
				PlayerLanding(player1,*vSquareList[player1->mPlayerPosition]);
				//At the end of each player’s inform them of their current balance.
				cout << player1->mName << " has " << POUND << player1->mMoney << endl;
				

				// Player 2 turn
				cout << endl << "Player 2 turn begins" << endl;
				diceRoll = Random(); // obtain dice roll.
				cout << *player2 << " rolls : " << diceRoll << endl;
				// move the player to said property.
				MovePlayer(player2, diceRoll, boardSize);

				// acknowledge player position and then perform the appropriate actions for the square they landed on.
				cout << *player2 << " lands on "; vSquareList[player2->mPlayerPosition]->DisplayName(); cout << endl;
				// Proceed with square specific rules upon a player landing.
				PlayerLanding(player2, *vSquareList[player2->mPlayerPosition]);
				//At the end of each player’s inform them of their current balance.
				cout << player2->mName << " has " << POUND << player2->mMoney << endl;
		
			}
		
			cout << "GAME OVER" << endl;
			cout << player1->mName << " has " << POUND << player1->mMoney << endl;
			cout << player2->mName << " has " << POUND << player2->mMoney << endl;

			if (player1->mMoney > player1->mMoney)
			{
				cout << "Player 1 wins!" << endl;
			}
			else if (player2->mMoney > player1->mMoney)
			{
				cout << "Player 2 wins!" << endl;
			}
			else
			{
				cout << "It's a draw" << endl;
			}

		
				
		}


		

		//cout << "Square List capacity = " << squareList.size() << endl;

		//for (int i = 0; i < squareList.size(); i++)
		//{
		//	squareList[i]->Display();
		//	cout << endl;
		//}

		//cout << squareList.size();
		//cout << "end of program" << endl;



	}

	


		_CrtDumpMemoryLeaks(); // memory leak detection.
	

}