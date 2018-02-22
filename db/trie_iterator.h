#ifndef POLIDB_TRIE_ITERATOR_H
#define POLIDB_TRIE_ITERATOR_H

#include <vector>
#include <string>
#include "node.h"

namespace polidb {
class TrieIterator {
 public:
  TrieIterator();
  explicit TrieIterator(Node node);

  std::string &operator*();

  TrieIterator operator++();
  TrieIterator operator++(int);

  bool operator==(const TrieIterator &rhs);
  bool operator!=(const TrieIterator &rhs);

 private:
  int iterator_position = 0;
  std::vector<std::string> keys;
  void collect(Node node, const std::string &prefix = "");
};
}

#endif //POLIDB_TRIE_ITERATOR_H
