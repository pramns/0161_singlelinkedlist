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
};