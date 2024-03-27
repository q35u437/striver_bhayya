#include<bits/stdc++.h>
using namespace std;


long long getPossibleWays(vector<long long> &coins, long long currentsum, vector<long long> &dp){
	if(currentsum == 0){
		dp[currentsum] = 1;
		return dp[currentsum];
	}else if(currentsum < 0){
		return 0;	
	}else if(dp[currentsum] != -1){
		return dp[currentsum];	
	}else{
		long long total = 0;
		for(long long coin : coins){
			total += (getPossibleWays(coins, currentsum-coin, dp)) % 1000000007;
		}
		dp[currentsum] = total;
		return dp[currentsum];
	}
}

int main(){
    	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long n,x;
	cin>>n>>x;
	vector<long long> coins;
	for(long long i = 0; i < n; i++){
		long long value;
		cin>>value;
		coins.push_back(value);
	}
	vector<long long> dp(x+1, -1);
	cout<<getPossibleWays(coins, x, dp) % 1000000007;
	return 0;
}
