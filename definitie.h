
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class definitie
{
    vector<string> defi;

public:
      definitie();
      definitie(vector<string> ceva);
      vector<string> get_def();
      void set_definitie(vector<string> ceva);
      friend ostream& operator<<(ostream& dev, const definitie &a);
      friend istream& operator>>(istream& dev, definitie &a);
};

definitie::definitie()
{
    this->defi.push_back(" ");
}

void definitie::set_definitie(vector<string> ceva)
{
    for(int  i=0;i<ceva.size();i++)
    {
        this->defi.push_back(ceva[i]);
    }
}
definitie::definitie(vector<string> ceva)
{
    this->set_definitie(ceva);
}

vector<string> definitie::get_def()
{
    return this->defi;
}
ostream& operator<<(ostream& dev, const definitie &a)
{
    for(int i=0;i<a.defi.size();i++)
        dev<<a.defi[i]<<" ";
    return dev;
}

istream& operator>>(istream& dev, definitie &a)
{
    string h;
    dev>>h;
    while(1){
    a.defi.push_back(h);
    if(h==".") return dev;

    dev>>h;
    if(h==".") return dev;}

     return dev;

}
