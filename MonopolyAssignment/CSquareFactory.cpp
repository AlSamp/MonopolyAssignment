// Alix Sampford G20790929
#include "CSquareFactory.h"

#include "CProperty.h"
#include "CGo.h"
#include "CStation.h"
#include "CBonus.h"
#include "CPenalty.h"
#include "CJail.h"
#include "CGoToJail.h"
#include "CFreeParking.h"



unique_ptr<CSquare> NewSquare(ESquareType square, istream& file)
{
	switch (square)
	{

	case ESquareType::Property:
	{
		unique_ptr<CProperty> pObject = make_unique<CProperty>(file);
		return move(pObject); // move the ownership of the newly created unique pointer to the vector
		break;
	}
	case ESquareType::Go:
	{
		unique_ptr<CGo> pObject = make_unique<CGo>(file);
		return move(pObject);
		break;
	}
	case ESquareType::Station:
	{
		unique_ptr<CStation> pObject = make_unique<CStation>(file);
		return move(pObject);
		break;
	}
	case ESquareType::Bonus:
	{
		unique_ptr<CBonus> pObject = make_unique<CBonus>(file);
		return move(pObject);
		break;
	}
	case ESquareType::Penalty:
	{
		unique_ptr<CPenalty> pObject = make_unique<CPenalty>(file);
		return move(pObject);
		break;
	}
	case ESquareType::Jail:
	{
		unique_ptr<CJail> pObject = make_unique<CJail>(file);
		return move(pObject);
		break;
	}
	case ESquareType::GoToJail:
	{
		unique_ptr<CGoToJail> pObject = make_unique<CGoToJail>(file);
		return move(pObject);
		break;
	}
	case ESquareType::FreeParking:
	{
		unique_ptr<CFreeParking> pObject = make_unique<CFreeParking>(file);
		return move(pObject);
		break;
	}
	default:
		break;
	//default case not required as these are enums and can only be them.

	}
}