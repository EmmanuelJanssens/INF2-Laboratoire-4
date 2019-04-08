#ifndef MATRICE_IMPL_H
#define MATRICE_IMPL_H

template<typename T>
Matrice<T>::Matrice(){}

template<typename T>
Matrice<T>::Matrice(std::size_t l)
{

}

template<typename T>
Matrice<T>::Matrice(std::size_t l, std::size_t c)
{

}


template<typename T>
Vecteur<T>& Matrice<T>::at(const std::size_t& pos)
{

}

template<typename T>
Vecteur<T> Matrice<T>::at(const std::size_t& pos) const
{

}

template<typename T>
std::size_t Matrice<T>::size() const
{

}

template<typename T>
void Matrice<T>::resize(const std::size_t& l)
{

}

template<typename T>
void Matrice<T>::resize(const std::size_t&l, const std::size_t &c)
{

}

template<typename T>
bool Matrice<T>::estVide() const
{

}

template<typename T>
bool Matrice<T>::estReguliere()const
{

}

template<typename T>
bool Matrice<T>::estCarree() const
{

}

template<typename T>
Vecteur<T> Matrice<T>::sommeLignes()
{

}

template<typename T>
Vecteur<T> Matrice<T>::sommeColonnes()
{

}

template<typename T>
Vecteur<T> Matrice<T>::sommeDiagonaleGD()
{

}

template<typename T>
Vecteur<T> Matrice<T>::sommeDiagonaleDG()
{

}

template<typename T>
Matrice<T> Matrice<T>::operator*(const T& valeur)
{

}

template<typename T>
Matrice<T> Matrice<T>::operator*(const Matrice<T>& m)
{

}

template<typename T>
Matrice<T> Matrice<T>::operator+(const Matrice<T>& m)
{

}


#endif //MATRICE_IMPL_H