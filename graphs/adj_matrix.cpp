#include<bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    vector<vector<int>> graph(nodes, vector<int>(nodes, 0));

    for(int edge=0;edge < edges; edge++) {
        int u, v;
        cin >> u >> v;
        graph[u-1][v-1] = 1;
        graph[v-1][u-1] = 1;
    }
    return 0;
}
