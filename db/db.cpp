#include <iostream>
#include "../includes/db.h"

namespace polidb {
bool Db::put(const std::string &key, const std::string &value) {
  if (!key.length()) return false;
  trie.put(key, value);
  return true;
}

std::string Db::get(const std::string &key) const {
  return trie.get(key);
}

bool Db::remove(const std::string &key) {
  if (!key.length()) return false;
  trie.remove(key);
  return true;
}

Trie Db::getKeysIterator() const {
  return trie;
}
}