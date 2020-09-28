#include <vector>
#include <iostream>
#include <unordered_map>  // for std::unordered_map
#include <cstring>
//返却値 : 等しければ 0、s1 が s2 より大きければ正の整数値、s1 が s2 より小さければ負の整数値を返す。
// int strcmp(const char* s1, const char* s2);

//======================================
std::vector<std::string> table = { "black", "blue", "green", "red" };
//======================================

#define dkeysize (12)

typedef struct _node{
    char key[dkeysize];
    struct _node *next;
}node;

int hash(char *keys){
    return *keys - 'a';

}

node *hashsearch(char *target, node *table[], int b){
    int index;
    node *node1;

    index = hash(target) % b;
    node1 = table[index];
    while(node1 != NULL){
        if(!strcmp(node1->key, target)){
            return node1;
        }
        node1 = node1 -> next;    
    }
    return NULL;
}

int linearsearch(char *target,node table[],int n){
    int pos;
    for(pos=0;pos < n;pos++){
        if(!strcmp(target,table[pos].key)){
            return pos;
        }
    }
    return -1;//不成功探索

}

int main() {
   /* for(std::string str : str_list) {//ここ検索
    int index = hash(str) % 7;
    }*/
    int index1 = hash("black") % 7;
    int index2 = hash("blue") % 7;
    int index3 = hash("green") % 7;
    int index4 = hash("red") % 7;
    
    std::cout << index1 << std::endl;
    std::cout << index2 << std::endl;
    std::cout << index3 << std::endl;
    std::cout << index4 << std::endl;
    return 0;
}