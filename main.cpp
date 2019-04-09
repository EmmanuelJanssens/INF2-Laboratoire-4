#include "Matrice.h"


using namespace std;


int main()
{	
	try
	{
		Vecteur<int> v({ 1000,20000,50000 });
		Vecteur<int> v2({ 2,3 });
		Vecteur<int> v3({ 2020202020,20200202,20202 });
		Vecteur<int> test;

		/*Test on vecteurs*/
		//Vecteur<int> v4(10000000000);	//OK
		//v.at(4);						//OK
		//v.resize(10000000000);		//OK
		//v.resize(-1);					//OK
		//test = v2 * v3;				//OK
		//test = v + v2;				//OK	
		//v2 = v2 - v3;					//OK

		cout << v << endl;

	}
	catch (exception& e)
	{
		cout << e.what() << endl;
		system("PAUSE");
		return EXIT_FAILURE;
	}

	system("PAUSE");
    return 0;
}