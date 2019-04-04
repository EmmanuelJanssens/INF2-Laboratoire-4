
#ifndef VECTEUR_IMPLEM_H
#define VECTEUR_IMPLEM_H

template <typename T>
Vecteur<T>::Vecteur(std::size_t n)
{
    _data.resize(n);
}

template <typename T>
Vecteur<T>::Vecteur(const std::vector<T>& t)
{
    _data.resize(t.size());
    std::copy(t.begin(), t.end(), _data.begin());
}


template <typename T>
T& Vecteur<T>::at(std::size_t pos)
{
    if(pos < _data.size() )
        return _data.at(pos);
    else
    {
        //error 
    }
    
}
template <typename T>
const T& Vecteur<T>::at(std::size_t pos)const
{
	if (pos < _data.size())
		return _data.at(pos);
	else
	{
		//error 
	}

}
template <typename T>
std::size_t Vecteur<T>::size()const
{
    return _data.size();
}

template <typename T>
void Vecteur<T>::resize(std::size_t size)
{
    _data.resize(size,0);
}

template <typename T>
Vecteur<T>& Vecteur<T>::operator*( T valeur)
{

    for(std::size_t i = 0; i < this->_data.size(); i++)
    {
        this->at(i) = this->at(i) * valeur;
    }

	return *this;

}

template <typename T>
Vecteur<T>& Vecteur<T>::operator+( const Vecteur<T>& v)
{
    //vérifier si la taille des vecteurs est simiaire
}

#endif
