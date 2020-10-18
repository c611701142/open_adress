#include "hashing.hpp"

#include <vector>
#include <ctime>
#include <iostream>
using namespace std;

namespace {

constexpr int kIndexSize = 0x100;//256

}

int main() {
  std::srand(time(0));
  //srandは乱数生成
  //timeは現在時刻を取得

  /*
   * Unstored value needs to be -1
   */
  kuroda::HashTable ht;
  std::vector<int> expect_list(kIndexSize, -1);
  for (int key = 0; key < kIndexSize; key++) {
    //std::cout << "key" << key <<  std::endl;
    if (std::rand()%4 == 0) {
      auto expect_value = std::rand()%kIndexSize;
      ht.set(key, expect_value);
      expect_list[key] = expect_value;
      std::cout << "key" << key << "expected_value= " << expect_value << std::endl;
    }
    /*
    else{
      ht.set(key, -1);//黒田追記
      std::cout << "-----first complete---------" << std::endl;
    }*/
  }//ここのfor文が途中で止まってしまいます。
  //少し煮詰まっているので、相談しました。
  std::cout << "-----insert complete---------" << std::endl;



  // Test
  int miss = 0;
  for (int key = 0; key < kIndexSize; key++) {
    //auto stored_value = ht.get(key);
    auto stored_value = ht.get(key);
    std::cout << "key" << key << "stored_value= " << stored_value << std::endl;
    if (stored_value != expect_list[key]) {
      std::cout << "ht[" << key << "] != " << stored_value << ", expected: " << expect_list[key] << std::endl;
      miss++;
    }
  }
  if (miss > 0) {
    std::cout << "Missed value counts: " << miss << std::endl;
  } else {
    std::cout << "OK" << std::endl;
  }
//test1
ht.set(1, 10);
ht.set(0, 11);
int v = ht.get(1);
std::cout << v << std::endl;

  return 0;
}