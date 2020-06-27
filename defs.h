#include "definitie.h"
using namespace std;

class defs
{
    vector<definitie> a;
public:
    defs();
    defs(vector<definitie> b);
    void set_defs(vector<definitie> b);
    friend ostream& operator<<(ostream& dev, const defs &b );
    friend istream& operator>>(istream& dev, defs &b);
};

defs::defs()
{
   vector<string> k;
   k.push_back("");
    this->a.push_back(k);
}
defs::defs(vector<definitie> b)
{
    vector<string> k;
   k.push_back("");
    this->a.push_back(k);
    this->set_defs(b);

}
void defs::set_defs(vector<definitie> b)
{
    for(int i=0;i<b.size();i++)
        this->a.push_back(b[i]);
}

ostream& operator<<(ostream &dev, const defs &b)
{
    for(int i=1;i<b.a.size();i++)
    {
        dev<<"["<<i<<"]"<<b.a[i]<<" ";
    }
    return dev;
}

istream& operator>>(istream &dev, defs &b)
{
    definitie k;
    dev>>k;
    vector<definitie> l(1,k);
    char c='n';
    cout<<"doriti sa adaugati alta definitie? d/n ";
    dev>>c;
    while(c=='d')
    {
          definitie m;
        cout<<"introduceti alta definitie :";
        dev>>m;
        l.push_back(m);
        //cout<<k;
        cout<<"\n doriti sa adaugati alta definitie? d/n ";
        dev>>c;
    }
     b.set_defs(l);
     return dev;
}
