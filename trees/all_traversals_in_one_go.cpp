#include<bits/stdc++.h>
using namespace std;

struct Node{
	int val;
	struct Node *left, *right;
	Node(int data){
		val = data;
		left = right = NULL;
	}
};


void getAll(Node *root){
	if(!root){
		cout<<"Pre-order: {}"<<endl;
		cout<<"In-order: {}"<<endl;
		cout<<"Post-order: {}"<<endl;
		return;
	}
	stack<pair<Node*,int>> s;
	vector<int> preorder,inorder,postorder;
	s.push({root,1});
	while(!s.empty()){
		auto it = s.top();
		if(it.second == 1){
			preorder.push_back(it.first->val);
			s.pop();
			it.second ++;
			s.push(it);
			if(it.first->left){
				s.push({it.first->left, 1});
			}
		}else if(it.second == 2){
			inorder.push_back(it.first->val);
			s.pop();
			it.second++;
			s.push(it);
			if(it.first->right){
				s.push({it.first->right, 1});
			}
		}else{
			postorder.push_back(it.first->val);
			s.pop();
		}
	}
	cout<<"Pre-order: ";
	for(int i:preorder)
		cout<<i<<" ";
	cout<<endl;
	cout<<"Inorder: ";
	for(int i:inorder)
		cout<<i<<" ";
	cout<<endl;
	cout<<"Postorder: ";
	for(int i:postorder)
		cout<<i<<" ";
	cout<<endl;
}

int main(){
	Node *root = new Node(1);
	root->left = new Node(2);
	root->left->left = new Node(3);
	root->left->right = new Node(4);
	root->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	getAll(root);
	return 0;
}
