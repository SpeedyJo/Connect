// Connect4.cpp : Defines the entry point for the console application.
//
#include "grille.h"

Grille& grille = Grille::instance();

void tour()
{
	while (!grille.verifierGagnant())
	{

	}
}

int main()
{
	

    return 0;
}

