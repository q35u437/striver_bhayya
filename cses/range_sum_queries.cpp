#include<bits/stdc++.h>
using namespace std;
 
class segtree{
	public:
		vector<long long> tree;
		segtree(long long size){
			tree.resize(4*size);
		}
 
		void build(int index, int low, int high, vector<long long> &array){
			if(low == high){
				tree[index] = array[low];
				return;
			}
			int middle = low + (high-low)/2;
			build(2*index+1,low,middle,array);
			build(2*index+2,middle+1,high,array);
			tree[index] = tree[2*index+1] + tree[2*index+2];
		}
 
		long long query(int index, int low, int high, int l, int r){
			if(l > high or r < low){
				return 0;
			}	
 
			if(l <= low and high <= r){
				return tree[index];
			}
 
			int middle = low + (high-low)/2;
			long long lans = query(2*index+1,low,middle,l,r);
			long long rans = query(2*index+2,middle+1,high,l,r);
			return lans+rans;
		}
};
 
 
int main(){
	long long n,q;
	cin>>n>>q;
	vector<long long> array;
	segtree seg = segtree(n);
	for(long long i=0;i<n;i++){
		long long value;
		cin>>value;
		array.push_back(value);
	}
	seg.build(0,0,n-1,array);
	while(q--){
		long long l,r;
		cin>>l>>r;
		l-=1;
		r-=1;
		cout<<seg.query(0,0,n-1,l,r)<<endl;
	}
	return 0;
}
