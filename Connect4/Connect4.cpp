// Connect4.cpp : Defines the entry point for the console application.
//
#include "grille.h"
#include <iostream>
#include <string>

Grille& grille = Grille::instance();

const int NBR_JOUEUR = 2;
char joueurs[NBR_JOUEUR] = { 'O', 'X' };

void tourJoueur(char joueur)
{
	bool valeurInvalide = true;
	int colonne = -1;
	while (valeurInvalide)
	{
		std::cout << "Placez votre pion sur une rangee (entrez chiffre de 1 a " << grille.LONG << ")." << std::endl;
		//std::cin.ignore();
		std::cin.clear();
		fflush(stdin);
		std::cin >> colonne;
		//std::getline(std::cin, colonne);
		if (colonne < 1 || colonne > grille.LONG)
		{
			std::cout << "Colonne " << colonne << " est hors limite" << std::endl;
			valeurInvalide = true;
		}
		else if (grille.verifierColonnePleine(colonne-1))
		{
			std::cout << "Colonne pleine" << std::endl;
			valeurInvalide = true;
		}
		else valeurInvalide = false;
	}
	grille.ajouter(joueur, colonne - 1);
}

void deroulementPartie()
{
	char joueurGagnant = grille.VIDE;
	while (joueurGagnant == grille.VIDE)
	{
		for (int i = 0; i < NBR_JOUEUR; i++)
		{
			tourJoueur(joueurs[i]);
			grille.afficher();
			if (grille.verifierGagnant(joueurs[i]))
			{
				joueurGagnant = joueurs[i];
				break;
			}
			else if (grille.verifierGrillePleine())
			{
				std::cout << "Partie nulle" << std::endl;
				return;
			}
		}
	}
	std::cout << "Le joueur " << joueurGagnant << " a gagne!!" << std::endl;
}

int main()
{
	deroulementPartie();

    return 0;
}

