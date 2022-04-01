#include "Funkcje.hh"

using namespace std;

/*
* Konstruktor klasy pakiet, przyjmuje 0 dla poszczególnych elementów klasy pakiet
*/

pakiet::pakiet(){
    next=0;
    prev=0;
    ID=0;
    front=0;
}

/*
* Konstruktor klasy listy, przyjmuje 0 dla poszczególnych elementów klasy lista
*/

lista::lista(){
    head=0;
    tail=0;
}

/*
* Funkcja nadaje nr ID tablicy elementów klasy pakiet
*/

void numer_pakiet(pakiet tab[] , int ile){
   for(int i=0;i<ile;i++)
  {
      tab[i].ID=i+1;
  }
}

/*
* Funkcja tasuje tablice pakietów ID 
*/

void tasowanie(pakiet tab[], int ile)
{
    srand(time(NULL));
    pakiet tab_old[ile];
    for(int i=0; i<ile;i++)
    {
        tab_old[i].ID=tab[i].ID;
    }
    int los=0;
    bool tab_bool[ile];
    for(int i=0; i<ile; i++)
    tab_bool[i] = false;
    for(int i=0; i<ile; i++)
    {
        do
        {
            los = rand() %ile;
        } while (tab_bool[los]);
        tab_bool[los]=true;
        tab[i].ID=tab_old[los].ID;
        cout<<tab[i].wys()<<" ";
    }
}

/*
* Funkca odnosi się do innych funkcji i na podstawie tego rozlokowuje w 
* posortowany sposób pakiety do listy dwukierunkowej  
*/

void lista::search_and_add(pakiet *tab,int size)
{ 
    push_front(&tab[0]);

    if(tab[0].ID>tab[1].ID)
        push_front(&tab[1]);
    else 
        add_after(&tab[1],&tab[0]);
    for(int i=2;i<size;i++)
    {
        pakiet *temp;
        temp=locate(&tab[i]);
        if(temp->front==1)
        {  
        push_front(&tab[i]);
        temp->front=0;
        }
        else{
        add_after(&tab[i],temp);
        }
    }
    show();
}

/*
* Funkcja ustawia w liście pakiet pak1 za pakiet pak2
*/

void lista::add_after(pakiet *pak1, pakiet *pak2)      //ustawia pakiet pak1 za pakietem pak2
{
    pak1->next=pak2->next;
    pak2->next=pak1;
    pak1->prev=pak2;
    if(pak1->next) pak1->next->prev=pak1;
    else tail=pak1;
}

/*
* Funkcja ustawia pakiet na początku listy 
*/

void lista::push_front(pakiet *pak)
{
    pak->next=head;
    pak->prev=NULL;
    if(head) head->prev=pak;
    head=pak;
    if(!tail) tail=head;
}

/*
* Funkcja wyświetla ID elementów listy
*/

void lista::show()
{
    pakiet *temp=head;

    while(temp){
        cout<<temp->ID<<" ";
        temp=temp->next;
    }

}

/*
* Funkcja przyjmuje wskaźnik klasy pakiet w celu zwrócenia adresu klasy pakiet po którym 
* ma zostać umieszczona na liście
*/
pakiet* lista::locate(pakiet *pak)
{
    pakiet *temp=head;
    if(temp->ID>pak->ID)
    {
        temp->front=1;
    return temp;
    }
    else{
    while (temp->ID<pak->ID)
    {
        if(temp==tail) return temp;
        temp=temp->next;
    }
    return temp->prev;
    } 
}