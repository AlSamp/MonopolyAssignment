// Alix Sampford G20790929
#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "CSquare.h"
#include <fstream>

enum class ESquareType : int
{
	Property = 1,
	Go = 2,
	Station = 3,
	Bonus = 4,
	Penalty =5,
	Jail = 6,
	GoToJail = 7,
	FreeParking = 8

};

unique_ptr<CSquare> NewSquare(ESquareType square, istream& file);


