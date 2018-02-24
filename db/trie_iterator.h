#ifndef POLIDB_TRIE_ITERATOR_H
#define POLIDB_TRIE_ITERATOR_H

#include <vector>
#include <string>
#include "node.h"

namespace polidb {
class TrieIterator {
 public:
  TrieIterator();
  explicit TrieIterator(const Node &node);

  // Operator overloads.
  std::string operator*() const;
  TrieIterator operator++();
  TrieIterator operator++(int);
  bool operator==(const TrieIterator &rhs) const;
  bool operator!=(const TrieIterator &rhs) const;

 private:
  int iterator_position = 0;
  std::vector<std::string> keys;
  void collect(const Node &node, const std::string &prefix = "");
};
}

#endif //POLIDB_TRIE_ITERATOR_H
