#include "grille.h"

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
bool Grille::ajouter(char joueur, int rangee)
{
	int i = 0;
	bool trouvePos = false;
	do
	{
		trouvePos = grille[i][rangee] == VIDE;
		if (trouvePos)
			grille[i][rangee] = joueur;
		i++;
	} while (i < HAUTEUR || trouvePos);
	return trouvePos;
}

bool Grille::verifierGagnant() const
{
	int dx[N] = {0, 1, 1, 1, 0,-1,-1,-1};
    	int dy[N] = {1, 1, 0,-1,-1,-1, 0, 1};
}

void Grille::reinitialiser()
{
	for (int i = 0; i < LONGUEUR; i++)
		for (int j = 0; j < HAUTEUR; j++)
			grille[i][j] = VIDE;
}
