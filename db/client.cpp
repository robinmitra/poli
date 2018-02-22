#include <iostream>
#include "../includes/db.h"

using namespace polidb;

int main() {
  // Instantiate.
  Db db;

  // Put key-value pairs.
  db.put("name", "Robin");
  db.put("place", "London");
  db.put("language-1", "C++");
  db.put("language-2", "JS");
  db.put("never", "true");
  db.put("", "bad value");
  db.put("language-3", "PHP");

  // Iterate through keys and get value for each.
  Trie keysIterator = db.getKeysIterator();
  for (const auto &key : keysIterator) {
    std::cout << "Key: " << key << ", value: " << db.get(key) << std::endl;
  }

  return 0;
}