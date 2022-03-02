// Alix Sampford G20790929
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


class CGame
{
private:
	typedef vector<unique_ptr<CSquare>> vupVector; // TODO ask about this
	typedef  shared_ptr<CPlayer> spPlayer;
	typedef vector<shared_ptr<CPlayer>> vpPlayers;

	int Random();
	void ReadFile();
	void GameOver(); // Check player money and output who has the most as winner
	void MovePlayer(shared_ptr<CPlayer>& player, int roll, int boardSize);
	void PlayerLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded, CSquare& square); // When a player lands on a specific square before the appropriate action //TODO ask shared_ptr<CPlayer>&
	vupVector vPtrSquareList; // The squares of the monopolish board will be stored within this vector of unique pointers
	vpPlayers vPtrPlayers; // vector of shared pointers. The property and station classes will share the player class.

public:
	CGame(); // constructor to initialise all game variables.
	void Monopolish();
};

