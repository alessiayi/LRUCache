#include <iostream>
#include <iterator>
#include <unordered_map>

using namespace std;

template <class T>

struct node{
  int data;
  char key;
  node *next;
  node *prev;
};

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
    if (curr==head){
      cout << " ";
    }
    else if (curr==tail){
      curr->next=head;
      head->prev=tail;
      tail=tail->prev;
      curr->prev=NULL;
      tail->next=NULL;
      head=curr;
    }
    else{
      //si esta en el medio
      node *temp=curr->prev;
      temp->next=curr->next;
      temp=temp->next;
      temp->prev=curr->prev;
      curr->next=head;
      curr->prev=NULL;
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
    cout << head->key << "\n";
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
};

int main() {
  LRUCache cache=LRUCache(3);
  cache.inserKeyValue('b', 2);
  cache.inserKeyValue('a', 1);
  cache.inserKeyValue('c', 3);
  cache.getMostRecentKey(); // "c" was the most recently inserted key
  cache.getValueFromKey('a');
  cache.getMostRecentKey(); // "a" was the most recently retrieved key
  cache.inserKeyValue('d', 4); // the cache had 3 entries; the least recently
  cache.getValueFromKey('b'); // "b" was evicted in the previous operation
  cache.inserKeyValue('a', 8); // "a" already exists in the cache so its valu
  cache.getValueFromKey('a');

  return 0;
}
