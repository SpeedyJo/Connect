#pragma once
//#include <vector>

const int HAUTEUR = 6;
const int LONGUEUR = 7;
const char VIDE = '-';

class Grille
{
private:
	Grille();

public:
	static Grille& instance();
	bool ajouter(char joueur, int rangee);
	bool verifierGagnant() const;
	void reinitialiser();

	//~Grille();
};