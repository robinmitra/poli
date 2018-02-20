#include <iostream>
#include "../includes/db.h"

using namespace polidb;

int main() {
  // Instantiate
  Db db;

  // Put key-value pairs
  db.put("name", "Robin");

  // Get key-value pairs
  std::string name = db.get("name");
  std::cout << name;

  // Iterate through key-value pairs

  return 0;
}