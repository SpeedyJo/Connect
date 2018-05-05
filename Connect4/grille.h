#pragma once
//#include <vector>

const int HAUTEUR = 6;
const int LONGUEUR = 7;

class Grille
{
private:
	Grille();

public:
	static Grille& instance();
	bool ajouter(char joueur, int rangee);
	bool verifierGagnant() const;
	void reinitialiser();
	void afficher();

	const int HAUT = HAUTEUR;
	const int LONG = LONGUEUR;
	const char VIDE = '-';

	//~Grille();
};