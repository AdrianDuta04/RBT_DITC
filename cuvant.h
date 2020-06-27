#include <iostream>
#include <string>
using namespace std;

class cuvant
{
    string a;
    int nr_def;
public:
       cuvant(string a="NULL", int nr_def=0);

       void set_nr(int x);
       int get_nr();

       void set_cuvant(string cuv);
       string get_cuvant();

       friend ostream& operator<<(ostream& dev, const cuvant &a);
       friend istream& operator>>(istream& dev, cuvant &a);

        bool operator<(const cuvant &f1) const;
         bool operator>( const cuvant &f1) const;
         bool operator==(const cuvant &f1) const;

         bool operator!=(const cuvant &f1) const;
};

bool cuvant::operator<( const cuvant &f1) const
{
    return ((this->a)<(f1.a));
}
bool cuvant::operator>( const cuvant &f1) const
{
    return ((this->a)>(f1.a));
}
bool cuvant::operator==(const cuvant &f1) const
{
    return (!(*this<f1) && !(*this>f1));
}
bool cuvant::operator!=(const cuvant &f1) const
{
    return !(*this==f1);
}






cuvant::cuvant(string cuv, int n)
{
    this->a=cuv;
    this->nr_def=n;
}


void cuvant::set_cuvant(string cuv)
{
    this->a=cuv;
}
void cuvant::set_nr(int x)
{
    this->nr_def=x;
}
string cuvant::get_cuvant()
{
    return this->a;
}

int cuvant::get_nr()
{
    return this->nr_def;
}


ostream& operator<<(ostream& dev, const cuvant &x)
{
    dev<<"Cuvant: "<<x.a;
    return dev;
}
istream& operator>>(istream& dev, cuvant &x)
{
    dev>>x.a;
    return dev;
}
