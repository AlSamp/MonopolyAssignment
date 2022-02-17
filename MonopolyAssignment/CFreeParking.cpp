#include "CFreeParking.h"

CFreeParking::CFreeParking(istream& file) : CSquare(file)
{
	file >> *this;
}

istream& operator>>(istream& inputStream, CFreeParking& freeParking)
{
	inputStream >> freeParking.namePart2;

	return inputStream;
}


void CFreeParking::OnLanding(shared_ptr<CPlayer> playerWhoLanded)
{
	// Inform player of circumstance.
	cout << playerWhoLanded->mName << " is resting" << endl;
}

void CFreeParking::DisplayName() // CSquare overridden virtual function
{
	cout << " " << name << " " << namePart2 << " ";
}