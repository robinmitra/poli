#include <string>
#include <unordered_map>

namespace polidb {
class Node {
 private:
  std::string value;
  std::unordered_map<char, Node> next;
 public:
  void setValue(std::string value);
  std::string getValue();
  std::unordered_map<char, Node> & getNext();
};
}