#include <iostream>
using namespace std;

class node{
  public:
    int noMhs;
    node *next;
};

class linkedlist{
  node *start;

public:
  linkedlist(){
    start = NULL;
  }
  void addnote(){
    int nim;
    cout << "\nMasukan Nomor Mahasiswa : ";
    cin >> nim;

    node *nodebaru = new node;
    nodebaru -> noMhs = nim;

    if (start == NULL || nim <= start->noMhs){
      if ((start != NULL) && (nim == start->noMhs)){
        cout << "\nDuplikasi noMhs tidak diizinkan\n";
        return;
      }
      nodebaru->next = start;
      start = nodebaru;
      return;
    }
    node *previous = start;
    node *current = start;

    while ((current != NULL) && (nim >= current->noMhs )){
      if (nim == current->noMhs){
        cout << "\nDuplikasi no Mhs tidak diizinkan\n";
        return;
      }
      previous = current;
      current = current->next;
    }
    nodebaru->next = current;
    previous->next = nodebaru;
  }
  bool listempty(){
    return (start==NULL);
  }
  bool search(int nim,node **previous, node **current){
    *previous = start;
    *current = start;

    while ((*current != NULL) && (nim != (*current)->noMhs)){
      *previous = *current;
      *current = (*current)->next;
    }
    return (*current != NULL);
  }

  bool delnote(int nim){
    node *current, *previous;
    if (!search(nim, &previous, &current))
    return false;

    if (current == start)
        start = start->next;
    else
      previous->next = current->next;

    delete current;
    return true;
  }
   void traverse(){
    if (listempty()){
      cout << "\nList Kosong\n";
    }
    else{
      cout << "\nData didalam list adalah: \n";
      node *currentnode = start;
      while (currentnode != NULL){
        cout << currentnode->noMhs << endl;
        currentnode = currentnode->next;
      }
      cout << endl;
    }
  }
};

int main()
{
    linkedlist mhs;
    int nim;
    char ch;
    do
    {
        cout << endl
             << "Menu";
        cout << endl
             << "1. Menambah data kedalam list" << endl;
        cout << "2. Menghapus data dari dalam list" << endl;
        cout << "3. Menampilkan semua data didalam list" << endl;
        cout << "4. Menampilkan semua data didalam list secara terbalik" << endl;
        cout << "5. Mencari data dalam  list" << endl;
        cout << "6. Keluar" << endl;
        cout << endl
             << "Masukkan pilihan (1-5): ";
        cin >> ch;
    
      
}