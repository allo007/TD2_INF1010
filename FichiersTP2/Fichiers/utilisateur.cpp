/********************************************
* Titre: Travail pratique #2 - utilisateur.cpp
* Date: 2 octobre 2018
* Auteurs: Raphael Geoffrion et Jules Lefebvre
*******************************************/

#include "utilisateur.h"

// Constructeurs
Utilisateur::Utilisateur() : nom_(""), nombreDepenses_(0){
}

Utilisateur::Utilisateur(const string& nom)
	: nom_(nom), nombreDepenses_(0) {
}

Utilisateur::Utilisateur(const Utilisateur & utilisateur) 
	: nom_(utilisateur.nom_), nombreDepenses_(utilisateur.nombreDepenses_), depenses_(utilisateur.depenses_) {
}

//Destructeur
Utilisateur::~Utilisateur() {
	for (unsigned int i = 0; i < depenses_.size(); i++)
	{
		delete depenses_[i];
		depenses_[i] = nullptr;
	}
}

// Methodes d'acces
string Utilisateur::getNom() const {
	return nom_;
}

unsigned int Utilisateur::getNombreDepense() const {
	return nombreDepenses_;
}

double Utilisateur::getTotalDepenses() const {
	double total = 0;
	for (unsigned int i = 0; i < nombreDepenses_; i++) {
		total += depenses_[i]->getMontant();
	}
	return total;
}

vector< Depense* > Utilisateur::getDepenses() const {

	return depenses_;
}


//Methodes de modification
void Utilisateur::setNom(const string& nom) {
	nom_ = nom;
}

Utilisateur & Utilisateur::operator+=(Depense* pointeurDepense)
{
	nombreDepenses_++;
	depenses_.push_back(pointeurDepense);
	return *this;
}

Utilisateur & Utilisateur::operator=(const Utilisateur & utilisateur)
{
	if (this != &utilisateur) {

		nom_ = utilisateur.nom_;
		nombreDepenses_ = utilisateur.nombreDepenses_;
		for (unsigned int i = 0; i < depenses_.size(); i++)
		{
			delete depenses_[i];
			depenses_[i] = nullptr;
		}
		depenses_ = utilisateur.depenses_;
	}
	return *this;
}

// Methode d'affichage
ostream& operator<<(ostream& os, const Utilisateur& utilisateur)
{
	os << "Utilisateur : " << utilisateur.getNom() << " a depense pour un total de : " << utilisateur.getTotalDepenses() << endl
		<< "\t Liste de depenses : " << endl;
	for (unsigned int i = 0; i < utilisateur.nombreDepenses_; i++) {
		cout << "\t\t" << (*utilisateur.depenses_[i]);
	}
	return os;
}