#include "trie_iterator.h"

namespace polidb {
TrieIterator::TrieIterator() {
  keys.emplace_back("");
}

TrieIterator::TrieIterator(const Node &node) {
  collect(node, "");
  keys.emplace_back("");
}

std::string TrieIterator::operator*() const {
  return keys[iterator_position];
}

TrieIterator TrieIterator::operator++() {
  ++iterator_position;
  return *this;
}

TrieIterator TrieIterator::operator++(int) {
  TrieIterator currentState = *this;
  ++iterator_position;
  return currentState;
}

bool TrieIterator::operator==(const TrieIterator &rhs) const {
  return keys[iterator_position]==rhs.keys[rhs.iterator_position];
}

bool TrieIterator::operator!=(const TrieIterator &rhs) const {
  return keys[iterator_position]!=rhs.keys[rhs.iterator_position];
}

void TrieIterator::collect(const Node &node, const std::string &prefix) {
  if (node.getValue().length()) keys.push_back(prefix);
  std::unordered_map<char, Node> nextMap = node.getNext();
  for (auto &currNode : nextMap) {
    collect(currNode.second, prefix + currNode.first);
  }
}
}
