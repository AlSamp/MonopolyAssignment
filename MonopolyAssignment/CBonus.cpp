// Alix Sampford G20790929
#include "CBonus.h"


CBonus::CBonus(istream& file) : CSquare(file)
{
    file >> *this;
}

istream& operator>>(istream& inputStream, CBonus& bonus)
{
    return inputStream;
}

void CBonus::OnLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded)
{
	// roll dice, each dice roll from 1 - 6 has its own negative outcome for the player
	//srand(SEED);
	int diceRoll = Random();

	//cout << *playerWhoLanded << " lands on Bonus." << endl;

	switch (diceRoll)
	{
	case 1:
		// 1 - Find some money gain £20.
		cout << "Find some money. Gain " << k.POUND << "20!" << endl;
		ptrPlayerWhoLanded->mMoney += k.BONUS_PENALTY_1;
		break;
	case 2:
		// 2 - Win a coding competition. Gain £50.
		cout << "Win a coding competition. Gain " << k.POUND << "50!" << endl;
		ptrPlayerWhoLanded->mMoney += k.BONUS_PENALTY_2;
		break;
	case 3:
		// 3 - Recieve a rent rebate. Gain £100.
		cout << "Recieve a rent rebate. Gain " << k.POUND << "100!" << endl;
		ptrPlayerWhoLanded->mMoney += k.BONUS_PENALTY_3;
		break;
	case 4:
		// 4 - Win the lotter gain £50.
		cout << "Win the lottery. Gain " << k.POUND << "150!" << endl;
		ptrPlayerWhoLanded->mMoney += k.BONUS_PENALTY_4;
		break;
	case 5:
		// 5 - Sell your iPad gain £200.
		cout << "Sell your iPad. Gain " << k.POUND << "200!" << endl;
		ptrPlayerWhoLanded->mMoney += k.BONUS_PENALTY_5;
		break;
	case 6:
		// 6 = It's your birthday gain £300.
		cout << "It's your birthday. Gain " << k.POUND << "300!!!" << endl;
		ptrPlayerWhoLanded->mMoney += k.BONUS_PENALTY_6;
		break;
	default:
		break;
	}

	//cout << *playerWhoLanded << " has " << POUND << playerWhoLanded->mMoney << "." << endl;



}

int CBonus::Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * k.NUMBER_OF_BONUS_PENALTY + 1);
}