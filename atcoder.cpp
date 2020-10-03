#include <vector>
#include <iostream>
#include <unordered_map>  // for std::unordered_map
#include <cstring>

int main() {
  int n;
  std::cin >> n;
  char s[n-1];
  for(int i = 0; i < n; i++){
      std::cin >> s[i];
  }
  std::vector<char> v(s, s + sizeof(s));
  std::cout << count(v.begin(), v.end(), 'A');
  //count' was not declared in this scope このエラーが出ます

  int count;
  
 if(n > 4){
     count = 1;
      for(int i = 0; i < n-1; i++){
          if(s[i] == 'A' && s[i+1] == 'T' ){
            count++;
          }
          else if(s[i] == 'T' && s[i+1] == 'A' ){
            count++;
          }
          else if(s[i] == 'C' && s[i+1] == 'G' ){
            count++;
          }
          else if(s[i] == 'G' && s[i+1] == 'C' ){
            count++;
          }

      }
  }

  else {
     count = 0;
      for(int i = 0; i < n-1; i++){
          if(s[i] == 'A' && s[i+1] == 'T' ){
            count++;
          }
          else if(s[i] == 'T' && s[i+1] == 'A' ){
            count++;
          }
          else if(s[i] == 'C' && s[i+1] == 'G' ){
            count++;
          }
          else if(s[i] == 'G' && s[i+1] == 'C' ){
            count++;
          }

      }
  }
  std::cout << count;
    return 0;
}