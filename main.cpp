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
      Vecteur<int> v1({1000, 20000, 50000});
      Vecteur<int> v2({2, 3});
      Vecteur<int> v3({2020202020, 20200202, 20202});
      Vecteur<int> test;

      Vecteur<string> v6({"abc","vwx","def"});
      cout << "somme v6: " << v6.somme() << endl;
      Vecteur<float> v5({1.1,2.2,3.3});
      cout << "v5: " << v5 << endl;
      cout << "somme v5: " << v5.somme() << endl;
      v5.resize(7);
      cout << "taille v5: " << v5.size() << endl;
      cout << "v1*3: " << v1*3 << endl;
      cout << "v1+v3: " << v1+v3 << endl;
      cout << "v1*v3: " << v1*v3 << endl;
      cout << "v1-v3: " << v1-v3 << endl;
      
      //Tests sur vecteurs qui levent des exceptions//
      //Vecteur<int> v4(10000000000);	//OK
      //v.at(4);			//OK
      //v.resize(10000000000);		//OK
      //v.resize(-1);			//OK
      //test = v2 * v3;			//OK
      //test = v1 + v2;			//OK	
      //v2 = v2 - v3;			//OK

      Matrice<int> m1(5, 5);
      for (size_t i = 0; i < m1.size(); i++) {
         for (size_t j = 0; j < m1.at(i).size(); j++) {
            m1.at(i).at(j) = 2;
         }
      }
      for (size_t k = 0; k < m1.size(); k++) {
         m1.at(k).resize(k + 1);
      }
      cout << "m1: " << m1 << endl;
      cout << "somme lignes m1: " << m1.sommeLignes() << endl;
      cout << "somme colonnes m1: " << m1.sommeColonnes() << endl;
      Matrice<int> m3(3, 3);
      m3.at(0).at(0) = 1; m3.at(0).at(1) = 2; m3.at(0).at(2) = 3;
      m3.at(1).at(0) = 4; m3.at(1).at(1) = 5; m3.at(1).at(2) = 6;
      m3.at(2).at(0) = 7; m3.at(2).at(1) = 8; m3.at(2).at(2) = 9;
      cout << "m3: " << m3 << endl;
      cout << "m3 est regulier: " << m3.estReguliere() << endl;
      cout << "m3 est carree: " << m3.estCarree() << endl;
      cout << "m3 est vide: " << m3.estVide() << endl;
      cout << "somme diagonalesGD m3: " << m3.sommeDiagonaleGD() << endl;
      cout << "somme diagonalesDG m3: " << m3.sommeDiagonaleDG() << endl;
      Matrice<int> mVide;
      cout << "mVide: " << mVide << endl;
      cout << "mVide est regulier: " << mVide.estReguliere() << endl;
      cout << "mVide est carree: " << mVide.estCarree() << endl;
      cout << "mVide est vide: " << mVide.estVide() << endl;
      Matrice<int> m4 = m3;
      cout << "m4 = m3: " << m4 << endl;
      cout << "m4 + m3: " << m4+m3 << endl;
      cout << "m4 * m3: " << m4*m3 << endl;
      cout << "m4 * 3: " << m4*3 << endl;
      Matrice<int> m5(5,1);

      //Tests sur matrices qui levent des exceptions//
      
      //Matrice<int> somme = m5 + m3;	//OK
      //Matrice<int> mult = m5 * m3;	//OK
      //m5.sommeDiagonaleDG();		//OK
      //m5.sommeDiagonaleGD();		//OK
      //m5.resize(7890987000);		//OK
      //m5.at(10);			//OK
      //m5.at(0).at(100);		//OK
      //mVide.sommeDiagonaleGD()        //OK
      //mVide.sommeDiagonaleDG()        //OK

   } catch (exception& e) {
      cout << e.what() << endl;
      system("PAUSE");
      return EXIT_FAILURE;
   }


   system("PAUSE");
   return 0;
}