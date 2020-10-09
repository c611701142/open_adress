#ifndef OPEN_ADRESS__HASHING_HPP_
#define OPEN_ADRESS__HASHING_HPP_
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

namespace kuroda {

class HashTableInterface {
public:
  virtual int get(int key) const = 0;
  virtual void set(int key, int value) = 0;
};

class HashTable : public HashTableInterface{
// TODO: Needs implementation by yourself.
public:
  static constexpr int kIndexSize = 0x100;
private:
  std::unordered_map<int, int> v;
public:
  HashTable() {
  }
  
  
  void set(int key, int value){
    v[key] = value; 
  }

  int get(int key) const{  
    std::cout << v.count(key) << std::endl;  
    //setでアクセスしたところ(4の倍数)は1、他は0になる
    if(v.count(key) == 0) { 
      return -1;
    }
    int target = v.find(key)->second;
    return target;

  }

};

}

#endif //OPEN_ADRESS__HASHING_HPP