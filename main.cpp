#include "LRU.h"

using namespace std;

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
  cache.deletekey('d');
  cache.getValueFromKey('a');

  return 0;
}
