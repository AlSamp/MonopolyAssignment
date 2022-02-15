#include "CSquareFactory.h"

#include "CProperty.h"
#include "CGo.h"
#include "CStation.h"
#include "CBonus.h"
#include "CPenalty.h"
#include "CJail.h"
#include "CGoToJail.h"
#include "CFreeParking.h"




  // note: added "{}" for each case because an error occured. Solution explanation : https://stackoverflow.com/questions/5136295/switch-transfer-of-control-bypasses-initialization-of-when-calling-a-function
	
unique_ptr<CSquare> NewSquare(ESquareType square, istream& file)
{
	switch (square)
	{

	case ESquareType::Property:
	{
		unique_ptr<CProperty> pObject = make_unique<CProperty>(file);
		return move(pObject);
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
	}
	case ESquareType::Bonus:
	{
		unique_ptr<CBonus> pObject = make_unique<CBonus>(file);
		return move(pObject);
	}
	case ESquareType::Penalty:
	{
		unique_ptr<CPenalty> pObject = make_unique<CPenalty>(file);
		return move(pObject);
	}
	case ESquareType::Jail:
	{
		unique_ptr<CJail> pObject = make_unique<CJail>(file);
		return move(pObject);
	}
	case ESquareType::GoToJail:
	{
		unique_ptr<CGoToJail> pObject = make_unique<CGoToJail>(file);
		return move(pObject);
	}
	case ESquareType::FreeParking:
	{
	unique_ptr<CFreeParking> pObject = make_unique<CFreeParking>(file);
	return move(pObject);
	}
	default:
		break;
	//default case not required as these are enums and can only be them.

	}
}