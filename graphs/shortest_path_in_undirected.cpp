// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> distances(N, 1e9);
        distances[src] = 0;
        queue<pair<int, int>> q;
        q.push({src, 0});
        vector<vector<int>> adj(N);
        for(int i = 0; i < N; i++) adj[i] = {};
        for(int edge = 0; edge < M; edge++){
            int u = edges[edge][0];
            int v = edges[edge][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        while(!q.empty()){
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();
            for(int neighbour : adj[node]){
                if(distances[neighbour] > distance + 1){
                    distances[neighbour] = distance+1;
                    q.push({neighbour, distances[neighbour]});
                }
            }
        }
        for(int i=0;i<N;i++){
            if(distances[i] == 1e9){
                distances[i] = -1;
            }
        }
        return distances;
    }
};
