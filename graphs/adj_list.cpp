#include<bits/stdc++.h>
using namespace std;

/*
 * adjacency list - O(2*E) memory space where E is number of edges
 * why this is because here we are only considering the total degree of the graph
 *
 * adjacency matrix - O(N*N) memory space where N is number of nodes
 * here we are considering all the possible pairs of nodes
 *
 */

int main() {
    int nodes, edges;

    cin >> nodes >> edges;

    vector<int> adj[nodes];

    for(int edge = 0; edge < edges ;edge++) {
        int u, v;
        cin >> u >> v;

        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1); // can be ignored if the graph is directed
    }
}
