#include<bits/stdc++.h>
using namespace std;

int main() {
    int nodes, edges;
    cin >> nodes >> edges;

    int graph[nodes][nodes] = {};

    for(int edge=0;edge < edges; edge++) {
        int u, v;
        cin >> u >> v;
        graph[u-1][v-1] = 1;
        graph[v-1][u-1] = 1;
    }

    for(int i = 0; i<nodes; i++) {
        for(int j=0; j < nodes; j++) {
            cout << graph[i][j] << " ";
        }
        cout<<endl;
    }
    return 0;
}
