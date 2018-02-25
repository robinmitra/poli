#include <utility>
#include "node.h"

namespace polidb {
void Node::setValue(const std::string &val) {
  value = val;
}

void Node::resetValue() {
  value.erase().shrink_to_fit();
}

const std::unordered_map<char, Node> &Node::getNext() const {
  return next;
}

std::unordered_map<char, Node> &Node::getNext() {
  return next;
}

std::string Node::getValue() const {
  return value;
}

void Node::setNextNode(const char &nodeKey, const Node &node) {
  next[nodeKey] = node;
}

void Node::removeNextNode(const char &nodeKey) {
  next.erase(nodeKey);
}

void Node::resetNextNodeValue(const char &nodeKey) {
  next[nodeKey].resetValue();
}

bool Node::hasNextNode(const char &key) const {
  return next.find(key)!=next.end();
}
}