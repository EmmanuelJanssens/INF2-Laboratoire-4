	
#ifndef VECTEUR_IMPLEM_H
#define VECTEUR_IMPLEM_H

#include "Vecteur.h"

template <typename T>
Vecteur<T>::Vecteur(std::size_t n)
{
	try
	{
		_data.resize(n);
	}
	catch (...)
	{

	}
}

template <typename T>
Vecteur<T>::Vecteur(const std::vector<T>& t)
{
	try
	{
		_data.resize(t.size());
		std::copy(t.begin(), t.end(), _data.begin());
	}
	catch (...)
	{

	}

}

template <typename T>
T& Vecteur<T>::at(std::size_t pos)
{
	
	if (pos < _data.size())
	{
		return _data.at(pos);
	}
    else
    {			
		throw index_error(makeMessage(__FILE__,__FUNCTION__,__LINE__));
    }
  
}
template <typename T>
const T& Vecteur<T>::at(std::size_t pos)const
{
	if (pos < _data.size())
	{
	return _data.at(pos);
	}
	else
	{
		throw index_error(makeMessage(__FILE__, __FUNCTION__, __LINE__));
	}

}
template <typename T>
std::size_t Vecteur<T>::size()const
{
	try 
	{
		return _data.size();
	}
	catch (...)
	{
		throw vecteur_length_error(makeMessage(__FILE__, __FUNCTION__, __LINE__));
	}
}

template <typename T>
void Vecteur<T>::resize(std::size_t size)
{
    _data.resize(size,0);
}

template <typename T>
Vecteur<T> Vecteur<T>::operator*( const T& valeur)
{
	Vecteur<T> temp(this->size());
	//check first
    for(std::size_t i = 0; i < this->_data.size(); i++)
    {
        temp.at(i) = this->at(i) * valeur;
    }

	return temp;

}
template <typename T>
Vecteur<T> Vecteur<T>::operator*(const Vecteur<T>& valeur)
{
	Vecteur<T> temp(this->size());
	//check first
	for (std::size_t i = 0; i < this->_data.size(); i++)
	{
		temp.at(i) = this->at(i) * valeur.at(i);
	}

	return temp;
}


template <typename T>
Vecteur<T> Vecteur<T>::operator+( const Vecteur<T>& v)
{
	//check first
	//throw sizedifferece("
	for (std::size_t i = 0; i < this->_data.size(); i++)
	{
		this->at(i) = this->at(i) + v.at(i);
	}

	return *this;
}
template <typename T>
Vecteur<T>& Vecteur<T>::operator-(const Vecteur<T>& v)
{

	//check first
	for (std::size_t i = 0; i < this->_data.size(); i++)
	{
		this->at(i) = this->at(i) - v.at(i);
	}

	return *this;
}

#endif
