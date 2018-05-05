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
	int colonne = -1;
	while (colonne == -1)
	{
		std::cout << "Placez votre pion sur une rangee (entrez chiffre de 1 a " << grille.LONG << ")." << std::endl;
		//std::cin.ignore();
		std::cin >> colonne;
		//std::getline(std::cin, colonne);
		if (colonne < 1 || colonne > grille.LONG)
		{
			std::cout << "Erreur" << std::endl;
			colonne = -1;
		}
	}
	grille.ajouter(joueur, colonne - 1);
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

