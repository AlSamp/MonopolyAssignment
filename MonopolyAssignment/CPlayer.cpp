// Alix Sampford G20790929
#include "CPlayer.h"

CPlayer::CPlayer(string name, int startingMoney)
{
	mName = name;
	mMoney = startingMoney;
	mPlayerPosition = 0;
}

ostream& operator << (ostream& outputStream, const CPlayer& player)
{

	outputStream << player.mName;
	return outputStream;
}