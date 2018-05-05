#include "grille.h"
#include <iostream>

namespace
{
	//std::vector<std::vector<char> > grille(HAUTEUR, std::vector<char>(LONGUEUR, 'd')); => push_back to add directly on top of "stack"
	char grille[HAUTEUR][LONGUEUR];
}

Grille::Grille()
{
	reinitialiser();
}

Grille& Grille::instance()
{
	static Grille grille = Grille();
	return grille;
}
bool Grille::ajouter(char joueur, int colonne)
{
	int i = 0;
	bool trouvePos = false;
	while(i < HAUTEUR && !trouvePos)
	{
		trouvePos = grille[i][colonne] == VIDE;
		if (trouvePos)
		{
			positionCourante = std::make_tuple(i, colonne);
			grille[i][colonne] = joueur;
		}
		i++;
	}
	return trouvePos;
}

bool Grille::verifierColonnePleine(int colonne)
{
	return grille[HAUTEUR-1][colonne] != VIDE;
}

bool Grille::verifierGagnant(char joueur) const
{
	int x = std::get<0>(positionCourante);
	int y = std::get<1>(positionCourante);
	const int DIRECTION = 4;
	const int connectN = 3;
	int dx[DIRECTION] = {0, 1, 1, 1};
    int dy[DIRECTION] = {1, 1, 0,-1};
	int colonne;
	int rangee;
	bool gagnant = false;
	for(int k = 0; k < DIRECTION; k++)
	{
		bool memeChar= false;
		int i = 1;
		int nbrMemeChar = 0;
		do{
			colonne = (x + i*dx[k]);
			rangee = (y + i*dy[k]);
			if (0 <= colonne && colonne <= LONGUEUR && 0 <= rangee && rangee <= HAUTEUR)
			{
				if (grille[colonne][rangee] == joueur)
				{
					memeChar = true;
					nbrMemeChar++;
				}
				else if (grille[colonne][rangee] != joueur)
					memeChar = false;

				if (nbrMemeChar >= connectN) {
					gagnant = true;
					break;
				}
				i++;
			}
		}while(memeChar);
		i =-1;
		do{
			colonne = (x + i*dx[k]);
			rangee = (y + i*dy[k]);
			if (0 <= colonne && colonne <= LONGUEUR && 0 <= rangee && rangee <= HAUTEUR)
			{
				if (grille[colonne][rangee] == joueur)
				{
					memeChar = true;
					nbrMemeChar++;
				}
				else if (grille[colonne][rangee] != joueur)
					memeChar = false;

				if (nbrMemeChar >= connectN) {
					gagnant = true;
					break;
				}
				i--;
			}
		}while(memeChar && !gagnant);
		
	}
	return gagnant;
}

void Grille::reinitialiser()
{
	for (int i = 0; i < HAUTEUR; i++)
		for (int j = 0; j < LONGUEUR; j++)
			grille[i][j] = VIDE;
}

void Grille::afficher()
{
	for (int i = HAUTEUR-1; i >= 0; i--)
	{
		std::cout << "\t";
		for (int j = 0; j < LONGUEUR; j++)
			std::cout << "  " << grille[i][j] << "  ";
		std::cout << std::endl;
	}
}