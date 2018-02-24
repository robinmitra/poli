#ifndef POLIDB_DB_H
#define POLIDB_DB_H

#include <string>
#include "../db/trie.h"

namespace polidb {
class Db {
 public:
  bool put(const std::string &key, const std::string &value);
  std::string get(const std::string &key) const;
  Trie getKeysIterator() const;
 private:
  Trie trie;
};
}

#endif //POLIDB_DB_H
