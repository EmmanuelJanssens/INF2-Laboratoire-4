#ifndef MATRICE_H
#define MATRICE_H

#include "Vecteur.h"

template <typename T> class Matrice;

template <typename T>
std::ostream& operator<<(std::ostream &os, const Matrice<T>& m) {
   os << "[";
   for (std::size_t i = 0; i < m.size(); i++) {
      os << "[";
      for (std::size_t j = 0; j < m.at(i).size(); j++) {
         os << m.at(i).at(j) << ", ";
      }
      os << "]";
   }
   os << "] ";
   return os;
}

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
   friend std::ostream& operator<< <T>(std::ostream& os, const Matrice<T>& m);
   friend Matrice<T> operator* <T>(const T&valeur, const Matrice<T>& m);

public:

   Matrice();
   Matrice(std::size_t l);
   Matrice(std::size_t l, std::size_t c);

   Vecteur<T>& at(const std::size_t& pos);
   Vecteur<T> at(const std::size_t& pos)const;

   std::size_t size() const;

   void resize(const std::size_t& l);
   void resize(const std::size_t& l, const std::size_t &c);

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

private:

   Vecteur<Vecteur<T>> _data;
};


#include "Matrice_implementation.h"

#endif

