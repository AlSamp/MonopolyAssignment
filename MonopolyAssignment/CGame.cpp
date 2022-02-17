#include "CGame.h"

// Returns a random number in the range 1 .. 6
// Note that I am using casting to convert one data type to another 
 int CGame::Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * SIDES_OF_DICE + 1);
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

void CGame::PlayerLanding(shared_ptr<CPlayer> playerWhoLanded, CSquare& square) // TODO override each class function for landing on a square in each of the derived classes.
{
	square.OnLanding(playerWhoLanded);
}

CGame::CGame()
{
	ReadFile(); 
	vPlayers.push_back(make_shared<CPlayer>(PLAYER_1_NAME, STARTING_MONEY));
	vPlayers.push_back(make_shared<CPlayer>(PLAYER_2_NAME, STARTING_MONEY));
	vPlayers.push_back(make_shared<CPlayer>(PLAYER_3_NAME, STARTING_MONEY));
	vPlayers.push_back(make_shared<CPlayer>(PLAYER_4_NAME, STARTING_MONEY));
}

void CGame::GameOver()
{ 
	string winner = "";
	int number = 0;
	cout << endl << "GAME OVER" << endl;
	for (int i = 0; i < MAX_NUM_PLAYERS; i++)
	{	
		cout << vPlayers[i]->mName << " has " << POUND << vPlayers[i]->mMoney << endl;

		if (vPlayers[i]->mMoney > number)
		{
			number = vPlayers[i]->mMoney;
			winner = vPlayers[i]->mName;
		}

	}

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
			if (type != 0)
			{
				vSquareList.push_back(NewSquare(ESquareType(type), infile)); // cast type into enum
			}
		}
	}
	infile.close();
}

void CGame::Monopolish() // The game itself happens here
{
		int diceRoll;
		int boardSize = vSquareList.size();
		srand(SEED);

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
				cout << *vPlayers[i] << " rolls : " << diceRoll << endl;

				// move the player on the board.
				MovePlayer(vPlayers[i], diceRoll, boardSize);

				// acknowledge player position and then perform the appropriate actions for the square they landed on.
				cout << *vPlayers[i] << " lands on "; vSquareList[vPlayers[i]->mPlayerPosition]->DisplayName(); cout << endl;

				// Proceed with square specific rules upon a player landing.
				PlayerLanding(vPlayers[i], *vSquareList[vPlayers[i]->mPlayerPosition]);

				//At the end of each player’s inform them of their current balance.
				cout << vPlayers[i]->mName << " has " << POUND << vPlayers[i]->mMoney << endl;
			}

		}

		GameOver();




	
}


