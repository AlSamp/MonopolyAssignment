#include "CProperty.h"


CProperty::CProperty(istream& file) : CSquare(file)
{
	// base class constructor is going to read in the name of the property.
	// The derived constructor is then going to follow on  and read in the rest of it

	propertyColour = NULL;
	propertyCost = NULL;
	propertyRent = NULL;
	isOwned = false;
	owner = nullptr;
	
	file >> *this;
}

istream& operator >>(istream& inputStream, CProperty& property)
{
	if (property.name != "Friargate") // this is for you nick ty <3
	{
		inputStream >> property.namePart2;
	}

		inputStream >> property.propertyCost;
		inputStream >> property.propertyRent;
		inputStream >> property.propertyColour;
	
	return inputStream;
}

void CProperty::Display()
{
	cout << name << " ";

	if (name != "Friargate") // this is for you nick ty <3
	{
		cout << namePart2 << " ";
	}
		cout << propertyCost << " " << propertyRent << " " << propertyColour << endl;
}

void CProperty:: DisplayName()
{
	cout << name;

	if (name != "Friargate") // this is for you nick ty <3
	{
		cout << " " << namePart2;
	}
}

int CProperty::getRent()
{
	return propertyRent;
}
int CProperty::getCost()
{
	return propertyCost;
}
int CProperty::getColour()
{
	return propertyColour;
}

void CProperty::setIsOwned(bool newStatus)
{
	isOwned = newStatus;
}



void CProperty::setOwner(shared_ptr<CPlayer>  newOwner)
{
	owner = newOwner; // TODO move will be required if this is implemented
}

bool CProperty::getIsOwned()
{
	return isOwned;
}

void CProperty::OnLanding(shared_ptr<CPlayer> playerWhoLanded) // 
{
	// check is property is owned. 
	if (isOwned == false)
	{
		//If not player buys it if they have the funds.
		if (playerWhoLanded->mMoney > 0)
		{
			//charge the player for their purchase.
			playerWhoLanded->mMoney -= this->propertyCost;
			//Set that player as the owner
			isOwned = true;
			owner = playerWhoLanded;
			cout << *playerWhoLanded << " buys "; DisplayName(); cout << " for " << POUND << this->propertyCost << "." << endl;
		}
		else
		{
			// When player has not enough money to buy a property output this.
			cout << *playerWhoLanded << " does not have enough money to purchase "; DisplayName(); cout << endl;				
		}
	}
	else  // if the property is owned
	{
		// if the player does not own the property and it is owned, charge them rent.
		if (playerWhoLanded->mName != owner->mName)
		{

			//perform a check on wether or not the player owns all colours of one group.


			//charge the player rent
			playerWhoLanded->mMoney -= this->propertyRent;
			// pay the owner rent
			owner->mMoney += this->propertyRent;

			cout << *playerWhoLanded << " has payed " << POUND << propertyRent << " rent to " << owner->mName << "." << endl;
		}
	}
}