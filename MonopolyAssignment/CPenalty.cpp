#include "CPenalty.h"

CPenalty::CPenalty(istream& file) : CSquare(file)
{
	file >> *this;
}

istream& operator>>(istream& inputStream, CPenalty& penalty)
{
	return inputStream;
}

void CPenalty::OnLanding(shared_ptr<CPlayer> playerWhoLanded)
{
	// roll dice, each dice roll from 1 - 6 has its own negative outcome for the player
	
}

int CPenalty::Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}