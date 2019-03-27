//Michal Zadrozny PROI projekt 1
#include <iostream>
#include <cstdlib>
#include "wielomian.h"
using namespace std;

int main()
{
    cout<<"Michal Zadrozny PROI projekt 1"<<endl<<endl;

    Wielomian w1,w2;
    cout<<"Domyslnie oba wielomiany w1 i w2 sa zerowe."<<endl<<endl;
    cout<<"[1] Podaj wspolczynniki wielomianu w1 (>>)"<<endl;
    cout<<"[2] Podaj wspolczynniki wielomianu w2 (>>)"<<endl;
    cout<<"[3] Wyswietl podane wielomiany (<<) "<<endl;
    cout<<"[4] Dodaj wielomiany (+) "<<endl;
    cout<<"[5] Odejmij wielomiany (-) "<<endl;
    cout<<"[6] Porownaj wielomiany (zbadaj identycznosc) (==) (!=) "<<endl;
    cout<<"[7] Zrozniczkuj wielomiany"<<endl;
    cout<<"[8] Przypisz pierwszemu wielomianowi sume podanych wielomianow (+=) "<<endl;
    cout<<"[9] Przypisz pierwszemu wielomianowi roznice podanych wielomianow (-=) "<<endl;
    cout<<"[0] Zamknij "<<endl;

    int c;
    while(1)
    {
    cout<<endl<<endl<<"###########################"<<endl<<endl;

    cout<<"Wybierz dzialanie: ";
    while(!(cin>>c)) //kontrola bledow
        {
            cout<<"Nieokreslona wartosc, sprobuj jeszcze raz: ";cout<<endl<<endl<<"###########################"<<endl<<endl; cout<<"Wybierz dzialanie: "; //gdy nie poda sie liczby
            cin.clear(); //usuwanie blednych danych ze strumienia
            cin.ignore(1000, '\n');
        }
    if(c<0 || c>9) {cout<<"Nieokreslona wartosc, sprobuj jeszcze raz:";cin.clear();cin.ignore(1000, '\n');continue;} //podanie zbyt duzej liczby lub ujemnej

    cin.clear();
    cin.ignore(1000, '\n'); //usuniecie nadmiarowych danych
    cout<<endl;

    switch(c)
    {
        case 1: cin>>w1; break;
        case 2: cin>>w2; break;
        case 3: cout<<"w1: "<<w1<<"w2: "<<w2; break;
        case 4: cout<<"w1 + w2 = "<<w1+w2; break;
        case 5: cout<<"w1 - w2 = "<<w1-w2; break;
        case 6: if(w1==w2) cout<<"(w1==w2) : Wielomiany sa identyczne."<<endl;
                else cout<<"!(w1==w2) : Wielomiany nie sa identyczne. "<<endl;
                if(w1!=w2) cout<<"(w1!=w2) : Wielomiany sa rozne."<<endl;
                else cout<<"!(w1!=w2) : Wielomiany nie sa rozne."<<endl;
                break;
        case 7: cout<<"Pochodna w1: "<<w1.dx();
                cout<<"Pochodna w2: "<<w2.dx(); break;
        case 8: cout<<"w1+=w2"<<endl;
                w1+=w2;
                cout<<"Nowa wartosc w1: "<<w1; break;
        case 9: cout<<"w1-=w2"<<endl;
                w1-=w2;
                cout<<"Nowa wartosc w1: "<<w1; break;
        case 0: cout<<"Do widzenia"<<endl; exit(0); break;
        default: cout<<"Nieokreslona wartosc, sprobuj jeszcze raz"<<endl; break;

    }
    }

    return 0;
}
