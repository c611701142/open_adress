#ifndef OPEN_ADRESS__HASHING_HPP_
#define OPEN_ADRESS__HASHING_HPP_
#include <iostream>
#include <vector>

namespace kuroda {

/*
class HashTableInterface {
 public:
  virtual int get(int key) const = 0;
  virtual void set(int key, int value) = 0;
};*/

//cannot declare variable 'ht' to be of abstract type 'kuroda
//のエラーがでたのでクラスを１つにしています(こうしたら動きました)

/*
 * Unstored value needs to be -1
 */
constexpr int kIndexSize = 0x100;//256
std::vector<int> v(kIndexSize, -1);


class HashTable{
// TODO: Needs implementation by yourself.
public:
int target;
void set(int key, int value){
  std::cout << "key =" << key << std::endl;
  v.insert(v.begin() + key, value);
  //std::cout << "wwwwwwwwwwwww" << std::endl;
  //v.erase(v.end());
  //質問です
  //33行目の配列要素削除をすると、セグメントエラーが起こると思うのですがなぜかわかりません
  //おそらく配列外参照になっていると思うのですが
  
 };//この関数が呼び出されるのは、4の倍数が選ばれたとき

int get(int key){

  std::cout << "target = " << v[key] << std::endl;
  std::cout << "key = " << key << std::endl;
  std::cout << "size = " << v.size()  << std::endl;
   //return target % 256;

  target =  v[key];
  return target;

 };//ここで返す値をexpected_valueと一致させたい

};

}

#endif //OPEN_ADRESS__HASHING_HPP_