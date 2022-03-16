// Alix Sampford G20790929
#include "CProperty.h"


CProperty::CProperty(istream& file) : CSquare(file)
{
	// base class constructor is going to read in the name of the property.
	// The derived constructor is then going to follow on  and read in the rest of it

	mPropertyColour = NULL;
	mPropertyCost = NULL;
	mPropertyRent = NULL;
	mIsOwned = false;
	pOwner = nullptr;
	
	file >> *this;
}

istream& operator >>(istream& inputStream, CProperty& property)
{
		inputStream >> property.mPropertyCost;
		inputStream >> property.mPropertyRent;
		inputStream >> property.mPropertyColour;
	
	return inputStream;
}







void CProperty::OnLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded) // 
{
	// check is property is owned. 
	if (mIsOwned == false)
	{
		//If not player buys it if they have the funds.
		if (ptrPlayerWhoLanded->mMoney > 0)
		{
			//charge the player for their purchase.
			ptrPlayerWhoLanded->mMoney -= this->mPropertyCost;
			//Set that player as the owner
			mIsOwned = true;
			pOwner = ptrPlayerWhoLanded;
			cout << *ptrPlayerWhoLanded << " buys "; DisplayName(); cout << " for " << k.POUND << this->mPropertyCost << "." << endl;
		}
		else
		{
			// When player has not enough money to buy a property output this.
			cout << *ptrPlayerWhoLanded << " does not have enough money to purchase "; DisplayName(); cout << endl;				
		}
	}
	else  // if the property is owned
	{
		// if the player does not own the property and it is owned, charge them rent.
		if (ptrPlayerWhoLanded->mName != pOwner->mName)
		{

			//perform a check on wether or not the player owns all colours of one group.


			//charge the player rent
			ptrPlayerWhoLanded->mMoney -= this->mPropertyRent;
			// pay the owner rent
			pOwner->mMoney += this->mPropertyRent;

			cout << *ptrPlayerWhoLanded << " has payed " << k.POUND << mPropertyRent << " rent to " << pOwner->mName << "." << endl;
		}
		else
		{
			//output what happens when a players lands on a property the own.
			cout << *ptrPlayerWhoLanded << " owns "; DisplayName(); cout << " (no charge required)" << endl;
		}
	}
}