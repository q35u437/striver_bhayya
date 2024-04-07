//you are given a string consisting of only A and B, now you have to remove substrings AB or BB present in the string any number of times
//what is the minimum length you can get
#include<bits/stdc++.h>
using namespace std;

int main(){
  string str;
  cin>>str;
  int index = 0, length = str.size(), answer = length;
  while(index < length-1){
    if((str[index] == 'A' and str[index+1] == 'B') or (str[index] == 'B' or str[index+1] == 'B')){
      if(index == 0 or index >= length-2){
        answer -= 2;
      }else{
        answer -= 2;
        if((str[index-1] == 'A' and str[index+2] == 'B') or (str[index-1] == 'B' and str[index+2] == 'B')){
          answer -= 2;
          index++;
        }
      }
      index+=2;
    }else{
      index++;
    }
  }
  cout<<answer<<endl;
  return 0;
}
