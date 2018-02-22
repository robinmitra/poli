#include <string>
#include "node.h"
#include "trie_iterator.h"

namespace polidb {
class Trie {
 private:
  Node root = Node();
  Node put(Node node, std::string key, std::string value, int index);
  Node get(Node node, std::string key, int index);

 public:
  void put(std::string key, std::string value);
  std::string get(const std::string &key);
  TrieIterator begin();
  TrieIterator end();
};
}