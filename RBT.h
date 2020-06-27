
#include "nod.h"
using namespace std;

class tree
{
    nod *root;
public:
    void rotatieStanga(nod* x);
    void rotatieDreapta(nod* x);

    void swapvalues(nod* u, nod* v);
    void swapcolors(nod*x1, nod*x2);

    void inorder(nod* x);
    void printInorder();

    void deletebyval(pereche<cuvant,defs> n);
    void deletenod(nod* v);
    void insertnod(pereche<cuvant,defs> n);
    void fix_negru_negru(nod* x);
    void fix_rosu_rosu(nod* x);
    void fixDoubleBlack(nod *x);


    tree();

    nod* get_root();
    nod* succesor(nod* x);
    nod* BSTreplace(nod* x);
    nod* search_val(pereche<cuvant,defs> n);
};
tree::tree()
{
    root=NULL;
}
nod* tree::get_root()
{
    return root;
}
nod* tree::succesor(nod* x)
{  //returneaza nodul fara fiu la stanga
    nod* temp=x;
    while(temp->get_stanga()!=NULL)
        temp=temp->get_stanga();
    return temp;
}
nod* tree::BSTreplace(nod*x)
{
    if(x->get_stanga()!=NULL && x->get_dreapta()!=NULL)
        return succesor(x->get_dreapta());
    if(x->get_stanga()==NULL && x->get_dreapta()==NULL)
        return NULL;
    if(x->get_stanga()!=NULL)
        return x->get_stanga();
    else return x->get_dreapta();
}
nod* tree::search_val(pereche<cuvant,defs> n)
{
    nod* temp=root;
    while(temp!=NULL)
    {
        if(n<temp->get_cuvix())
        {
            if(temp->get_stanga()==NULL) break;
            else
                temp=temp->get_stanga();
        }
        else if(n==temp->get_cuvix())
        {
            break;
        }
             else
             {
                 if(temp->get_dreapta()==NULL)
                    break;
                 else temp=temp->get_dreapta();
             }

    }
    return temp;
}
void tree::rotatieStanga(nod* x)
{
    nod *np=x->get_dreapta();//noul nod este fiul de pe partea dreapta
    if(x==this->root)
        this->root=np;
    x->moveDown(np);
    x->set_dreapta(np->get_stanga());//leaga x cu fiul stang al noului parinte
    if(np->get_stanga()!=NULL)
       (np->get_stanga())->set_parinte(x);
    np->set_stanga(x);
}

void tree::rotatieDreapta(nod* x)
{
    nod *np=x->get_stanga();//noul nod este fiul de pe partea stanga
    if(x==this->root)
        this->root=np;
    x->moveDown(np);
    x->set_stanga(np->get_dreapta());//leaga x cu fiul stang al noului parinte
    if(np->get_dreapta()!=NULL)
       (np->get_dreapta())->set_parinte(x);
    np->set_dreapta(x);
}
void tree::swapcolors(nod* x1, nod* x2)
{
    bool temp;
    temp=x1->get_color();
    x1->set_color(x2->get_color());
    x2->set_color(temp);
}

void tree::swapvalues(nod* u, nod *v)
{
    pereche<cuvant,defs> temp;
    temp=u->get_cuvix();
    u->set_cuv(v->get_cuvix());
    v->set_cuv(temp);
}
void tree::inorder(nod* x)
{
    if(x==NULL) return;
    inorder(x->get_stanga());
    cout<<x->get_cuvix()<<endl;
    inorder(x->get_dreapta());
}

void tree::printInorder()
{
    if(this->root==NULL)
        cout<<"dictionar gol";
    else inorder(root);
    cout<<endl;
}


void tree::fix_rosu_rosu(nod* x)
{
    if(x==this->root)
    {
        x->set_color(1);
        return;
    }
    nod* parent=x->get_parinte();
    nod* grandparent=parent->get_parinte();
    nod* unchi=x->uncle();
    if(parent->get_color()!=1)
    {
        if(unchi!=NULL && unchi->get_color()==0)
        {
            parent->set_color(1);
            unchi->set_color(1);
            grandparent->set_color(0);
            fix_rosu_rosu(grandparent);
        }
        else{
            if(parent->isOnLeft()){
                if(x->isOnLeft()){
                    swapcolors(parent,grandparent);
                } else{
                       rotatieStanga(parent);
                       swapcolors(x,grandparent);
                }
                rotatieDreapta(grandparent);
            }else
            {
                if(x->isOnLeft())
                {
                    rotatieDreapta(parent);
                    swapcolors(x,grandparent);
                } else{
                swapcolors(parent,grandparent);
                }
                rotatieStanga(grandparent);
            }
        }
    }
}

