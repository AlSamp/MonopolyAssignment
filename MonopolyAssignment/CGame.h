#pragma once
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

using namespace std;

typedef vector<unique_ptr<CSquare>> uVector; // TODO ask about this
typedef  shared_ptr<CPlayer> PlayerPtr;
typedef vector<shared_ptr<CPlayer>> PlayersVector;

class CGame
{
private:
	static int Random();
	void ReadFile();
	void GameOver();
	void PlayerLanding(shared_ptr<CPlayer> playerWhoLanded, CSquare& square);

	uVector vSquareList; // The squares of the monopolish board will be stored within this vector of unique pointers
	PlayersVector vPlayers;
	PlayerPtr pPlayer1; // shared pointers. The property and station classes will share the player class.
	PlayerPtr pPlayer2;
public:
	CGame(); // constructor to initialise all game variable.
	void Monopolish();
};

