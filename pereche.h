
#include "cuvant.h"
#include "defs.h"
using namespace std;
//pair
template <typename T, typename M>
class pereche
{
    T cuvi;
    M def;

public:
    pereche();
    pereche(T a, M b);
    T get_cuvant();
   friend ostream& operator<<(ostream& dev, const pereche &a)
   {

    dev<<a.cuvi<<"="<<a.def;
    return dev;

   }
   friend istream& operator>>(istream& dev, pereche &a)
   {
    dev>>a.cuvi>>a.def;
    return dev;
   }
   bool operator<(const pereche<T,M> &f1) const;
         bool operator>(const pereche<T,M> &f1) const;
         bool operator==(const pereche<T,M> &f1) const;

         bool operator!=(const pereche<T,M> &f1) const;
};
template <typename T, typename M>
bool pereche<T,M>::operator<(  const pereche<T,M> &f1) const
{
    return (this->cuvi<f1.cuvi);
}
template <typename T, typename M>
bool pereche<T,M>::operator> (const  pereche<T,M> &f1) const
{
    return (this->cuvi>f1.cuvi);
}
template <typename T, typename M>
bool pereche<T,M>::operator==( const pereche<T,M> &f1) const
{
    return (!(*this<f1) && !(*this>f1));
}
template <typename T, typename M>
bool pereche<T,M>::operator!=( const pereche<T,M> &f1) const
{
    return !(*this==f1);
}

template <typename T, typename M>
pereche<T,M>::pereche()
{
    T a;
    M b;
    this->cuvi=a;
    this->def=b;
}
template <typename T, typename M>
pereche<T,M>::pereche(T a, M b)
{
    this->cuvi=a;
    this->def=b;

}
template <typename T, typename M>
T pereche<T,M>::get_cuvant()
{
    return (this->cuvi);
}
