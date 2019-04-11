/*
-----------------------------------------------------------------------------------
Laboratoire : 04

Fichier     : Matrice_implementation.h

Auteur(s)   : Emmanuel Janssens et Pierre-Olivier Sandoz

Date        : 11.04.2019

But         : Définition des fonctions de la classe générique Matrice

Remarque(s) : L'opération de multiplacation de deux matrices est 
 
              mathématiquement fausse

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */
#ifndef MATRICE_IMPL_H
#define MATRICE_IMPL_H

#include "Vecteur.h"
#include "Matrice.h"

template<typename T>
Matrice<T>::Matrice() {

}

template<typename T>
Matrice<T>::Matrice(std::size_t lig) {
   try {
      _data.resize(lig);
   } catch (...) {
      throw vecteur_range_error(makeMessage
              (__FILE__, __FUNCTION__, __LINE__));
   }
}

template<typename T>
Matrice<T>::Matrice(std::size_t lig, std::size_t col) {
   try {
      _data.resize(lig);
   } catch (...) {
      throw vecteur_range_error(makeMessage
              (__FILE__, __FUNCTION__, __LINE__));
   }
   for (std::size_t i = 0; i < lig; i++) {
      try {
         _data.at(i).resize(lig);
      } catch (...) {
         throw vecteur_range_error(makeMessage
                 (__FILE__, __FUNCTION__, __LINE__));
      }
   }
}

template<typename T>
Vecteur<T>& Matrice<T>::at(const std::size_t& pos) {
   if (pos < _data.size())
      return _data.at(pos);
   else {
      throw vecteur_index_error(makeMessage
              (__FILE__, __FUNCTION__, __LINE__) +
              " : could not acces proper index");
   }
}

template<typename T>
Vecteur<T> Matrice<T>::at(const std::size_t& pos) const {
   if (pos < _data.size())
      return _data.at(pos);
   else {
      throw vecteur_index_error(makeMessage
              (__FILE__, __FUNCTION__, __LINE__) +
              " : could not acces proper index");
   }
}

template<typename T>
std::size_t Matrice<T>::size() const {
   return _data.size();
}

template<typename T>
void Matrice<T>::resize(const std::size_t& lig) {
   _data.resize(lig);
}

template<typename T>
void Matrice<T>::resize(const std::size_t&lig, const std::size_t &col) {
   try {
      _data.resize(lig);
   } catch (...) {
      throw vecteur_range_error(makeMessage
              (__FILE__, __FUNCTION__, __LINE__) +
              " : could not resize vector data");
   }
   for (std::size_t i = 0; i < lig; i++) {
      try {
         _data.at(i).resize(col);
      } catch (...) {
         throw vecteur_range_error(makeMessage
                 (__FILE__, __FUNCTION__, __LINE__) +
                 " : could not resize vector data");
      }
   }
}

template<typename T>
bool Matrice<T>::estVide() const {
   bool toReturn = true;
   if (this->size()) {
      toReturn = false;
   }
   return toReturn;
}

template<typename T>
bool Matrice<T>::estReguliere() const {
   bool toReturn = true;
   if (this->size()) {
      for (std::size_t i = 1; i < this->size(); i++) {
         if (this->at(0).size() != this->at(i).size()) {
            toReturn = false;
         }
      }
   }
   return toReturn;
}

template<typename T>
bool Matrice<T>::estCarree() const {
   if (this->size()) {
      return (this->estReguliere() && (this->at(0).size() == this->size()));
   } else {
      return true;
   }
}

template<typename T>
Vecteur<T> Matrice<T>::sommeLignes() {
   Vecteur<T> toReturn(this->size());
   for (std::size_t i = 0; i < toReturn.size(); i++) {
      toReturn.at(i) = this->at(i).somme();
   }
   return toReturn;
}

