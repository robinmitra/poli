#include "trie_iterator.h"

namespace polidb {

TrieIterator::TrieIterator() {
  keys.emplace_back("");
}

TrieIterator::TrieIterator(Node node) {
  collect(std::move(node), "");
  keys.emplace_back("");
}

std::string &TrieIterator::operator*() {
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

void TrieIterator::collect(Node node, const std::string &prefix) {
  if (node.getValue().length()) keys.push_back(prefix);
  std::unordered_map<char, Node> nextMap = node.getNext();
  for (const auto &currNode : nextMap) {
    collect(currNode.second, prefix + currNode.first);
  }
}

bool TrieIterator::operator==(const TrieIterator &rhs) {
  return keys[iterator_position]==rhs.keys[rhs.iterator_position];
}

bool TrieIterator::operator!=(const TrieIterator &rhs) {
  return keys[iterator_position]!=rhs.keys[rhs.iterator_position];
}

}
