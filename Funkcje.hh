#ifndef FUNKCJE_HH
#define FUNKCJE_HH

#include <iostream>
#include <cstdlib>
#include <time.h>


/*
* Klasa realizuje przechowywanie pakietów. ID przechowuje odpowiedni numer pakietu
* Funkcja wys() - zwaraca wartość ID
* pakiet *next; - wskaznik na nastepny element listy
* pakiet *prev; - wskaznik na poprzedni element listy
* pakiet() - konstruktor 
*/

class pakiet{
    
    public:
    int ID;
    int front;
    int wys() {return ID;};
    pakiet *next;   //nastepny element listy
    pakiet *prev;   //poprzedni element
    
    pakiet();
};

/*
* Klasa realizuje przechowywanie listy. ID przechowuje odpowiedni numer pakietu
* Funkcja wys() - zwaraca wartość ID
* pakiet *head; - wskaźnik na początek listy
* pakiet *tail - wskaźnik na koniec listy
* void search_and_add(pakiet *tab,int size);
* void push_front(pakiet *pak);
* void add_after(pakiet *pak1, pakiet *pak2);
* void show(); - 
* lista() - konstruktor 
*/

class lista{
    public:
    pakiet *head;   //wskaźnik na początek listy
    pakiet *tail;   //wskaźnik na koniec listy
    void search_and_add(pakiet *tab,int size);
    void push_front(pakiet *pak);
    void add_after(pakiet *pak1, pakiet *pak2);
    void show();
    pakiet* locate(pakiet *pak);
    lista();
};

void numer_pakiet(pakiet tab[], int ile);
void tasowanie(pakiet tab[], int ile);

#endif