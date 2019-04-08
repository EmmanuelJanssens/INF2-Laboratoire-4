#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>
#include <iostream>
#include "Exception.h"
template <typename T> class Vecteur;

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

template <typename T>
Vecteur<T> operator*(const T &valeur, const Vecteur<T>& v) {
   Vecteur<T> res(v.size());

   //check first
   for (std::size_t i = 0; i < v.size(); i++) {
      res .at(i) = v.at(i) * valeur;
   }

   return res;
}

template <typename T>
class Vecteur {
   friend std::ostream& operator<< <T>(std::ostream &os, const Vecteur<T>& v);

   friend Vecteur<T> operator*<T>(const T &valeur, const Vecteur<T>& v);


public:

   Vecteur(std::size_t n);
   Vecteur(const std::vector<T>& t);

   // friend std::ostream& operator<< <T>(std::ostream &os, const Vecteur<T>& v);

   /**
    * @brief 
    * 
    * @param pos 
    * @return T& 
    */
   T& at(std::size_t pos);
   const T& at(std::size_t pos)const;

   /**
    * @brief 
    * 
    * @param size 
    */
   void resize(std::size_t size);

   /**
    * @brief 
    * 
    */
   std::size_t size()const;

   /**
    * @brief 
    * 
    */
   std::size_t somme();


   /**
    * @brief 
    * 
    * @param valeur 
    */
   Vecteur operator*(const T& valeur);

   /**
    * @brief 
    * 
    * @param v 
    */
   Vecteur operator*(const Vecteur<T>& v);

   /**
    * @brief 
    * 
    * @param v 
    */
   Vecteur operator+(const Vecteur<T>& v);

   /**
    * @brief 
    * 
    */
   Vecteur operator-(const Vecteur<T>& v);


private:
   std::vector<T> _data;

};

#include "Vecteur_implementation.h"

#endif //VECTEUR_H