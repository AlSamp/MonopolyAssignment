// Alix Sampford G20790929
#include "CPenalty.h"

CPenalty::CPenalty(istream& file) : CSquare(file)
{
	file >> *this;
}

istream& operator>>(istream& inputStream, CPenalty& penalty)
{
	return inputStream;
}

void CPenalty::OnLanding(shared_ptr<CPlayer>& ptrPlayerWhoLanded)
{
	// roll dice, each dice roll from 1 - 6 has its own negative outcome for the player
	int diceRoll = Random();


	switch (diceRoll)
	{
	case 1:
		// 1 - Buy a coffee in Starbucks lose £20
		cout << "Buy a coffee in Starbucks. Lose " << k.POUND << "20!" << endl;
		ptrPlayerWhoLanded->mMoney -= k.BONUS_PENALTY_1;
		break;
	case 2:
		// 2 - Pay your broadband brill lose £50
		cout << "Pay your broadband bill. Lose " << k.POUND << "50!" << endl;
		ptrPlayerWhoLanded->mMoney -= k.BONUS_PENALTY_2;
		break;
	case 3:
		// 3 - Visit the SU shop for food lose £100
		cout << "Visit the SU shop for food. Lose " << k.POUND << "100!" << endl;
		ptrPlayerWhoLanded->mMoney -= k.BONUS_PENALTY_3;
		break;
	case 4:
		// 4 - Buy an assignment solution lose £150
		cout << "Buy an assignment solution. Lose " << k.POUND << "150!" << endl;
		ptrPlayerWhoLanded->mMoney -= k.BONUS_PENALTY_4;
		break;
	case 5:
		// 5 - Go for a romantic meal. lose £200
		cout << "Go for a romantic meal. Lose " << k.POUND << "200!" << endl;
		ptrPlayerWhoLanded->mMoney -= k.BONUS_PENALTY_5;
		break;
	case 6:
		// 6 = Pay your university fees. lose £300
		cout << "Pay your university fees. Lose " << k.POUND << "300!" << endl;
		ptrPlayerWhoLanded->mMoney -= k.BONUS_PENALTY_6;
		break;
	default:
		break;
	}
}

int CPenalty::Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * k.NUMBER_OF_BONUS_PENALTY + 1);
}