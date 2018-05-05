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
		//std::cin.ignore();
		std::cin >> rangee;
		//std::getline(std::cin, rangee);
		if (rangee < 1 || rangee > grille.LONG)
		{
			std::cout << "Erreur" << std::endl;
			rangee = -1;
		}
	}
	grille.ajouter(joueur, rangee - 1);
}

void deroulementPartie()
{
	char joueurGagnant = '-';
	while (joueurGagnant == '-')
	{
		tourJoueur(joueur1);
		grille.afficher();
		if (grille.verifierGagnant(joueur1))
		{
			joueurGagnant = joueur1;
			break;
		}
		tourJoueur(joueur2);
		grille.afficher();
		if (grille.verifierGagnant(joueur2))
			joueurGagnant = joueur2;
	}
	std::cout << "Le joueur " << joueurGagnant << " a gagne!!" << std::endl;
}

int main()
{
	deroulementPartie();

    return 0;
}

