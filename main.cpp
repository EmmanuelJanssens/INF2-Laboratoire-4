#include "Matrice.h"


using namespace std;

int main() {

   Vecteur<int> v({5, 6, 7});
   Vecteur<int> test(v.size());

   cout << v.somme() << endl;

   test = v * 4;
   cout << test << endl;
   test = 4 * v;
   cout << test << endl;
   test = test + v;
   cout << test << endl;
   test = v - test;
   cout << test << endl;


   system("PAUSE");
   return 0;
}