#include "hashing.hpp"

#include <vector>
#include <ctime>
#include <iostream>

namespace {

constexpr int kIndexSize = 0x100;

}

int main() {
  std::srand(time(0));

  /*
   * Unstored value needs to be -1
   */
  kuroda::HashTable ht;
  std::vector<int> expect_list(kIndexSize, -1);
  for (int key = 0; key < kIndexSize; key++) {
    if (std::rand()%4 == 0) {
      auto expect_value = std::rand()%kIndexSize;
      ht.set(key, expect_value);
      expect_list[key] = expect_value;
    }
  }

  // Test
  int miss = 0;
  for (int key = 0; key < kIndexSize; key++) {
    auto stored_value = ht.get(key);
    if (stored_value != expect_list[key]) {
      std::cout << "ht[" << key << "] != " << stored_value << ", expected: " << expect_list[key] << std::endl;
      ++miss;
    }
  }
  if (miss > 0) {
    std::cout << "Missed value counts: " << miss << std::endl;
  } else {
    std::cout << "OK" << std::endl;
  }

  return 0;
}
