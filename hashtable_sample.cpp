#include <vector>
#include <iostream>
#include <unordered_map>  // for std::unordered_map
#include <cstring>

//線形探索法(Linear Probing)
//本来入るべきであった場所の隣で妥協していく方法


//探索
//キーからハッシュ値を求め、バケットのデータがキーに対応する値をチェック、正しければ探索完了、異なれば、次の値を探すか(線形探索法)、再ハッシュを繰り返すか(二重探索法)し、たどり着くまで繰り返す。
//消去
//バケットを空にしてしまうと、以降の探索ができなくなってしまう。(これは、線形探索法でも、二重ハッシュ法でも、衝突が置きたデータは同じハッシングによって連続して格納されているため、NULLが入ると、そこで探索が終わってしまうから)。バケットは空にせず、ダミーの「消去済み」というオブジェクトを入れる。探索においては、ダミーをスキップして処理を行わせる必要がある。
//再挿入
//「消去済み」バケットは、「空状態」バケットと同じように扱う。

#define SIZE 20

/* DataItemの定義 */
struct DataItem
{
    int data;
    int key;
};

struct DataItem *hashArray[SIZE];
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
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

/* 挿入のための関数 */
//ハッシュ値の衝突が発生した場合は、再ハッシュを繰り返して、「空状態」バケットを調べていき、空いているバケットを発見したらデータを格納します。
void insert(int key, int data)
{

    struct DataItem *item = (struct DataItem *)malloc(sizeof(struct DataItem));
    //mallocをnewに書き換えたいのですが、やり方がわかりません
    item->data = data;
    item->key = key;

    //get the hash
    int hashIndex = hashCode(key);

    //move in array until an empty or deleted cell
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
    {
        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }
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

        if (hashArray[hashIndex]->key == key)
        {
            struct DataItem *temp = hashArray[hashIndex];

            //assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem;
            return temp;
        }

        //go to next cell
        ++hashIndex;

        //wrap around the table
        hashIndex %= SIZE;
    }

    return NULL;
}

void display()
{
    int i = 0;

    for (i = 0; i < SIZE; i++)
    {

        if (hashArray[i] != NULL)
            printf(" (%d,%d)", hashArray[i]->key, hashArray[i]->data);
        else
            printf(" ~~ ");
    }

    printf("\n");
}

int main()
{
    dummyItem = (struct DataItem *)malloc(sizeof(struct DataItem));
    //
    dummyItem->data = -1;
    dummyItem->key = -1;

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);

    display();
    item = search(37);

    if (item != NULL)
    {
        printf("Element found: %d\n", item->data);
    }
    else
    {
        printf("Element not found\n");
    }

    fade (item);
    item = search(37);

    if (item != NULL)
    {
        printf("Element found: %d\n", item->data);
    }
    else
    {
        printf("Element not found\n");
    }
}
/*
int main () {
    
    int* p = nullptr;//NULLの代わり
    try {
        p = new int[10];
        std::cout << p << std::endl;
    } catch (const std::bad_alloc& e) {
        std::cout << "cannot be allocated." << std::endl;
    }
    
    delete p;
    
    return 0;
}*/