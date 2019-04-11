/*
-----------------------------------------------------------------------------------
Laboratoire : 04

Fichier     : Vecteur.h

Auteur(s)   : Emmanuel Janssens et Pierre-Olivier Sandoz

Date        : 11.04.2019

But         : Déclaration des fonctions de la classe générique Vecteur

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/
#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <iostream>
#include <string>

#include "Exception.h"
template <typename T> class Vecteur;

// Surcharge de l'opérateur de flux de sortie
template <typename T>
std::ostream& operator<<(std::ostream &os, const Vecteur<T>& v) {
   if(v.size() > 1){
   os << "[" << v.at(0);
   for (std::size_t i = 1; i < v.size(); i++) {
      os << ", " << v.at(i);
   }
   os << "] ";
   }
   else{
      os << "[" << v.at(0) << "] ";
   }
   return os;
}

// Surcharge de l'opérateur de multiplication d'une matrice 
template <typename T>
Vecteur<T> operator*(const T &valeur, const Vecteur<T>& v) {
   Vecteur<T> res(v.size());

   for (std::size_t i = 0; i < v.size(); i++) {
      res .at(i) = v.at(i) * valeur;
   }

   return res;
}

template <typename T>
class Vecteur
{
   /**
     * @brief Surcharge de l'opérateur de flux de sortie
     * 
     * @param os : le flux de sortie 
     * @param v
     * @return ostream& : le flux de sortie 
     */
    friend std::ostream& operator<< <T>(std::ostream &os,  const Vecteur<T>& v);
    /**
     * @brief Surcharge de l'opérateur de multiplication d'une matrice 
     * par une valeur
     * 
     * @param valeur 
     * @param m
     * @return Matrice<T> 
     */
    friend Vecteur<T> operator*<T>(const T &valeur, const Vecteur<T>& v);

    
    public:

    Vecteur(std::size_t n = 0);
    Vecteur(const std::vector<T>& t);

   // friend std::ostream& operator<< <T>(std::ostream &os, const Vecteur<T>& v);

    /**
     * @brief Accès à l’élément en position pos (lecteur et écriture)
     * 
     * @param pos 
     * @return T& 
     */
    T& at(std::size_t pos) ;
	const T& at(std::size_t pos)const ;

    /**
     * @brief Redimensionne le vecteur
     * 
     * @param size 
     */
    void resize(std::size_t size);

    /**
     * @brief Retourne la taille actuelle
     * 
     * @return size_t
     */
    std::size_t size()const;

    /**
     * @brief Retourne la somme des éléments contenus
     * 
     * @return T
     */
    T somme();


    /**
     * @brief Multiplie chaque élément par valeur et retour le
     *        vecteur correspondant
     * 
     * @param valeur 
     * @return Vecteur
     */
    Vecteur operator*( const T& valeur);

    /**
     * @brief Multiplie chaque élément entre eux et retourne le
     *        vecteur correspondant
     * 
     * @param v 
     * @return Vecteur
     */
	Vecteur operator*( const Vecteur<T>& v);

    /**
     * @brief Retourne un vecteur correspondant à l’addition de 
     *        chacun des éléments
     * 
     * @param v 
     * @return Vecteur
     */
	Vecteur operator+( const Vecteur<T>& v);

    /**
     * @brief Retourne un vecteur correspondant à la soustraction de 
     *        chacun des éléments
     * 
     * @param v 
     * @return Vecteur
     */
	Vecteur operator-(const Vecteur<T>& v);

    
    private:
    std::vector<T> _data;

};

#include "Vecteur_implementation.h"

#endif //VECTEUR_H