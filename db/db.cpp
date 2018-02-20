#include <iostream>
#include "../includes/db.h"

namespace polidb {
bool Db::put(std::string key, std::string value) {
  trie.put(std::move(key), std::move(value));
  return true;
}

std::string Db::get(std::string key) {
  return trie.get(key);
};
}