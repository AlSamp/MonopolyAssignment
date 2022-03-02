// Alix Sampford G20790929
#include "CGame.h"

// Returns a random number in the range 1 .. 6
// Note that I am using casting to convert one data type to another 
int CGame::Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * SIDES_OF_DICE + 1);
}

void CGame::MovePlayer(shared_ptr<CPlayer>& player, int roll, int boardSize)
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

void CGame::PlayerLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded, CSquare& square) // When a player lands on a specific square before the appropriate action
{
	square.OnLanding(ptrPlayerWhoLanded);
}

CGame::CGame()
{
	ReadFile(); 
	// push players with their information in the vector that will contain them and be used to access them throughout the game.
	vPtrPlayers.push_back(make_shared<CPlayer>(PLAYER_1_NAME, STARTING_MONEY));
	vPtrPlayers.push_back(make_shared<CPlayer>(PLAYER_2_NAME, STARTING_MONEY));
	vPtrPlayers.push_back(make_shared<CPlayer>(PLAYER_3_NAME, STARTING_MONEY));
	vPtrPlayers.push_back(make_shared<CPlayer>(PLAYER_4_NAME, STARTING_MONEY));
}

void CGame::GameOver()
{ 
	string winner;
	int number = 0;

	cout << endl << "GAME OVER" << endl;
	for (int i = 0; i < MAX_NUM_PLAYERS; i++)
	{	
		// out all player balances to screen
		cout << vPtrPlayers[i]->mName << " has " << POUND << vPtrPlayers[i]->mMoney << endl;

		// Check and record witch player has the most moneny and output who has the most.
		if (vPtrPlayers[i]->mMoney > number)
		{
			number = vPtrPlayers[i]->mMoney;
			winner = vPtrPlayers[i]->mName;
		}

	}

	//output winner
	cout << endl << winner << " wins!" << endl;

}

void CGame::ReadFile()
{
	ifstream infile;
	infile.open(GAME_FILE);
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			int type = 0;
			infile >> type;
			if (type != 0) // Get the number type of the data and place into sqaure factory for assembly.
			{
				vPtrSquareList.push_back(NewSquare(ESquareType(type), infile)); // cast type into enum
			}
		}
	}
	infile.close();
}

void CGame::Monopolish() // The game itself happens here
{
		int diceRoll;
		int boardSize = vPtrSquareList.size();
		srand(SEED); // game seed

		cout << GAME_START_MESSAGE << endl;

		for (int round = 1; round <= MAX_NUM_ROUNDS; round++) // 
		{
			cout << endl << "<< Round " << round << " >>" << endl; // Output what round it is.

			// Player turns

			for (int i = 0; i < MAX_NUM_PLAYERS; i++)
			{
				//Output which players turn it is.
				cout << endl << "Player "<< i+1 <<" turn begins" << endl;

				// obtain dice roll.
				diceRoll = Random(); 

				//output the player and what they rolled
				cout << *vPtrPlayers[i] << " rolls : " << diceRoll << endl;

				// move the player on the board.
				MovePlayer(vPtrPlayers[i], diceRoll, boardSize);

				// acknowledge player position and then perform the appropriate actions for the square they landed on.
				cout << *vPtrPlayers[i] << " lands on "; vPtrSquareList[vPtrPlayers[i]->mPlayerPosition]->DisplayName(); cout << endl;

				// Proceed with square specific rules upon a player landing.
				PlayerLanding(vPtrPlayers[i], *vPtrSquareList[vPtrPlayers[i]->mPlayerPosition]);

				//At the end of each player’s inform them of their current balance.
				cout << vPtrPlayers[i]->mName << " has " << POUND << vPtrPlayers[i]->mMoney << endl;
			}
		}

		GameOver();
}