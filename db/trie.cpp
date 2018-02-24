#include <iostream>
#include "trie.h"

namespace polidb {
void Trie::put(const std::string &key, const std::string &value) {
  root = put(root, key, value, 0);
}

Node Trie::put(Node node, const std::string &key, const std::string &value, const int &index) {
  const char currChar = key[index];
  // Match - set the value.
  if (index==key.length()) node.setValue(value);
  else {
    const std::unordered_map<char, Node> &nextMap = node.getNext();
    auto search = nextMap.find(currChar);
    Node nextNode = search!=nextMap.end() ? nextMap.at(currChar) : Node();
    node.setNextNode(currChar, put(nextNode, key, value, index + 1));
  }
  return node;
}

std::string Trie::get(const std::string &key) const {
  Node node = get(root, key, 0);
  if (node.getValue().length()) return node.getValue();
  return "Not Found";
}

Node Trie::get(const Node &node, const std::string &key, const int &index) const {
  if (index==key.length()) {
    return node;
  } else {
    const char currChar = key[index];
    const std::unordered_map<char, Node> &nextMap = node.getNext();
    auto search = nextMap.find(currChar);
    if (search==nextMap.end()) return Node();
    return get(nextMap.at(currChar), key, index + 1);
  }
}

TrieIterator Trie::begin() const {
  return TrieIterator(root);
}

TrieIterator Trie::end() const {
  return TrieIterator();
}
}