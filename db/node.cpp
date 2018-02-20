#include <utility>
#include "node.h"

namespace polidb {

void Node::setValue(std::string val) {
  value = std::move(val);
}

std::unordered_map<char, Node> &Node::getNext() {
  return next;
}

std::string Node::getValue() {
  return value;
}
}