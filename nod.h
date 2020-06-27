#include "pereche.h"
#include <queue>
using namespace std;


 class nod
 {

     pereche<cuvant,defs> a;
     nod* stanga;
     nod* dreapta;
     nod* parinte;
     bool color;

public:
    nod();
    nod(pereche<cuvant,defs> b);
    nod(pereche<cuvant,defs> b, nod* primul, nod *doi, nod *trei ,bool k);
    ~nod();
   void aloca_dreapta();
   void aloca_stanga();
   void aloca_parinte();
    void set_stanga(nod *k);
    void set_dreapta(nod *k);
    void set_parinte(nod *k);
    nod* get_stanga();
    nod* get_dreapta();
    nod* get_parinte();

    pereche<cuvant,defs> get_cuvix();
    void set_cuv(pereche<cuvant,defs> b);

    bool get_color();
    void set_color(bool b);

    friend ostream& operator<<(ostream& dev, const nod& a);
    friend istream& operator>>(istream& dev, nod& b);


    nod* uncle();
    nod* sibling();
    bool isOnLeft();
    bool hasRedChild();
    void moveDown(nod* n);
 };
nod::~nod()
{
    delete stanga;
    delete dreapta;
    delete parinte;

}
 bool nod::hasRedChild()
 {
     return (stanga!=NULL && stanga->color==0)||(dreapta!=NULL && dreapta->color==0);
 }

 void nod::moveDown(nod* n)
{
    if(parinte!=NULL)
    {
        if(isOnLeft())
        {
            parinte->stanga=n;
        }
        else
            {
              parinte->dreapta=n;
            }
    }
        n->parinte=this->parinte;
        this->parinte=n;
    }



nod* nod::sibling()
{
    if(parinte==NULL)
        return NULL;
    if(isOnLeft())
        return parinte->dreapta;
    return parinte->stanga;
}
 bool nod::isOnLeft()
 {
     return this==parinte->stanga;
 }
 nod* nod::uncle()
 {
     if(this->parinte==NULL || this->parinte->parinte==NULL)
        return NULL;
     if(this->parinte->isOnLeft())
        return this->parinte->parinte->dreapta;
     else return this->parinte->parinte->stanga;
 }


 void nod::set_cuv(pereche<cuvant,defs> b)
 {
     this->a=b;
 }
 bool nod::get_color()
 {
     return this->color;
 }
 void nod::set_color(bool b)
 {
     this->color=b;
 }
nod::nod(pereche<cuvant,defs> b)
{
    this->a=b;
    this->dreapta=NULL;
     this->stanga=NULL;
     this->parinte=NULL;
     this->color=0;

}


 pereche<cuvant,defs> nod::get_cuvix()
 {
     return this->a;
 }
nod* nod::get_dreapta()
{
    return this->dreapta;
}
nod* nod::get_stanga()
{
    return this->stanga;
}
nod* nod::get_parinte()
{
    return this->parinte;
}
 void nod::set_parinte(nod *k)
 {
     this->parinte=k;

 }
 void nod::set_stanga(nod *k)
 {

     //if(this->stanga==NULL) this->aloca_stanga();
     this->stanga=k;

 }
  void nod::set_dreapta(nod *k)
 {

     //if(this->dreapta==NULL) this->aloca_dreapta();
     this->dreapta=k;

 }


 nod::nod()
 {
     pereche<cuvant,defs> b;
     this->a=b;
     this->dreapta=NULL;
     this->stanga=NULL;
     this->parinte=NULL;
     this->color=0;
 }

 void nod::aloca_dreapta()
 {
     this->dreapta=new nod;
 }
 void nod::aloca_stanga()
 {
     this->stanga=new nod;
 }
 nod::nod(pereche<cuvant,defs> smt, nod* primul, nod* doi, nod* trei, bool k)
 {
     this->a=smt;
     //this->aloca_dreapta();
    // this->aloca_stanga();
     this->stanga=primul;
     this->dreapta=doi;
     this->parinte=trei;
     this->color=k;
 }
ostream& operator<<(ostream& dev, const nod& b)
{
    dev<<b.a;
    return dev;
}
istream& operator>>(istream& dev, nod& b)
{
    dev>>b.a;
    return dev;
}
