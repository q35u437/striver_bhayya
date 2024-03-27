#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
 
template<typename T>
using ordered_set = tree <T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//the above part is ordered_set from GNU that does operations in logarithmic time.
//it is a policy based data structure
 
int main(){
	int n, k;
	cin>>n>>k;
	vector<int> values;
	for(int i=0;i<n;i++){
		int value;
		cin>>value;
		values.push_back(value);
	}
	ordered_set<pair<int, int>> window;
	for(int i=0;i<k;i++){
		window.insert({values[i], i});
	}
	cout<<window.find_by_order((k-1)/2)->first<<" ";
	for(int i=1;i<n-k+1;i++){
		window.erase({values[i-1],i-1});
		window.insert({values[i+k-1],i+k-1});
		cout<<window.find_by_order((k-1)/2)->first<<" ";
	}
	return 0;
}
