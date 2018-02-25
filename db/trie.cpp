#include <iostream>
#include "trie.h"

namespace polidb {
void Trie::put(const std::string &key, const std::string &value) {
  root = put(root, key, value, 0);
}

Node Trie::put(Node &node, const std::string &key, const std::string &value, const int &index) {
  const char currChar = key[index];
  // Match - set the value.
  if (index==key.length()) node.setValue(value);
  else {
    const std::unordered_map<char, Node> &nextMap = node.getNext();
    Node nextNode = node.hasNextNode(currChar) ? nextMap.at(currChar) : Node();
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
    if (node.hasNextNode(currChar)) return get(nextMap.at(currChar), key, index + 1);
    return Node();
  }
}

void Trie::remove(const std::string &key) {
  root = remove(root, key, 0);
}

Node Trie::remove(Node &node, const std::string &key, const int &index) {
  const char currChar = key[index];
  std::unordered_map<char, Node> &nextMap = node.getNext();
  if (node.hasNextNode(currChar)) { // Current character exists in next nodes collection.
    if (key.length()==index + 1) { // Last character in the key - i.e. match.
      const Node &nextNode = nextMap.at(currChar);
      if (nextNode.getNext().empty()) node.removeNextNode(currChar);
      else node.resetNextNodeValue(currChar);
    } else {
      Node nextNode = remove(nextMap.at(currChar), key, index + 1);
      if (nextNode.getNext().empty()) node.removeNextNode(currChar);
      else node.setNextNode(currChar, nextNode);
    }
  }
  return node;
}

TrieIterator Trie::begin() const {
  return TrieIterator(root);
}

TrieIterator Trie::end() const {
  return TrieIterator();
}
}