/*
-----------------------------------------------------------------------------------
Laboratoire : 04

Fichier     : main.cpp

Auteur(s)   : Emmanuel Janssens et Pierre-Olivier Sandoz

Date        : 11.04.2019

But         : le but de se laboratoire est de créer deux classes génériques,

              Vecteur et Matrice, implémentant plusieurs fonctions effectuant
 
              diverses opérations. Le but étant de nous familiariser avec 
   
              l'utilisation des exceptions.

Remarque(s) : -

Compilateur : MinGW-g++ 6.3.0
-----------------------------------------------------------------------------------
 */
#include "Matrice.h"


using namespace std;

int main() {
   try {
      Vecteur<int> v({1000, 20000, 50000});
      Vecteur<int> v2({2, 3});
      Vecteur<int> v3({2020202020, 20200202, 20202});
      Vecteur<int> test;

      //Test on vecteurs//
      //Vecteur<int> v4(10000000000);	//OK
      //v.at(4);						//OK
      //v.resize(10000000000);		//OK
      //v.resize(-1);					//OK
      //test = v2 * v3;				//OK
      //test = v + v2;				//OK	
      //v2 = v2 - v3;					//OK

      cout << v << endl;

      Matrice<int> m(5, 5);
      cout << m << endl;
      for (size_t i = 0; i < m.size(); i++) {
         for (size_t j = 0; j < m.at(i).size(); j++) {
            m.at(i).at(j) = 2;
         }
      }
      for (size_t k = 0; k < m.size(); k++) {
         m.at(k).resize(k + 1);
      }
      cout << m << endl;

      Matrice<int> m3(3, 3);
      m3.at(0).at(0) = 1;
      m3.at(0).at(1) = 2;
      m3.at(0).at(2) = 3;
      m3.at(1).at(0) = 4;
      m3.at(1).at(1) = 5;
      m3.at(1).at(2) = 6;
      m3.at(2).at(0) = 7;
      m3.at(2).at(1) = 8;
      m3.at(2).at(2) = 9;
      cout << m3 << endl;
      Matrice<int> m4 = m3;
      cout << m4 << endl;

      Matrice<int> m5(5);
      cout << m5 << endl;
      m5.resize(7);
      cout << m5 << endl;
      cout << m5.at(2).at(2);
   } catch (exception& e) {
      cout << e.what() << endl;
      system("PAUSE");
      return EXIT_FAILURE;
   }


   system("PAUSE");
   return 0;
}