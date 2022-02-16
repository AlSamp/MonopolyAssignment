#pragma once
#include "CSquare.h"
class CStation : public CSquare
{
private:

protected:
	string namePart2;
	bool isOwned;
	shared_ptr<CPlayer> owner;
	string fullName;

public:

	CStation(istream& file);

	void OnLanding(shared_ptr<CPlayer> playerWhoLanded);

	friend istream& operator >> (istream& inputStream, CStation& station);

	void Display();
};

