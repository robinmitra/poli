#include <iostream>
#include "trie.h"

namespace polidb {
void Trie::put(std::string key, std::string value) {
  root = put(root, std::move(key), std::move(value), 0);
}

Node Trie::put(Node node, std::string key, std::string value, int index) {
  const char currChar = key[index];
  // Match - set the value.
  if (index==key.length()) node.setValue(std::move(value));
  else {
    std::unordered_map<char, Node> &nextMap = node.getNext();
    auto search = nextMap.find(currChar);
    Node nextNode = search!=nextMap.end() ? nextMap[currChar] : Node();
    nextMap[currChar] = put(nextNode, key, value, index + 1);
  }
  return node;
}

std::string Trie::get(const std::string &key) {
  Node node = get(root, key, 0);
  if (node.getValue().length()) return node.getValue();
  return "Not Found";
}

Node Trie::get(Node node, std::string key, int index) {
  if (index==key.length()) {
    return node;
  } else {
    const char currChar = key[index];
    std::unordered_map<char, Node> nextMap = node.getNext();
    auto search = nextMap.find(currChar);
    if (search==nextMap.end()) return Node();
    return get(nextMap[currChar], key, index + 1);
  }
}

TrieIterator Trie::begin() {
  return TrieIterator(root);
}

TrieIterator Trie::end() {
  return TrieIterator();
}
}