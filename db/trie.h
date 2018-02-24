#ifndef POLIDB_TRIE_H
#define POLIDB_TRIE_H

#include <string>
#include "node.h"
#include "trie_iterator.h"

namespace polidb {
class Trie {
 public:
  void put(const std::string &key, const std::string &value);
  std::string get(const std::string &key) const;
  TrieIterator begin() const;
  TrieIterator end() const;
 private:
  Node root;
  Node put(Node node, const std::string &key, const std::string &value, const int &index);
  Node get(const Node &node, const std::string &key, const int &index) const;
};
}

#endif //POLIDB_TRIE_H
