#include <iostream>
#include <cstdlib>
#include <time.h>
#include "Funkcje.hh"

using namespace std;

/*
*
* Program rozwiązuje problem zadany w zadaniu projektowym na ocenę bdb.
* Użytkownik podaje ilość pakietów jakie mają zostać posortowane, a następnie są one generowane  w tablicy z          * odpowiednimi ID. Następnym etapem jest posortowanie pakietów w odpowiedniej funkcji. Po posortowaniu tablicy, 
* zostaje ona przekazana do algorytmu, który podczas lokowania pakietów do listy dwukierunkowej sortuje je.
*
*/


int main(){
    int l_pakiet;
    cout<<"Podaj liczbę pakietow: ";
    cin>>l_pakiet;
    if(l_pakiet<1) 
    {
        cout<<"Nieprawidlowa liczba pakietow - error ";
        return 1;
    }
    pakiet t_pakiet[l_pakiet];

    numer_pakiet(t_pakiet, l_pakiet);

    cout<<endl<<"Pakiety po pomieszniu"<<endl;
    tasowanie(t_pakiet, l_pakiet);

    lista *baza=new lista;

    cout<<endl<<"Pakiety po posortowaniu "<<endl;
    baza->search_and_add(t_pakiet,l_pakiet);
    return 0;
}


