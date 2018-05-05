// Connect4.cpp : Defines the entry point for the console application.
//
#include "grille.h"
#include <iostream>
#include <string>

Grille& grille = Grille::instance();
char joueur1 = 'O';
char joueur2 = 'X';

void tourJoueur(char joueur)
{
	int rangee = -1;
	while (rangee == -1)
	{
		std::cout << "Placez votre pion sur une rangee (entrez chiffre de 1 a " << grille.LONG << ")." << std::endl;
		std::cin.ignore();
		std::cin >> rangee;
		//std::getline(std::cin, rangee);
		if (rangee < 1 || rangee > grille.LONG)
		{
			std::cout << "Erreur" << std::endl;
			rangee = -1;
		}
	}
	grille.ajouter(joueur, rangee);
}

void deroulementPartie()
{
	char joueurGagnant = '-';
	while (joueurGagnant == '-')
	{
		tourJoueur(joueur1);
		if (grille.verifierGagnant())
		{
			joueurGagnant = joueur1;
			break;
		}
		tourJoueur(joueur2);
		if (grille.verifierGagnant())
			joueurGagnant = joueur2;
	}
	std::cout << "Le joueur " << joueurGagnant << " a gagne!!" << std::endl;
}

int main()
{
	deroulementPartie();

    return 0;
}

