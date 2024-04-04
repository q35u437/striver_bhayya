#include<bits/stdc++.h>
using namespace std;


int main(){
	int n;
	long long x;
	cin>>n>>x;
	vector<pair<long long, int>> array;
	for(int i=0;i<n;i++){
		long long valie;
		cin>>valie;
		array.push_back({valie,i+1});
	}
	sort(array.begin(), array.end());
	for(int i=0;i<n;i++){
		long long target = x - array[i].first;
		t
		int left = i+1, right = n-1;
		while(left < right){
			if(array[left].first + array[right].first < target){
				left++;
			}else if(array[left].first + array[right].first > target){
				right--;
			}else if(left < right and array[left].first + array[right].first == target){
				cout<<array[i].second<<" "<<array[left].second<<" "<<array[right].second<<endl;
				return 0;
			}
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
}
