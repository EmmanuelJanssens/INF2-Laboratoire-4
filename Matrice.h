#ifndef MATRICE_H
#define MATRICE_H

#include "Vecteur.h"

template <typename T> class Matrice;


template <typename T>
std::ostream& operator<<(std::ostream &os, const Matrice<T>& m)
{
	
	return os;
}

template <typename T>
Matrice<T> operator*(const T &valeur, const Matrice<T>& m)
{

}


template< typename T>
class Matrice
{
	friend std::ostream& operator<< <T>(std::ostream& os, const Matrice<T>& m);
	friend Matrice<T> operator* <T>(const T&valeur, const Matrice<T>& m);

	Matrice();
	Matrice(std::size_t l);
	Matrice(std::size_t l, std::size_t c);

	Vecteur<T>& at(const std::size_t& pos);
	Vecteur<T> at(const std::size_t& pos)const;

	std::size_t size() const;

	void resize(const std::size_t& l);
	void resize(const std::size_t& l,const std::size_t &c);

	bool estVide()const;

	bool estCarree() const;

	bool estReguliere() const;

	Vecteur<T> sommeLignes();
	Vecteur<T> sommeColonnes();
	Vecteur<T> sommeDiagonaleGD();
	Vecteur<T> sommeDiagonaleDG();

	Matrice<T> operator*(const T& valeur);
	Matrice<T> operator*(const Matrice<T>& m);
	Matrice<T> operator+(const Matrice<T>& m);
};


#include "Matrice_implementation.h"

#endif

