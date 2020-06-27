#include "RBT.h"
using namespace std;


int main()
{


    cuvant a;
    a.set_cuvant("gradina");
    cuvant a1;
    a1.set_cuvant("eficace");
    cuvant b;
    b.set_cuvant("fecioara");
    cuvant c;
    c.set_cuvant("lunetist");
    cuvant d;
    d.set_cuvant("dentist");
    cuvant e;
    e.set_cuvant("cornee");
    cuvant f;
    f.set_cuvant("balena");
    cuvant g;
    g.set_cuvant("ananas");
      vector<string> l,m;
    l.push_back("ana");
    l.push_back("are");
    l.push_back("mere");
    m.push_back("ionel");
    m.push_back("are");
    m.push_back("pere");
    vector<definitie> n;
    n.push_back(l);
    n.push_back(m);
    defs h(n);
    pereche<cuvant,defs> i1(a1,h);
    pereche<cuvant,defs> i(a,h);
    pereche<cuvant,defs> j(b,h);
    pereche<cuvant,defs> k(c,h);
    pereche<cuvant,defs> o(d,h);
    pereche<cuvant,defs> p(e,h);
    pereche<cuvant,defs> r(f,h);
    pereche<cuvant,defs> s(g,h);
    tree copac;
    copac.insertnod(i);
    copac.insertnod(i1);
    copac.insertnod(j);
    copac.insertnod(k);
    copac.insertnod(o);
    copac.insertnod(p);
    copac.insertnod(r);
   copac.insertnod(s);
    copac.printInorder();
    cout<<"dupa stergere"<<endl;



     copac.deletebyval(o);
    copac.printInorder();



}

