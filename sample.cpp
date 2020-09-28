#include <vector>
#include <iostream>
#include <unordered_map>  // for std::unordered_map
#include <cstring>
//返却値 : 等しければ 0、s1 が s2 より大きければ正の整数値、s1 が s2 より小さければ負の整数値を返す。
// int strcmp(const char* s1, const char* s2);

//======================================
std::vector<int> str_list = { 1,2,3,4,5,6,7,8,9,10 };
std::vector<int> table;

int hash(int a){

  return a % 11;
}
//======================================

int main() {
   int key = 9;
   for(int i = 0; i < str_list.size();i++){
     int x =hash(str_list[i]);
     table.push_back(x);
        if(table[i] == key){
            std::cout << "Yes" << std::endl;
            break;
        }
        else{
            std::cout << "No" << std::endl;
        }
    }
   
  
    
    return 0;
}