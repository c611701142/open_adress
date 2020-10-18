#ifndef OPEN_ADRESS__HASHING_HPP_
#define OPEN_ADRESS__HASHING_HPP_
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>

namespace kuroda {

class HashTableInterface {
public:
  virtual int get(int key) = 0;
  virtual void set(int key, int value) = 0;
};

class HashTable : public HashTableInterface{
// TODO: Needs implementation by yourself.
public:
  HashTable()= default;
  #define SIZE 256
//-------------------------------------------------------------------
/* DataItemの定義 */
private:
struct DataItem{
    int value;
    int key;
};
public:
struct DataItem *hashArray[SIZE];//ポインタ、アドレスを割り当てる
struct DataItem *dummyItem;
struct DataItem *item;
//sizeof(item) = 8;

/* ハッシュ関数の定義 */
int hashCode(int key){
    return key % SIZE;
}

/* 検索のための関数 */
/* liner Probingを使っているのでそれに合わせた検索を実装です。 */
struct DataItem *search(int key){
    //get the hash
    int hashIndex = hashCode(key);
    //move in array until an empty
    while (hashArray[hashIndex] != NULL){
        std::cout << key << std::endl;
        std::cout << " ------------------- " << std::endl;
        if (hashArray[hashIndex]->key == key)
            return hashArray[hashIndex];

        //go to next cell
        hashIndex++;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

//ハッシュテーブルの中身を表示
//{(key0,value0),(key1,value1),.......,(key255,value255)}みたいなイメージです
void display(){
    int i = 0;
    std::cout << "data_size" << sizeof(DataItem) << std::endl;
    std::cout << "hashtable_size" << sizeof(hashArray) << std::endl;
    std::cout << "table_size" << sizeof(item) << std::endl;
    for (i = 0; i < SIZE; i++){
        std::cout << " corganp check" << std::endl;
        std::cout << i ;
        if (hashArray[i] != NULL){
            printf(" (%d,%d)", hashArray[i]->key, hashArray[i]->value);
            //ここの初期値が決まっていないので(1818195295,1919186944)
            //みたいになってしまいます
        }
        else{
            printf(" ~~ ");
        }   
    }
    printf("\n");
}

/* 挿入のための関数 */
//ハッシュ値の衝突が発生した場合は、再ハッシュを繰り返して、「空状態」バケットを調べていき、空いているバケットを発見したらデータを格納します。
void set(int key, int value){
    //display();
    std::cout << "random_select";
    std::cout << key << "," << value << std::endl;
    //display();
    DataItem *item = (DataItem *)malloc(sizeof(DataItem));
    //mallocをnewに書き換えたいのですが、やり方がわかりません
    item->value = value;
    item->key = key;
    
    int collison = 0;//衝突回数(再ハッシュした回数)

    //get the hash
    int hashIndex = hashCode(key);
    //move in array until an empty or deleted cell
    while (hashArray[hashIndex] != NULL /*&& hashArray[hashIndex]->key != -1*/){
        //go to next cell
        hashIndex++;
        //wrap around the table
        hashIndex %= SIZE;
        /*
        std::cout << hashArray[hashIndex]->key << ",,,";この２つにアクセスしようとすると、セグメントエラー
        std::cout << hashArray[hashIndex]->value << std::endl;
        */

        collison++;
    }
    // ポインタに対してオブジェクトを代入するということをやっています。
    hashArray[hashIndex] = item;
    //std::cout << "hashtable_number_after" << hashIndex << std::endl;
    std::cout << key << "," << value << " --rehash_time="<< collison << std::endl;
}

int get(int key){  
    dummyItem = (DataItem *)malloc(sizeof( DataItem));
    dummyItem->value = -1;
    dummyItem->key = -1;
    item = search(key);
    std::cout << " ------------------- " << std::endl;
    return -1;
}


//-------------------------------------------------------------------
};

}

#endif //OPEN_ADRESS__HASHING_HP