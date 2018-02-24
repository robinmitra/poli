#include <utility>
#include "node.h"

namespace polidb {
void Node::setValue(const std::string &val) {
  value = val;
}

const std::unordered_map<char, Node> &Node::getNext() const {
  return next;
}

std::string Node::getValue() const {
  return value;
}

void Node::setNextNode(const char &nodeKey, const Node &node) {
  next[nodeKey] = node;
}
}