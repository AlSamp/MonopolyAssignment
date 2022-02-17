#include "CGoToJail.h"

CGoToJail::CGoToJail(istream& file) :CSquare(file)
{
	file >> *this;
}

void CGoToJail::OnLanding(shared_ptr<CPlayer> playerWhoLanded)
{
	// set the player position to square 7 (zero based index so its 6)
	playerWhoLanded->mPlayerPosition = 6;
	// Inform player of being throw to jail.
	cout << playerWhoLanded->mName << " goes to Jail." << endl;
	// Deduct £50 from the poor fellow.
	cout << playerWhoLanded->mName << " pays " << POUND  <<"50" << endl;
	playerWhoLanded->mMoney -= JAIL_PAYMENT;

}

istream& operator>>(istream& inputStream, CGoToJail& goToJail)
{
	inputStream >> goToJail.namePart2;
	inputStream >> goToJail.namePart3;
	return inputStream;
}

void CGoToJail::DisplayName()
{
	cout << name << " " << namePart2 << " " << namePart3;
}
