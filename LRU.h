#include <iostream>
#include <iterator>
#include <unordered_map>
#include "node.h"

using namespace std;

//template <typename T>

unordered_map<char, node*> mapa;
int contador;

class LRUCache{
private:
  node *head, *tail;
  int size;
public:
  LRUCache(int s){
    size=s;
    head=NULL;
    tail=NULL;
  }

  void test(char c, int v){
    node *curr= new node;
    curr->data=v;
    curr->key=c;
    mapa.insert(make_pair(c, curr));
    cout << mapa.find(c)->second->data;
  }

  void update(node *curr){
    if (curr==tail){
      curr->next=head;
      head->prev=tail;
      tail=tail->prev;
      curr->prev=NULL;
      tail->next=NULL;
      head=curr;
    }
    else if (curr!=head){
      //si esta en el medio
      node *temp=curr->prev;
      node *temp2=curr->next;
      temp->next=temp2;
      temp2->prev=temp;
      curr->prev=NULL;
      curr->next=head;
      head->prev=curr;
      head=curr;
    }
  }

  void inserKeyValue(char c, int v){
    if (mapa.find(c)==mapa.end()){//no esta
      node *temp=new node;
      if (contador<size){
        contador++;
        temp->data=v;
        temp->key=c;
        temp->next=NULL;
        temp->prev=NULL;
        if (head==NULL){
          head=temp;
          tail=temp;
        }
        else{
          temp->next=head;
          head->prev=temp;
          head=temp;
        }
      }
      else{
        mapa.erase(tail->key);
        temp->data=v;
        temp->key=c;
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        head=temp;
        node *temp1=tail->prev;
        temp1->next=NULL;
        tail->prev=NULL;
        delete tail;
        tail=temp1;
      }
      mapa.insert(make_pair(c, temp));
    }
    else{
      node*curr=mapa.find(c)->second;
      curr->data=v;
      update(curr);
    }
  }

  void getMostRecentKey(){
    cout << head->key << endl;
  }

  void getValueFromKey(char c){
    if (mapa.find(c)==mapa.end()){
      cout << "-" << endl;
    }
    else{
      node *curr=mapa.find(c)->second;
      cout << curr->data << endl;
      update(curr);
    }
  }

  void deletekey(char c){
    if (mapa.find(c)==mapa.end()){
      cout << "-" << endl;
    }
    else{
      node *tmp=mapa.find(c)->second;
      mapa.erase(c);
      if (tmp==head){
        tmp = head->next;
        delete head;
        head->next = NULL;
        tmp->prev = NULL;
        head = tmp;
      }
      else if (tmp==tail){
        tmp=tail->prev;
        tail->prev=NULL;
        delete tail;
        tmp->next=NULL;
        tail=tmp;
      }
      else{//si esta en el medio
        node *curr=tmp->prev;
        node *curr2=tmp->next;
        tmp->next=NULL;
        tmp->prev=NULL;
        curr->next=curr2;
        curr2->prev=curr;
        delete tmp;
      }
      contador--;
    }
  }
};
