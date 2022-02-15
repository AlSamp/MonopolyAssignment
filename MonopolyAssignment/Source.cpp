// Alix Sampford

#define _CRTDBG_MAP_ALLOC  // memory leak detection.
#include <stdlib.h>		   // memory leak detection.
#include <crtdbg.h>		   // memory leak detection.
#include <ctime>		   // Used for the random function.
#include <iostream>
#include "CSquareFactory.h"
#include "CSquare.h"
#include <vector>
#include <fstream>

using namespace std;


// Returns a random number in the range 1 .. 6
// Note that I am using casting to convert one data type to another
int Random()
{
	return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);
}

int main()
{
	{

		// A random number generator actually produces a pseudo-random sequence of numbers.
		// This means that the random number generator will always produce the same sequence of numbers.
		// The generator needs to be "seeded" with a value. You seed the generator with the function srand().
		// If you want to create a different sequence of numbers each time then seed it with the time as follows:

		srand(static_cast<unsigned int> (time(0)));

		// The output of time() is time_t (which is actually an int).
		// static_cast<unsigned int> merely converts the output of time() into an unsigned integer.

		for (int i = 0; i < 10; i++)
		{
			cout << Random() << endl;
		}
		cout << endl;

		// However, if you seed the generator with the same value each time then it will always produce
		// the same sequence of numbers. You want this to occur with the Monopoly program.
		// The next bit of code does this:

		srand(4);

		for (int i = 0; i < 10; i++)
		{
			cout << Random() << endl;
		}

		system("pause");

		//vector<CSquare*> squareList;
		vector<unique_ptr<CSquare>> squareList;
		ifstream infile;


		infile.open("monopoly.txt");
		if (infile.is_open())
		{

			while (!infile.eof())
			{

				int type = 0;
				
				infile >> type;
				if (type != 0)
				{
					cout << "Got square type : " << type;
					squareList.push_back(NewSquare(ESquareType(type), infile)); // cast type into enum
					cout << "  Name = " << *squareList.back();

				}
				cout << endl;

			}
		}

		infile.close();

		cout << "Square List capacity = " << squareList.capacity() << endl;

		for (int i = 0; i < squareList.size(); i++)
		{
			squareList[i]->Display();
		}

		cout << squareList.size();
		cout << "end of program" << endl;



	}

	{

		_CrtDumpMemoryLeaks(); // memory leak detection.
	}

}