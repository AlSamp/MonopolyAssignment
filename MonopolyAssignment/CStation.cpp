#include "CStation.h"

CStation::CStation(istream& file) : CSquare(file)
{

	isOwned = false;
	owner = nullptr;

	file >> *this;
}

void CStation::Display()
{
	cout << name << " " << namePart2 << endl;
}

istream& operator>>(istream& inputStream, CStation& station)
{
	inputStream >> station.namePart2;

	return inputStream;
}

void CStation::DisplayName()
{
	cout << name << " " << namePart2;
}

void CStation::OnLanding(shared_ptr<CPlayer> playerWhoLanded) // 
{
	// check is property is owned. 
	if (isOwned == false)
	{
		//If not player buys it if they have the funds.
		if (playerWhoLanded->mMoney > 0)
		{
			//charge the player for their purchase.
			playerWhoLanded->mMoney -= STATION_PRICE;
			//Set that player as the owner
			isOwned = true;
			owner = playerWhoLanded;
			cout << *playerWhoLanded << " buys "; DisplayName(); cout  << " for " << POUND << STATION_PRICE << endl;
		}
		else
		{
			cout << *playerWhoLanded << " does not have enough money to purchase "; DisplayName(); cout << endl; // TODO make this refer to full names
		}
	}
	else  // if the property is owned
	{
		// if the player does not own the station and is it owned, charge them rent.
		if (playerWhoLanded->mName != owner->mName)
		{
			//charge the player rent
			playerWhoLanded->mMoney -= STATION_RENT;
			// pay the owner rent
			owner->mMoney += STATION_RENT;

			cout << *playerWhoLanded << " pays " << POUND << STATION_RENT << " for ticket " << endl; // << owner->mName
		}
	}



}