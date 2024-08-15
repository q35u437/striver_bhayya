#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
    visited[node] = 1;
    for(int neighbour : adj[node]) {
        if(!visited[neighbour])
            dfs(neighbour, adj, visited);
    }
}



int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> adj(n);

    for(int city = 0; city < n; city++) adj[city] = {};

    for(int road = 0; road < m; road++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    vector<int> visited(n, 0);

    int counter = 0;
    vector<pair<int, int>> answer;
    for(int city = 0; city < n; city++) {
        if(!visited[city]) {
            answer.push_back({1, city+1});
            dfs(city, adj, visited);
            counter++;
        }
    }

    cout << counter-1 << endl;
    for(int start = 1; start < counter; start++) {
        cout<<answer[start].first<<" "<<answer[start].second<<endl;
    }
    return 0;
}
