#ifndef POLIDB_NODE_H
#define POLIDB_NODE_H

#include <string>
#include <unordered_map>

namespace polidb {
class Node {
 public:
  void setValue(const std::string &value);
  std::string getValue() const;
  const std::unordered_map<char, Node> &getNext() const;
  void setNextNode(const char &nodeKey, const Node &node);
 private:
  std::string value;
  std::unordered_map<char, Node> next;
};
}

#endif // POLIDB_NODE_H