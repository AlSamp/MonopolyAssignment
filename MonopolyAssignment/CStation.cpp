// Alix Sampford G20790929
#include "CStation.h"

CStation::CStation(istream& file) : CSquare(file)
{

	isOwned = false;
	pOwner = nullptr;
	file >> *this;
}


istream& operator>>(istream& inputStream, CStation& station)
{
	return inputStream;
}



void CStation::OnLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded) // 
{
	// check is property is owned. 
	if (isOwned == false)
	{
		//If not player buys it if they have the funds.
		if (ptrPlayerWhoLanded->mMoney > 0)
		{
			//charge the player for their purchase.
			ptrPlayerWhoLanded->mMoney -= k.STATION_PRICE;
			//Set that player as the owner
			isOwned = true;
			pOwner = ptrPlayerWhoLanded;
			cout << *ptrPlayerWhoLanded << " buys "; DisplayName(); cout  << " for " << k.POUND << k.STATION_PRICE << endl;
		}
		else
		{
			cout << *ptrPlayerWhoLanded << " does not have enough money to purchase "; DisplayName(); cout << endl;
		}
	}
	else  // if the property is owned
	{
		// if the player does not own the station and is it owned, charge them rent.
		if (ptrPlayerWhoLanded->mName != pOwner->mName)
		{
			//charge the player rent
			ptrPlayerWhoLanded->mMoney -= k.STATION_RENT;
			// pay the owner rent
			pOwner->mMoney += k.STATION_RENT;

			cout << *ptrPlayerWhoLanded << " pays " << k.POUND << k.STATION_RENT << " for ticket " << endl; // << owner->mName
		}
	}



}