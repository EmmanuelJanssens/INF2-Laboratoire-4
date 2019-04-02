#ifndef VECTEUR_H
#define VECTEUR_H

#include <vector>

template <typename T>
class Vecteur
{
    public:

    Vecteur(T n);
    Vecteur(std::vector<T> t);


    

    T operator*(T val);
    
    private:


};

#endif //VECTEUR_H