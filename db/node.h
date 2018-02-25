#ifndef POLIDB_NODE_H
#define POLIDB_NODE_H

#include <string>
#include <unordered_map>

namespace polidb {
class Node {
 public:
  void setValue(const std::string &value);
  void resetValue();
  std::string getValue() const;
  const std::unordered_map<char, Node> &getNext() const;
  std::unordered_map<char, Node> &getNext();
  void setNextNode(const char &nodeKey, const Node &node);
  void removeNextNode(const char &nodeKey);
  void resetNextNodeValue(const char &nodeKey);
  bool hasNextNode(const char &key) const;
 private:
  std::string value;
  std::unordered_map<char, Node> next;
};
}

#endif // POLIDB_NODE_H