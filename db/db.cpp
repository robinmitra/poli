#include <iostream>
#include "../includes/db.h"

namespace polidb {
bool Db::put(std::string key, std::string value) {
  if (!key.length()) return false;
  trie.put(std::move(key), std::move(value));
  return true;
}

std::string Db::get(std::string key) {
  return trie.get(key);
}

Trie Db::getKeysIterator() {
  return trie;
}

}