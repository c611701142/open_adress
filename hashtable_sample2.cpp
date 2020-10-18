#include <vector>
#include <iostream>
#include <unordered_map>  // for std::unordered_map
#include <cstring>

#define SIZE 256
//ハッシュテーブルのサイズ、(key,value)が格納される
//  insertする回数より少ないとセグメントエラー
//線形探索法(Linear Probing)
//本来入るべきであった場所の隣で妥協していく方法

/* DataItemの定義 */
struct DataItem{
    int data;
    int key;
};

struct DataItem *hashArray[SIZE];//
struct DataItem *dummyItem;
struct DataItem *item;

/* ハッシュ関数の定義 */
int hashCode(int key)
{
    return key % SIZE;
}

/* 検索のための関数 */
/* liner Probingを使っているのでそれに合わせた検索を実装です。 */
struct DataItem *search(int key)
{
    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty
    while (hashArray[hashIndex] != NULL)
    {

        if (hashArray[hashIndex]->key == key)
            return hashArray[hashIndex];

        //go to next cell
        hashIndex++;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

/* 挿入のための関数 */
//ハッシュ値の衝突が発生した場合は、再ハッシュを繰り返して、「空状態」バケットを調べていき、空いているバケットを発見したらデータを格納します。
void insert(int key, int data){
    DataItem *item = (DataItem *)malloc(sizeof(DataItem));
    //mallocをnewに書き換えたいのですが、やり方がわかりません
    //ポインタを使わず、vectorのresizeで拡張してはだめなのですが
    item->data = data;
    item->key = key;

    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty or deleted cell
    int collision = 0;//衝突回数 のちにXorshiftで使うかも
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1){//衝突が起こったとき
        //go to next cell
        hashIndex++;
        collision++;
        //wrap around the table
        hashIndex %= SIZE;
    }
    //std::cout << hashArray[hashIndex]->key << std::endl;
    std::cout << key << std::endl;
    std::cout << "rehash = " << collision << std::endl;
    collision = 0;
    // ポインタに対してオブジェクトを代入するということをやっています。
    hashArray[hashIndex] = item;
}
//消去
//バケットを空にしてしまうと、以降の探索ができなくなってしまう。(これは、線形探索法でも、二重ハッシュ法でも、
//衝突が置きたデータは同じハッシングによって連続して格納されているため、NULLが入ると、そこで探索が終わってしまうから)。
//バケットは空にせず、ダミーの「消去済み」というオブジェクトを入れる。探索においては、ダミーをスキップして処理を行わせる必要がある。


struct DataItem *fade (struct DataItem *item)
{
    int key = item->key;

    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty
    while (hashArray[hashIndex] != NULL)
    {

        if (hashArray[hashIndex]->key == key){
            DataItem *temp = hashArray[hashIndex];

            //assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem;
            return temp;
        }

        //go to next cell
        hashIndex++;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void display(){
    int i = 0;
    for (i = 0; i < SIZE; i++){
        if (hashArray[i] != NULL)
            printf(" (%d,%d)", hashArray[i]->key, hashArray[i]->data);
        else
            printf(" ~~ ");
    }
    for (i = 0; i < SIZE; i++){
        if (hashArray[i] != NULL){
            //std::cout << "key" << hashArray[i]->key << std::endl;
            //std::cout << "data" << hashArray[i]->data << std::endl;
        }
        else{
            printf(" ~~ ");
        }
    }
    printf("\n");
}

constexpr int kIndexSize = 0x100;//256
int main(){
    dummyItem = (struct DataItem *)malloc(sizeof( DataItem));
    //
    dummyItem->data = -1;
    dummyItem->key = -1;

    std::srand(10);
    std::vector<int> expect_list(kIndexSize, -1);
    for (int key = 0; key < kIndexSize; key++) {
        if (std::rand()%4 == 0) {
            auto expect_value = std::rand()%kIndexSize;
            expect_list[key] = expect_value;
            insert(key, expect_value);
        }
        else
        {
            insert(key,-1);
        }
        
    std::cout << key << " "  << expect_list[key] << std::endl;
    }
    std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaa" << std::endl;
    //insert(1, 20);
 
    int miss = 0;
    for (int key = 0; key < kIndexSize; key++) {
    item = search(key);
    auto stored_value = item->data;
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
    display();
    /*
    for(int i = 0; i < kIndexSize; i++){
        item = search(i);//key検索すると、dataと結び付けられる

        if (item != NULL){
            printf("Element found: %d\n", item->data);
        }
        else{
            printf("Element not found\n");
        }
    }*/
    fade (item);//消してしまった
}