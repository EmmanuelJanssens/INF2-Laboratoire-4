/*
-----------------------------------------------------------------------------------
Laboratoire : 04

Fichier     : Vecteur_implementation.h

Auteur(s)   : Emmanuel Janssens et Pierre-Olivier Sandoz

Date        : 11.04.2019

But         : Définition des fonctions de la classe générique Vecteur

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
*/
#ifndef VECTEUR_IMPLEM_H
#define VECTEUR_IMPLEM_H




//runtime error

template <typename T>
Vecteur<T>::Vecteur(std::size_t n) {
   try {
      _data.resize(n);
   } catch (...) {
      throw vecteur_range_error(makeMessage
              (__FILE__, __FUNCTION__, __LINE__));
   }
}

//runtime error

template <typename T>
Vecteur<T>::Vecteur(const std::vector<T>& t) {
   try {
      _data.resize(t.size());
      std::copy(t.begin(), t.end(), _data.begin());
   } catch (...) {
      throw vecteur_range_error(makeMessage
              (__FILE__, __FUNCTION__, __LINE__));
   }
}


//logic error

template <typename T>
T& Vecteur<T>::at(std::size_t pos) {
   if (pos < _data.size()) {
      return _data.at(pos);
   } else {
      throw vecteur_index_error(makeMessage
              (__FILE__, __FUNCTION__, __LINE__) +
              " : could not acces proper index");
   }

}

//logic error

template <typename T>
const T& Vecteur<T>::at(std::size_t pos)const {
   if (pos < _data.size()) {
      return _data.at(pos);
   } else {
      throw vecteur_index_error(makeMessage
              (__FILE__, __FUNCTION__, __LINE__) +
              " : could not acces proper index");
   }

}

//No exception

template <typename T>
std::size_t Vecteur<T>::size()const {
   return _data.size();
}

//runtime error

template <typename T>
void Vecteur<T>::resize(std::size_t size) {
   try {
      _data.resize(size, 0);
   } catch (...) {
      throw vecteur_range_error(makeMessage
              (__FILE__, __FUNCTION__, __LINE__) +
              " : could not resize vector data");
   }
}

//numeric error

template <typename T>
Vecteur<T> Vecteur<T>::operator*(const T& valeur) {
   Vecteur<T> temp(this->size());
   //check first
   for (std::size_t i = 0; i < this->_data.size(); i++) {
      temp.at(i) = this->at(i) * valeur;
   }

   return temp;

}

//numeric error

template <typename T>
Vecteur<T> Vecteur<T>::operator*(const Vecteur<T>& vecteur) {

   if (vecteur.size() != this->size())
      throw vector_length_mismatch(makeMessage
           (__FILE__, __FUNCTION__, __LINE__) +
           " : Trying to multiply vectors of different length");

   Vecteur<T> temp(this->size());
   //check first
   for (std::size_t i = 0; i < this->_data.size(); i++) {
      temp.at(i) = this->at(i) * vecteur.at(i);
   }

   return temp;
}

//numeric error

template <typename T>
Vecteur<T> Vecteur<T>::operator+(const Vecteur<T>& v) {
   if (v.size() != this->size())
      throw vector_length_mismatch(makeMessage
           (__FILE__, __FUNCTION__, __LINE__) +
           " : Trying to add vectors of different length");
   Vecteur<T> temp(this->size());
   //check first
   //throw sizedifferece("
   for (std::size_t i = 0; i < this->_data.size(); i++) {
      temp = this->at(i) + v.at(i);
   }

   return temp;
}

//numeric error

template <typename T>
Vecteur<T>& Vecteur<T>::operator-(const Vecteur<T>& v) {
   Vecteur<T> temp(this->size());
   //check first
   for (std::size_t i = 0; i < this->_data.size(); i++) {
      this->at(i) = this->at(i) - v.at(i);
   }

   return temp;
}

template <typename T>
std::size_t Vecteur<T>::somme() {
   if (this->size()) {
      T toReturn = this->at(0);
      for (std::size_t i = 1; i < this->size(); i++) {
         toReturn += this->at(i);
      }
      return toReturn;
   }
}
#endif
