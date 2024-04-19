#include<bits/stdc++.h>
using namespace std;


int main(){
  int t;
  cin>>t;
  while(t--){
    int size;
    cin>>size;
    vector<int> array;
    for(int index = 0; index < size; index ++){
      int value;
      cin>>value;
      array.push_back(value);
    }
    vector<int> prefix_array;
    prefix_array.push_back(-1);
    for(int index = 1; index < size; index++){
      if(array[index] != array[index-1]){
        prefix_array.push_back(index-1);
      }else{
        prefix_array.push_back(prefix_array[index-1]);
      }
    }

    /*for(int value : prefix_array){
      cout<<value<<" ";
    }*/
    //cout<<endl;
    int q;
    cin>>q;
    while(q--){
      int l, r;
      cin>>l>>r;
      l-=1;r-=1;
      if(prefix_array[r] < l){
        cout<<-1<<" "<<-1<<endl;
      }else{
        cout<<prefix_array[r]+1<<" "<<r+1<<endl;
      }
    }
  }
  return 0;
}
