#include<bits/stdc++.h>
using namespace std;
 
 
 
class seg{
	public:
		vector<int> tree;
		seg(int size){
			tree.resize(4*size);
		}
		void build(int index, int low, int high, vector<int> &array){
			if(low == high){
				tree[index] = array[low];
				return;
			}
			int middle = low + (high-low)/2;
			build(2*index+1,low,middle,array);
			build(2*index+2,middle+1,high,array);
			tree[index] = min(tree[2*index+1], tree[2*index+2]);
		}
		int query(int index, int low, int high, int l, int r){
			if(l > high or r < low){
				return INT_MAX;
			}
 
			if(low >= l and high <=r ){
				return tree[index];
			}
 
			int middle = low + (high-low)/2;
			int lefans = query(2*index+1,low,middle,l,r);
			int rightans = query(2*index+2,middle+1,high,l,r);
			return min(lefans, rightans);
		}
};
 
int main(){
	int n,q;
	cin>>n>>q;
	vector<int> array;
	for(int i=0;i<n;i++){
		int value;
		cin>>value;
		array.push_back(value);
	}
	seg segt = seg(n);
	segt.build(0,0,n-1,array);
	while(q--){
		int a,b;
		cin>>a>>b;
		a-=1;
		b-=1;
		cout<<segt.query(0,0,n-1,a,b)<<endl;
	}	
	return 0;
}
