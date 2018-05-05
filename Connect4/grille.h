#pragma once
//#include <vector>
#include <tuple>

const int HAUTEUR = 6;
const int LONGUEUR = 7;

class Grille
{
private:
	Grille();
	std::tuple<int, int> positionCourante;
public:
	static Grille& instance();
	bool ajouter(char joueur, int rangee);
	bool verifierGagnant(char joueur) const;
	void reinitialiser();
	void afficher();

	const int HAUT = HAUTEUR;
	const int LONG = LONGUEUR;
	const char VIDE = '-';

	//~Grille();
};