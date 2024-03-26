#include<bits/stdc++.h>
using namespace std;

struct SegTree{
	public:
		vector<int> seg;
		SegTree(int size){
			seg.resize(4*size);
		}

		void build(int index, int low, int high, vector<int> &array, int flag){
			if(low == high){
				seg[index] = array[low];
				return;
			}
			int middle = low + (high-low)/2;
			build(2*index+1,low,middle,array,!flag);
			build(2*index+2,middle+1,high,array,!flag);
			if(flag) seg[index] = seg[2*index+1] ^ seg[2*index+2];
			else seg[index] = seg[2*index+1] | seg[2*index+2];
		}

		void update(int index, int low, int high, int ind, int value, int flag){
			if(low==high){
				seg[index] = value;
				return;
			}
			int middle = low + (high-low)/2;
			if(ind <= middle){
				update(2*index+1,low,middle,ind,value,!flag);
			}else{
				update(2*index+2,middle+1,high,ind,value,!flag);
			}
			if(flag) seg[index] = seg[2*index+1] ^ seg[2*index+2];
			else seg[index] = seg[2*index+1] | seg[2*index+2];	
		}
};



int main(){
	int n,m;
	cin>>n>>m;
	int length = 1<<n;
	vector<int> array;
	for(int i=0;i<length;i++){
		int value;
		cin>>value;
		array.push_back(value);
	}
	SegTree seg(length);
	if(n%2){
		seg.build(0,0,length-1,array,0);
	}else{
		seg.build(0,0,length-1,array,1);
	}
	while(m--){
		int index,value;
		cin>>index>>value;
		if(n%2){
			seg.update(0,0,length-1,index-1,value,0);
		}else{
			seg.update(0,0,length-1,index-1,value,1);
		}
		cout<<seg.seg[0]<<endl;
	}
	return 0;
}
