#include <iostream>
#include "wielomian.h"
using namespace std;

Wielomian::Wielomian()
{
    for(int i=0;i<5;i++) x[i]=0; //domyslnie zerowy wielomian
}


Wielomian::~Wielomian()
{
}

ostream &operator<<(ostream &out, const Wielomian &w)
{
    int p=1; //flaga zeby wielomian nie zaczal sie od +
    for(int i=4;i>=0;i--)
    {
        if(w.x[i]!=0) //wyswietlamy niezerowe
        {
            if(w.x[i]>0)
            {
                if(p==0) {out<<"+ "; if(w.x[i]!=1 || i==0) out<<w.x[i];} //pomijanie jedynki
                if(p==1) //pierwszy dodatni, nie chcemy plusa na poczatku
                    {
                        if(w.x[i]!=1 || i==0) out<<w.x[i];
                        p=0; // przy kolejnych wyswietlaj plus
                    }

                if(i>1) out<<"x^"<<i<<" "; //zeby nie wyswietlal x^1 x^0
                if(i==1) out<<"x ";
            }
            if(w.x[i]<0)
            {
                if(w.x[i]==-1) {if(i==0)out<<w.x[i]; else out<<"-";} else out<<w.x[i]; //pomijanie minus jedynki
                if(i>1)out<<"x^"<<i<<" "; //zeby nie wyswietlal x^1 x^0
                if(i==1) out<<"x ";
                p=0;
            }
        }

    }
    if(w.x[0]==0 && w.x[1]==0 && w.x[2]==0 && w.x[3]==0 && w.x[4]==0) out<<"0"; //pusty wielomian
    out<<endl;
    return out;
}

istream &operator>>(std::istream &in, Wielomian &w1)
{
    cout<<"Podaj wspolczynniki wielomianu: "<<endl;
    for(int i=4;i>=0;i--)
    {
        cout<<"x^"<<i<<" : "; //kolejne wspolczynniki
        while(!(in>>w1.x[i])) //kontrola bledow
        {
            cout<<"Blad, sprobuj jeszcze raz: ";
            in.clear(); //usuwanie blednych danych ze strumienia
            in.ignore(1000, '\n');
        }
        in.clear(); //usuwanie blednych danych ze strumienia
        in.ignore(1000, '\n');
    }
    return in;
}

Wielomian Wielomian::operator+(const Wielomian &w1) const
{
    Wielomian w2;
    for(int i=0;i<5;i++) w2.x[i]=w1.x[i]+x[i]; //dodawanie
    return w2;
}

void Wielomian::operator+=(const Wielomian &w1)
{
    for(int i=0;i<5;i++) x[i]=w1.x[i]+x[i]; //przypisz wielomianowi sume obu wielomianow
}

Wielomian Wielomian::operator-(const Wielomian &w1) const
{
    Wielomian w2;
    for(int i=0;i<5;i++) w2.x[i]=x[i]-w1.x[i]; //odejmowanie
    return w2;
}

void Wielomian::operator-=(const Wielomian &w1)
{
    for(int i=0;i<5;i++) x[i]=x[i]-w1.x[i]; //przypisz wielomianowi roznice obu wielomianow
}

bool Wielomian::operator==(const Wielomian &w1) const
{
    for(int i=0;i<5;i++)
    {
        if(w1.x[i]!=x[i]) return false; //wszystkie wspolczynniki musze byc rowne
    }
    return true;
}

bool Wielomian::operator!=(const Wielomian &w1) const
{
    for(int i=0;i<5;i++)
    {
        if(w1.x[i]!=x[i]) return true; //wystarczy niezgodnosc wspolczynnikow przy jednej potedze
    }
    return false;
}

Wielomian Wielomian::dx()
{
    Wielomian w;
    w.x[0]=x[1];
    w.x[1]=2*x[2];
    w.x[2]=3*x[3];
    w.x[3]=4*x[4];
    w.x[4]=0;
    return w;
}

