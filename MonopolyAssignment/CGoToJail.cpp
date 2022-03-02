// Alix Sampford G20790929
#include "CGoToJail.h"

CGoToJail::CGoToJail(istream& file) :CSquare(file)
{
	file >> *this;
}

void CGoToJail::OnLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded)
{
	// set the player position to square 7 (zero based index so its 6)
	ptrPlayerWhoLanded->mPlayerPosition = 6;
	// Inform player of being throw to jail.
	cout << ptrPlayerWhoLanded->mName << " goes to Jail." << endl;
	// Deduct £50 from the poor fellow.
	cout << ptrPlayerWhoLanded->mName << " pays " << POUND  <<"50" << endl;
	ptrPlayerWhoLanded->mMoney -= JAIL_PAYMENT;
}

istream& operator>>(istream& inputStream, CGoToJail& goToJail)
{
	return inputStream;
}


