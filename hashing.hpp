#ifndef OPEN_ADRESS__HASHING_HPP_
#define OPEN_ADRESS__HASHING_HPP_
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

namespace kuroda {

class HashTableInterface {
public:
  virtual int const get(int key) = 0;
  virtual void set(int key, int value) = 0;
};

class HashTable : public HashTableInterface{
// TODO: Needs implementation by yourself.
static constexpr int SIZE = 256;
//-------------------------------------------------------------------
/* DataItemの定義 */
private:
struct DataItem{
    int data = -1;
    int key;
};
public:
struct DataItem hashArray[SIZE] = {};//
std::vector<bool> empty_check;
HashTable(){
    empty_check.resize(SIZE,0);
};

/* ハッシュ関数の定義 */
int hashCode(int key){
    return key % SIZE;
}

/* 検索のための関数 */
/* liner Probingを使っているのでそれに合わせた検索を実装です。 */
int const get(int key){
    //get the hash
    
    int hashIndex = hashCode(key);
    //return hashArray[hashIndex].data;
    //move in array until an empty
    
    while (empty_check[key] == 1){//要素が使用済みになるまで
        std::cout << key << std::endl;
        std::cout << " ------------------- " << std::endl;
        if (hashArray[hashIndex].key == key)
            return hashArray[hashIndex].data;
            //ここでは256のあまりが返る
        hashIndex++;

        //wrap around the table
        hashIndex %= SIZE;
    }
    return hashArray[hashIndex].data;//ここでは初期値が返る
}
//ハッシュテーブルの中身を
/* 挿入のための関数 */
//ハッシュ値の衝突が発生した場合は、再ハッシュを繰り返して、「空状態」バケットを調べていき、空いているバケットを発見したらデータを格納します。
void set(int key, int data){
    hashArray[key].data = data;
    hashArray[key].key = key;
    empty_check[key] = 1;//使用済みにする
    std::cout << sizeof(empty_check[key]);//8

    //get the hash
    int hashIndex = hashCode(key);
    //move in array until an empty or deleted cell
    int collision = 0;//衝突回数 のちにXorshiftで使うかも
    while (empty_check[hashIndex] == 1 ){//衝突が起こったとき
        //go to next cell
        ++hashIndex;
        ++collision;
        //wrap around the table
        hashIndex %= SIZE;
        std::cout << "rehash = " << collision << std::endl;
    }
    collision = 0;
}
//-------------------------------------------------------------------
};

}

#endif //OPEN_ADRESS__HASHING_HP