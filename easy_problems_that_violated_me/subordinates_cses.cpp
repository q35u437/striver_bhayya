#include<bits/stdc++.h>
using namespace std;

int getAnswer(vector<vector<int>> &array, vector<int> &answer, int currentnode){
	if(array[currentnode].size() == 0){
		return 1;
	}else{
		int total = 0;
		for(int neighbour : array[currentnode]){
			total += getAnswer(array,answer,neighbour);
		}
		answer[currentnode] = total;
		return answer[currentnode]+1;
	}
}

int main(){
	int n;
	cin>>n;
	vector<vector<int>> array(n+1);
	for(int i=1;i<=n;i++){
		array[i] = {};
	}
	for(int i=2;i<=n;i++){
		int value;
		cin>>value;
		array[value].push_back(i);
	}
	vector<int> answer(n+1, 0);
	getAnswer(array, answer, 1);
	for(int i=1;i<=n;i++)
		cout<<answer[i]<<" ";
	return 0;
}
