/*
-----------------------------------------------------------------------------------
Laboratoire : 04

Fichier     : Matrice.h

Auteur(s)   : Emmanuel Janssens et Pierre-Olivier Sandoz

Date        : 11.04.2019

But         : Déclaration des fonctions de la classe générique Matrice

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/
#ifndef MATRICE_H
#define MATRICE_H

#include "Vecteur.h"

template <typename T> class Matrice;

// Surcharge de l'opérateur de flux de sortie
template <typename T>
std::ostream& operator<<(std::ostream &os, const Matrice<T>& m) {
   os << "[";
   for (std::size_t i = 0; i < m.size(); i++) {
      os << "[";
      for (std::size_t j = 0; j < m.at(i).size(); j++) {
         os << m.at(i).at(j);
         if( j != m.at(i).size() - 1){
            os << ", ";
         }
      }
      os << "]";
   }
   os << "] ";
   return os;
}

// Surcharge de l'opérateur de multiplication d'une matrice par une valeur
template <typename T>
Matrice<T> operator*(const T &valeur, const Matrice<T>& m) {
   Matrice<T> res(m.size());
   for(std::size_t k = 0; k < res.size(); k++){
      res.at(k).resize(m.at(k).size());
   }
   //check first
   for (std::size_t i = 0; i < m.size(); i++) {
      for (std::size_t j = 0; j < res.at(i).size(); j++) {
         res .at(i).at(j) = m.at(i).at(j) * valeur;
      }
   }
   return res;
}

template< typename T>
class Matrice {
   /**
     * @brief Surcharge de l'opérateur de flux de sortie
     * 
     * @param os : le flux de sortie 
     * @param m
     * @return ostream& : le flux de sortie 
     */
   friend std::ostream& operator<< <T>(std::ostream& os, const Matrice<T>& m);
   /**
     * @brief Surcharge de l'opérateur de multiplication d'une matrice 
     * par une valeur
     * 
     * @param valeur 
     * @param m
     * @return Matrice<T> 
     */
   friend Matrice<T> operator* <T>(const T&valeur, const Matrice<T>& m);

public:

   Matrice();
   Matrice(std::size_t lig);
   Matrice(std::size_t lig, std::size_t col);

   /**
     * @brief Accès au vecteur en position pos (lecteur et écriture)
     * 
     * @param pos 
     * @return Vecteur<T>& 
     */
   Vecteur<T>& at(const std::size_t& pos);
   
   /**
     * @brief Accès au vecteur en position n (lecteur et écriture)
     * 
     * @param pos 
     * @return Vecteur<T>& 
     */
   Vecteur<T> at(const std::size_t& pos)const;

   /**
     * @brief Retourne la taille actuelle (nbre de lignes)
     * 
     * @return size_t la taille du Vecteur 
     */
   std::size_t size() const;

   /**
     * @brief Redimensionne le vecteur à lig lignes
     * 
     * @param lig 
     */
   void resize(const std::size_t& lig);
   
   /**
     * @brief Redimensionne le vecteur à lig lignes et col colonnes
     * 
     * @param lig
     * @param col  
     */
   void resize(const std::size_t& lig, const std::size_t &col);

   /**
     * @brief Indique que la matrice est vide
     * 
     * @return bool 
     */
   bool estVide()const;

   /**
     * @brief Indique que la matrice est carrée. 
     * Par convention une matrice vide est carrée
     * 
     * @return bool 
     */
   bool estCarree() const;

   /**
     * @brief Indique que toutes les lignes ont la même longueur. 
     * Par convention une matrice vide est régulière
     * 
     * @return bool 
     */
   bool estReguliere() const;

   /**
     * @brief Retourne un vecteur contenant la somme de chaque ligne
     * 
     * @return Vecteur<T> 
     */
   Vecteur<T> sommeLignes();
   
   /**
     * @brief Retourne un vecteur contenant la somme de chaque colonne
     * 
     * @return Vecteur<T> 
     */
   Vecteur<T> sommeColonnes();
   
   /**
     * @brief Retourne la somme des valeurs de la diagonale Gauche-Droite
     * 
     * @return size_t 
     */
   T sommeDiagonaleGD();
   
   /**
     * @brief Retourne la somme des valeurs de la diagonale Droite-Gauche
     * 
     * @return size_t 
     */
   T sommeDiagonaleDG();

   /**
     * @brief Retourne la matrice dont tous les éléments ont été multipliés 
     * par valeur.
     * 
     * @param valeur 
     * @return Matrice<T> 
     */
   Matrice<T> operator*(const T& valeur);
   
   /**
     * @brief Retourne une matrice dont tous les éléments ont été multipliés 
     * par les éléments correspondants. L’opération est possible seulement si 
     * les matrices ont strictement la même forme
     * 
     * @param m 
     * @return Matrice<T> 
     */
   Matrice<T> operator*(const Matrice<T>& m);
   
   /**
     * @brief Retourne une matrice dont tous les éléments ont été additionnés 
     * avec les éléments correspondants. L’opération est possible seulement si 
     * les matrices ont strictement la même forme
     * 
     * @param m 
     * @return Matrice<T> 
     */
   Matrice<T> operator+(const Matrice<T>& m);
   
private:

   Vecteur<Vecteur<T>> _data;
};


#include "Matrice_implementation.h"

#endif

