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

bool Grille::verifierGagnant(char joueur) const
{
	int dx[N] = {0, 1, 1, 1};
    	int dy[N] = {1, 1, 0,-1};
	bool gagnant = false;
	for(int k = 0; k < dx.size(); k++)
	{
		bool memeChar= false;
		int i =0;
		int nbrMemeChar = 0;
		do{
			colonne = (x + i*dx[k]);
			rangee = (y + i*dy[k]);
			if(grille[colonne][rangee] = joueur)
			{
				memeChar = true;
				nbrMemeChar++;
			}
			else if (grille[colonne][rangee] = joueur)
				memeChar = false;
			
			if (nbrMemeChar >= 4){
				gagnant =true;
				break;
			}
			i++;
		}while(memeChar);
		int i =-1;
		do{
			colonne = (x + i*dx[k]);
			rangee = (y + i*dy[k]);
			if(grille[colonne][rangee] = joueur)
			{
				memeChar = true;
				nbrMemeChar++;
			}
			else if (grille[colonne][rangee] = joueur)
				memeChar = false;
			
			if (nbrMemeChar >= 4){
				gagnant =true;
				break;
			}
			i--;
		}while(memeChar);
		
	}
	return gagnant;
}

void Grille::reinitialiser()
{
	for (int i = 0; i < LONGUEUR; i++)
		for (int j = 0; j < HAUTEUR; j++)
			grille[i][j] = VIDE;
}
