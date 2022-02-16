// Alix Sampford

#define _CRTDBG_MAP_ALLOC  // memory leak detection.
#include <stdlib.h>		   // memory leak detection.
#include <crtdbg.h>		   // memory leak detection.
#include <ctime>		   // Used for the random function.
#include <iostream>
#include <fstream>
#include <vector>

#include "Constants.h"
#include "CSquareFactory.h"
#include "CSquare.h"
#include "CPlayer.h"
#include "CProperty.h"



using namespace std;


// Returns a random number in the range 1 .. 6
// Note that I am using casting to convert one data type to another
int Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

int Player1Roll()
{
	//srand(static_cast<unsigned int> (time(0))); time is the seed
	srand(PLAYER_1_SEED);
	return Random();
}

void MovePlayer(CPlayer* player, int roll, int boardSize)
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

void PlayerLanding(CPlayer& playerWhoLanded, CPlayer& propertyOwner, CSquare& square) // TODO override each class function for landing on a square in each of the derived classes.
{
	square.OnLanding(playerWhoLanded,propertyOwner);
	//square.OnLanding(playerWhoLanded);
}

int main()
{
	{

		// A random number generator actually produces a pseudo-random sequence of numbers.
		// This means that the random number generator will always produce the same sequence of numbers.
		// The generator needs to be "seeded" with a value. You seed the generator with the function srand().
		// If you want to create a different sequence of numbers each time then seed it with the time as follows:

		

		// The output of time() is time_t (which is actually an int).
		// static_cast<unsigned int> merely converts the output of time() into an unsigned integer.

		for (int i = 0; i < 10; i++)
		{
			cout << Random() << endl;
		}
		cout << endl;
		
		// However, if you seed the generator with the same value each time then it will always produce
		// the same sequence of numbers. You want this to occur with the Monopoly program.
		// The next bit of code does this:
		
		srand(SEED);
		
		for (int i = 0; i < 10; i++)
		{
			cout << Random() << endl;
		}

		//system("pause");

		//vector<CSquare*> squareList;
		vector<unique_ptr<CSquare>> squareList;
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
					cout << "Got square type : " << type;
					squareList.push_back(NewSquare(ESquareType(type), infile)); // cast type into enum
					cout << "  Name = " << *squareList.back();

				}
				cout << endl;

			}
		}
		infile.close();


		// The game


		{
			CPlayer* player1 = new CPlayer(PLAYER_1_NAME,STARTING_MONEY); // TODO convert to smart pointers.
			CPlayer* player2 = new CPlayer(PLAYER_2_NAME, STARTING_MONEY);
		
			int diceRoll;
			int boardSize = squareList.size();
		
			cout << GAME_START_MESSAGE << endl;
		
			for (int round = 1; round <= MAX_NUM_ROUNDS; round++) // 
			{
				cout << endl << "Round " << round << endl; // Output what round it is.
				cout << player1->mName << " has " << POUND << player1->mMoney << endl;
				cout << player2->mName << " has " << POUND << player2->mMoney << endl;

				// Player 1 turn
				cout << endl << "Player 1 turn begins." << endl;
		
				diceRoll = Random(); // obtain dice roll.
				cout << *player1 << " rolls : " << diceRoll << endl;
				// move the player to said property.
				MovePlayer(player1, diceRoll, boardSize);
		
				// acknowledge player position and then perform the appropriate actions for the square they landed on.
				cout << *player1 << " is at " << *squareList[player1->mPlayerPosition] << endl;
				// Proceed with square specific rules upon a player landing.
				PlayerLanding(*player1,*player2,*squareList[player1->mPlayerPosition]);
				

				// Player 2 turn
				cout << endl << "Player 2 turn begins." << endl;
				diceRoll = Random(); // obtain dice roll.
				cout << *player2 << " rolls : " << diceRoll << endl;
				// move the player to said property.
				MovePlayer(player2, diceRoll, boardSize);

				// acknowledge player position and then perform the appropriate actions for the square they landed on.
				cout << *player2 << " is at " << *squareList[player2->mPlayerPosition] << endl;
				// Proceed with square specific rules upon a player landing.
				PlayerLanding(*player2, *player1, *squareList[player2->mPlayerPosition]);
				



		
		
			}
		
			cout << player1->mName << "has " << POUND << player1->mMoney << endl;
			cout << player2->mName << "has " << POUND << player2->mMoney << endl;
/*		//	• In your main program, simulate playing 20 rounds of the game as follows :
			• When the game is started, a welcome message is displayed.The format of the message is :
			'Welcome to Monopol-ish'
				• At the start of each round, the round number should be output :
			'round <round number>'
				• For each turn, the name of the playerand the generated number is displayed.Use the description
				of the player’s piece as their name(i.e.Hamster, Pumpkin).Output the message :
			'<Player> rolls <number>'
				• On the next line the name of the player and the name of the square that the player landed on are
				displayed.Output the message :
			'<Player> lands on <square name>'
				• When a player passes over or lands on GO, the player receives £200.You must output the
				message :
			‘<Player> passes GOand collects £200'
				• When a player lands on any other square, nothing should happen.
				• At the end of the game you should output the final amount of money each player has, and also
				which player has won.Output the following messages :
			'Game Over'
				'<Player1> has £<amount>
				'<Player2> has £<amount>
				‘<Player> wins.*/
		
		
		
		
		
		
		
		
		
		
		
		
		
		}



















		cout << "Square List capacity = " << squareList.size() << endl;

		for (int i = 0; i < squareList.size(); i++)
		{
			squareList[i]->Display();
			cout << endl;
		}

		cout << squareList.size();
		cout << "end of program" << endl;



	}

	{

		_CrtDumpMemoryLeaks(); // memory leak detection.
	}

}