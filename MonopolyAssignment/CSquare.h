#pragma once
#include <iostream>
using namespace std;
class CSquare
{
protected:
	string name;

public:
	CSquare(istream& file);
	virtual ~CSquare() // neccessary for deletion of derived class object
	{
		
	}

	

	friend istream& operator >> (istream& inputStream, CSquare& square);
	
	friend ostream& operator << (ostream& outputStream, const CSquare& square);
	virtual void Display(); // yay polymorphism

	
};

