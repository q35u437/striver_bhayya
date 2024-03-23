#include<bits/stdc++.h>
using namespace std;


class SegTree{
	private:
		vector<int> seg;
	public:
		SegTree(int size){
			seg.resize(4*size);
		}

		void build(int index, int low, int high, vector<int> &array){
			if(low == high){
				seg[index] = array[low];
				return;
			}
			int middle = low + (high-low)/2;
			build(2*index+1,low,middle,array);
			build(2*index+2,middle+1,high,array);
			seg[index] = min(seg[2*index+1],seg[2*index+2]);
		}

		int query(int index, int low, int high, int l, int r){
			//no overlap
			if(l > high or r < low){
				return INT_MAX;
			}

			if(low >= l and high <= r){
				return seg[index];
			}

			int middle = low + (high-low)/2;
			int ans1 = query(2*index+1,low,middle,l,r);
			int ans2 = query(2*index+2,middle+1,high,l,r);
			return min(ans1, ans2);
		}

		void update(int index, int low, int high, int ind, int value){
			if(low==high){
				seg[index] = value;
				return;
			}
			int middle = low + (high-low)/2;
			if(ind <= middle)
				update(2*index+1,low,middle,ind,value);
			else 
				update(2*index+2,middle+1,high,ind,value);
		}
};


int main(){
	int length1,length2;
	vector<int> arr1,arr2;
	cin>>length1;
	for(int i=0;i<length1;i++){
		int value;
		cin>>value;
		arr1.push_back(value);
	}
	cin>>length2;
	for(int i=0;i<length2;i++){
		int value;
		cin>>value;
		arr2.push_back(value);
	}
	SegTree seg1(length1);
	SegTree seg2(length2);
	seg1.build(0,0,length1-1,arr1);
	seg2.build(0,0,length2-1,arr2);
	int q;
	cin>>q;
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			int min1,min2,l1,r1,l2,r2;
			cin>>l1>>r1>>l2>>r2;
			min1 = seg1.query(0,0,length1-1,l1,r1);
			min2 = seg2.query(0,0,length2-1,l2,r2);
			cout<<min(min1,min2)<<endl;
		}else{
			int whicharr;
			cin>>whicharr;
			int ind,value;
			cin>>ind>>value;
			if(whicharr==1){
				seg1.update(0,0,length1-1,ind,value);
				arr1[ind]=value;
			}else{
				seg2.update(0,0,length2-1,ind,value);
				arr2[ind]=value;
			}
		}
	}
	return 0;
}
