//ps : please don't stalk the code i've written :(


#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		//an edge between the songs exists iff either they belong to the same genre or writer
		//first take inputs
		map<int, pair<string, string>> mymap;
		for(int i=0;i<n;i++){
			string g, w;
			cin>>g>>w;
			mymap[i] = {g, w};
		}
		//now form a graph between songs by adding an edge if they either have same genre or writer
		vector<vector<int>> graph(n,vector<int>(n, 0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)
					continue;
				if(mymap[i].second == mymap[j].second or mymap[i].first == mymap[j].first){
					graph[i][j] = 1;
					graph[j][i] = 1;
				}
			}
		}
		//checking every possible subset of songs
		vector<vector<bool>> dp(n, vector<bool>(1<<n, false));
		//every vertext itself if contained in a graph has hamiltonian path always
		for(int i=0;i<n;i++)
			dp[i][1<<i] = true;
		for(int j=0;j<(1<<n);j++){
		    for(int i=0;i<n;i++){
				if(j & (1<<i)){
					for(int k=0;k<n;k++){
						if(j & (1<<k) and graph[i][k] and  dp[k][j ^ (1<<i)]){
							dp[i][j] = true;
							break;
						}
					}
				}
			}
		}
		int answer = 1;
		for(int i=0;i<n;i++){
			for(int j=0;j<(1<<n);j++){
				if(dp[i][j])
					answer = max(answer,__builtin_popcount(j));
			}
		}
		cout<<(n-answer)<<endl;
	}
	return 0;
}
