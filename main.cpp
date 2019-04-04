#include "Vecteur.h"


using namespace std;


int main()
{	

    Vecteur<int> v({5,6,7});
	Vecteur<int> test(v.size());
	

    test = v*4;
    cout<<test<<endl ;


	system("PAUSE");
    return 0;
}