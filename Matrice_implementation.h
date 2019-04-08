#ifndef MATRICE_IMPL_H
#define MATRICE_IMPL_H

#include "Vecteur.h"

template<typename T>
Matrice<T>::Matrice() {

}

/*
template<typename T>
Matrice<T>::Matrice(std::size_t l)
{

}
 */
template<typename T>
Matrice<T>::Matrice(std::size_t l, std::size_t c = 0) {
   _data.resize(l);
   if (c) {
      for (std::size_t i = 0; i < l; i++) {
         _data.at(i).resize(c);
      }
   }
}

template<typename T>
Vecteur<T>& Matrice<T>::at(const std::size_t& pos) {
   if (pos < _data.size())
      return _data.at(pos);
   else {
      //error 
   }
}

template<typename T>
Vecteur<T> Matrice<T>::at(const std::size_t& pos) const {
   if (pos < _data.size())
      return _data.at(pos);
   else {
      //error 
   }
}

template<typename T>
std::size_t Matrice<T>::size() const {
   return _data.size();
}

template<typename T>
void Matrice<T>::resize(const std::size_t& l) {
   _data.resize(l);
}

template<typename T>
void Matrice<T>::resize(const std::size_t&l, const std::size_t &c) {
   _data.resize(l);
   for (std::size_t i = 0; i < l; i++) {
      _data.at(i).resize(c);
   }
}

template<typename T>
bool Matrice<T>::estVide() const {

}

template<typename T>
bool Matrice<T>::estReguliere()const {

}

template<typename T>
bool Matrice<T>::estCarree() const {

}

template<typename T>
Vecteur<T> Matrice<T>::sommeLignes() {

}

template<typename T>
Vecteur<T> Matrice<T>::sommeColonnes() {

}

template<typename T>
Vecteur<T> Matrice<T>::sommeDiagonaleGD() {

}

template<typename T>
Vecteur<T> Matrice<T>::sommeDiagonaleDG() {

}

template<typename T>
Matrice<T> Matrice<T>::operator*(const T& valeur) {

}

template<typename T>
Matrice<T> Matrice<T>::operator*(const Matrice<T>& m) {

}

template<typename T>
Matrice<T> Matrice<T>::operator+(const Matrice<T>& m) {

}


#endif //MATRICE_IMPL_H