void tree::insertnod(pereche<cuvant,defs> n)
{
    nod* newnod=new nod(n);
    if(root==NULL)
    {
        newnod->set_color(1);
        root=newnod;
    }
    else{
        nod *temp=search_val(n);
        if(temp->get_cuvix()==n)
           {
              return;
           }
        newnod->set_parinte(temp);
        if(n<temp->get_cuvix())
            temp->set_stanga(newnod);
        else temp->set_dreapta(newnod);
        fix_rosu_rosu(newnod);
    }
}

void tree::fixDoubleBlack(nod *x)
{
    if(x==root) return;
    nod* frate=x->sibling();
    nod* parent=x->get_parinte();

    if(frate==NULL)
    {
        fixDoubleBlack(parent);
    }
    else{
        if(frate->get_color()==0)
        {
            parent->set_color(0);
            frate->set_color(1);
            if(frate->isOnLeft())
            {
                rotatieDreapta(parent);
            }
            else rotatieStanga(parent);
            fixDoubleBlack(x);
        }
        else{
            if(frate->hasRedChild())
            {
                if(frate->get_stanga()==NULL && (frate->get_stanga())->get_color()==0)
                {
                    if(frate->isOnLeft())
                    {
                        (frate->get_stanga())->set_color(frate->get_color());
                        frate->set_color(parent->get_color());
                        rotatieDreapta(parent);
                    }
                    else
                        { //RIGHT LEFT
                        (frate->get_stanga())->set_color(parent->get_color());
                        rotatieDreapta(frate);
                        rotatieStanga(parent);

                        }
                }
                else{
                    if(frate->isOnLeft())
                    {
                        //stanga right
                        (frate->get_dreapta())->set_color(parent->get_color());
                        rotatieStanga(frate);
                        rotatieDreapta(parent);
                    }
                    else{
                        (frate->get_dreapta())->set_color(frate->get_color());
                        frate->set_color(parent->get_color());
                        rotatieStanga(parent);
                    }
                }
                parent->set_color(1);
            }
            else{
                frate->set_color(0);
            if(parent->get_color()==1)
                fixDoubleBlack(parent);
            else parent->set_color(1);

            }
        }
    }


}



void tree::deletenod(nod *v) {
    nod *u =BSTreplace(v);

    // True when u and v are both black
    bool uvBlack = ((u == NULL or u->get_color() == 1) &&(v->get_color() == 1));
    nod *parent = v->get_parinte();


    if (u == NULL) {

      // u is NULL therefore v is leaf
      if (v == root) {
        // v is root, making root null
        root = NULL;
      } else {
        if (uvBlack) {

          // u and v both black
          // v is leaf, fix double black at v
          fixDoubleBlack(v);

        } else {
          // u or v is red
          if (v->sibling() != NULL)
            // sibling is not null, make it red"
           (v->sibling())->set_color(0);
        }

        // delete v from the tree
        if (v->isOnLeft()) {

          parent->set_stanga(NULL);
        } else {
          parent->set_dreapta(NULL);
        }
      }

     v=NULL;

     // cout<<*v;
      return;
    }
    if (v->get_stanga()== NULL || v->get_dreapta() == NULL) {

      // v has 1 child
      if (v == root) {
        // v is root, assign the value of u to v, and delete u
        v->set_cuv(u->get_cuvix());
        v->set_stanga(NULL);
        v->set_dreapta(NULL);
        u=NULL;
        //cout<<*u;
      } else {
        // Detach v from tree and move u up
        if (v->isOnLeft()) {
          parent->set_stanga(u);
        } else {
          parent->set_dreapta(u);
        }
       v=NULL;
        //cout<<*v;
        u->set_parinte(parent);
        if (uvBlack) {
          fixDoubleBlack(u);
        } else {
          u->set_color(1);
        }
      }
      //cout<<"salut";
      return;
    }
     swapvalues(u, v);
    deletenod(u);
}
void tree::deletebyval(pereche<cuvant,defs> n)
{
    if(root==NULL)
        return;
    nod* v=search_val(n);

    if((v->get_cuvix())!=n)
    {
        cout<<"cuvant negasit";
        return;
    }
    deletenod(v);
}


