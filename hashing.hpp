#ifndef OPEN_ADRESS__HASHING_HPP_
#define OPEN_ADRESS__HASHING_HPP_
#include <iostream>
#include <vector>
#include <unordered_map>  // for std::unordered_map
using namespace std;

namespace kuroda {


class HashTableInterface {
 public:
  virtual int get(int key) const = 0;//const消すとコンパイル通りました
  virtual void set(int key, int value) = 0;
};

class HashTable : public HashTableInterface{

/*void set(int key, int value){
      //std::unordered_map<int, int> mp;    //  int → int のハッシュ連想配列
    mp[key] = value;
    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        std::cout << "key = " << itr->first           // キーを表示
                        << ", val = " << itr->second << "\n";    // 値を表示
    }*/  
 //}//この関数が呼び出されるのは、4の倍数が選ばれたとき

public:
  static constexpr int kIndexSize = 0x100;
private:
  std::vector<int> v;
  int target;
public:
  HashTable() {
    v.resize(kIndexSize, -1);
  }
  //constexpr int kIndexSize = 0x100;//256
  
  void set(int key, int value){
    std::cout << "key =" << key << std::endl;
    v.insert(v.begin() + key, value);
    
  }//この関数が呼び出されるのは、4の倍数が選ばれたとき

  int get(int key) const{

    std::cout << "target = " << v[key] << std::endl;
    std::cout << "key = " << key << std::endl;
    std::cout << "size = " << v.size()  << std::endl;
    //return target % 256;

    //target =  v[key];
    //return target;
    return v[key];

  }//ここで返す値をexpected_valueと一致させたい

};

}

#endif //OPEN_ADRESS__HASHING_HPP_