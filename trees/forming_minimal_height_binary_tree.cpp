//ps: please don't stalk the code i have written

#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
  int a,b,c;
  cin>>a>>b>>c;
  if(a!=c-1){
   cout<<-1<<endl;      // not a valid binary tree
  }else if(a+b+c==1){
   cout<<0<<endl; //only one node so the height is zero	
  }else{
    //if n are number of nodes in binary tree, the minimum height a binary tree can have is
    //log2(n) + 1
    //the maximum height is n itself
       int answer = 0, currentlevel_number_of_nodes = 1, nextlevel_number_of_nodes = 0;
       for(int i=0;i<a;i++){ //right now using all the 2 child nodes
     if(currentlevel_number_of_nodes > 0){
       currentlevel_number_of_nodes--;
       nextlevel_number_of_nodes+=2; //for every one node we are getting two nodes
     }
     if(currentlevel_number_of_nodes <= 0){
       swap(currentlevel_number_of_nodes, nextlevel_number_of_nodes);
       answer++; //increment the height of tree
     }
      }
      for(int i=0;i<b;i++){
        if(currentlevel_number_of_nodes > 0){
          currentlevel_number_of_nodes--;
          nextlevel_number_of_nodes++; // now since we are using 1 child vertices 
               // for every one node only one node is added
        }

        if(currentlevel_number_of_nodes <= 0){
          swap(currentlevel_number_of_nodes, nextlevel_number_of_nodes);
          answer++;
        }
      }
      if(currentlevel_number_of_nodes < c)
        answer++;
      cout<<answer<<endl;
  }
}
return 0;
}
