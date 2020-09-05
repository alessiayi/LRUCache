#include <iostream>
#include <iterator>
#include <map>

using namespace std;

struct node{
  int data;
  node *next;
};

map<int, int> mapa;

class LRUCache{
private:
  node *head, *tail;
public:
  //LRUCache(int);
  LRUCache(){
    head=NULL;
    tail=NULL;
  }
  void inserKeyValue(char c, int v){
    if (mapa.find(c) == m.end()){
      node *temp=new node;
      temp->data=c;
      temp->next=NULL;
      if (head==NULL){
        head=temp;
        tail=temp;
        temp=NULL;
      }
      else{
        temp->next=head;
        head=temp;
      }

      mapa.insert(pair<char, int>(c, v))
    }
  }

  void getMostRecentKey(){
    cout << head->data << "\n";
  }

  void getValueFromKey(char c){
    cout << mapa.find(c)->second << "\n";
  }
};

int main() {

  return 0;
}