template<typename T>
Vecteur<T> Matrice<T>::sommeColonnes() {
   Vecteur<T> toReturn(this->size());
   if (!estReguliere()) {
      Matrice<T> temp(this->size());
      for (std::size_t l = 0; l < temp.size(); l++) {
         temp.at(l).resize(this->at(l).size());
         for (std::size_t l2 = 0; l2 < temp.at(l).size(); l2++) {
            temp.at(l).at(l2) = this->at(l).at(l2);
         }
      }
      std::size_t maxColonne = 0;
      for (std::size_t i = 0; i < this->size(); i++) {
         if (this->at(i).size() > maxColonne) {
            maxColonne = this->at(i).size();
         }
      }
      for (std::size_t j = 0; j < temp.size(); j++) {
         temp.at(j).resize(maxColonne);
      }
      for (std::size_t k = 0; k < temp.size(); k++) {
         for (std::size_t k2 = 0; k2 < maxColonne; k2++) {
            toReturn.at(k) += temp.at(k2).at(k);
         }
      }
   } else {
      for (std::size_t k = 0; k < this->size(); k++) {
         for (std::size_t k2 = 0; k2 < this->at(k).size(); k2++) {
            toReturn.at(k) += this->at(k2).at(k);
         }
      }
   }
   return toReturn;
}

template<typename T>
std::size_t Matrice<T>::sommeDiagonaleGD() {
   std::size_t toReturn = 0;
   if (estCarree()) {
      for (std::size_t i = 0; i < this->size(); i++) {
         toReturn += this->at(i).at(i);
      }
   }else{
      throw not_square_matrix(makeMessage
              (__FILE__, __FUNCTION__, __LINE__));
   }
   return toReturn;
}

template<typename T>
std::size_t Matrice<T>::sommeDiagonaleDG() {
   std::size_t toReturn = 0;
   if (estCarree()) {
      for (std::size_t i = 0; i < this->size(); i++) {
         toReturn += this->at(i).at(this->at(i).size() - i - 1);
      }
   }else{
      throw not_square_matrix(makeMessage
              (__FILE__, __FUNCTION__, __LINE__));
   }
   return toReturn;
}

template<typename T>
Matrice<T> Matrice<T>::operator*(const T& valeur) {
   //check first
   Matrice<T> temp(this->size());
   for (std::size_t k = 0; k < temp.size(); k++) {
      temp.at(k).resize(this->at(k).size());
   }
   for (std::size_t i = 0; i < this->size(); i++) {
      for (std::size_t j = 0; j < this->at(i).size(); j++) {
         temp.at(i).at(j) = this->at(i).at(j) * valeur;
      }
   }

   return temp;
}

template<typename T >
Matrice<T> Matrice<T>::operator*(const Matrice<T>& m) {
   Matrice<T> temp(this->size());
   for (std::size_t k = 0; k < temp.size(); k++) {
      temp.at(k).resize(this->at(k).size());
   }
   if (this->size() == m.size()) {
      bool MatriceSimilar = true;
      for (std::size_t k = 0; k < this->size(); k++) {
         if (this->at(k).size() != m.at(k).size()) {
            MatriceSimilar = false;
         }
      }
      if (MatriceSimilar) {
         for (std::size_t i = 0; i < this->size(); i++) {
            for (std::size_t j = 0; j < this->at(i).size(); j++) {
               temp.at(i).at(j) = this->at(i).at(j) * m.at(i).at(j);
            }
         }
      } else {
         throw not_square_matrix(makeMessage
              (__FILE__, __FUNCTION__, __LINE__));
      }
   } else {
      throw not_square_matrix(makeMessage
              (__FILE__, __FUNCTION__, __LINE__));
   }
   return temp;
}

template<typename T >
Matrice<T> Matrice<T>::operator+(const Matrice<T>& m) {
   Matrice<T> temp(this->size());
   for (std::size_t k = 0; k < temp.size(); k++) {
      temp.at(k).resize(this->at(k).size());
   }
   if (this->size() == m.size()) {
      bool MatriceSimilar = true;
      for (std::size_t k = 0; k < this->size(); k++) {
         if (this->at(k).size() != m.at(k).size()) {
            MatriceSimilar = false;
         }
      }
      if (MatriceSimilar) {
         for (std::size_t i = 0; i < this->size(); i++) {
            for (std::size_t j = 0; j < this->at(i).size(); j++) {
               temp.at(i).at(j) = this->at(i).at(j) + m.at(i).at(j);
            }
         }
      } else {
         throw not_square_matrix(makeMessage
              (__FILE__, __FUNCTION__, __LINE__));
      }
   } else {
      throw not_square_matrix(makeMessage
              (__FILE__, __FUNCTION__, __LINE__));
   }
   return temp;
}


#endif //MATRICE_IMPL_H