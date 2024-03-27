#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	cin>>n>>x;
	vector<int> prices, pages;
	for(int i=0;i<n;i++){
		int value;
		cin>>value;
		prices.push_back(value);
	}
	for(int i=0;i<n;i++){
		int value;
		cin>>value;
		pages.push_back(value);
	}
	vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
	for(int i=1; i<=n; i++){
		for(int j=1;j<=x;j++){
			if(prices[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(dp[i-1][j], pages[i-1]+dp[i-1][j-prices[i-1]]);
			}
		}
	}
	cout<<dp[n][x]<<endl;
	return 0;
}
