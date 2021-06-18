#include"Store.h"
#include"Card.h"


void Store::init()
{
	
	return;
}

void Store::randFourCards()
{
	srand((unsigned)time(NULL));
	//rand 3 chess
	for (int i = 1; i <= 3; i++)
	{
		int identification = rand() % 6;//get int from 0 to 5 as identification

		allCards.push_back(identification);
	}

	//rand 1 equipment
	int identification = 6+rand() % 3;

	allCards.push_back(identification);

	return;
}

