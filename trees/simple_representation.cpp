#include<iostream>
using namespace std;
struct Node{
    int val;
    Node *left,*right;
    Node(int data){
      val = data;
      left = right = NULL;
    }
};



int main(){
  Node *root = new Node(100);
  root->left = new Node(10);
  cout<<(root->left->val)<<endl;
  return 0;
}
