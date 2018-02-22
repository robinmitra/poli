#include <string>
#include "../db/trie.h"

namespace polidb {

class Db {
 private:
  Trie trie;

 public:
  bool put(std::string key, std::string value);
  std::string get(std::string key);
  Trie getKeysIterator();
};
}