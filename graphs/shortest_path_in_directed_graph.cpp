// User function Template for C++
class Solution {
  public:
  
    void dfs(int node, vector<vector<pair<int, int>>> &adj, vector<int> &visited, vector<int> &topoSort){
        visited[node] = 1;
        
        for(auto neighbour : adj[node]){
            if(!visited[neighbour.first]){
                dfs(neighbour.first, adj, visited, topoSort);
            }
        }
        
        topoSort.push_back(node);
    }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         vector<int> topoSort;
         vector<int> visited(N, 0);
         vector<vector<pair<int, int>>> adj(N);
         
         for(int node = 0; node < N; node++){
             adj[node] = {};
        }
        
        for(int edge = 0; edge < M; edge++){
            int u = edges[edge][0];
            int v = edges[edge][1];
            int w = edges[edge][2];
            adj[u].push_back({v, w});
        }
        
        
        for(int node = 0; node < N; node++){
            if(!visited[node]){
                dfs(node, adj, visited, topoSort);
            }
        }
        
        reverse(topoSort.begin(), topoSort.end());
        
        vector<int> distances(N, 1e9);
        
        distances[0] = 0;
        
        for(int node : topoSort){
            for(auto neighbour : adj[node]){
                int v = neighbour.first;
                int w = neighbour.second;
                distances[v] = min(distances[v], distances[node] + w);
            }
        }
        
        for(int node = 0; node < N; node++){
            if(distances[node] == 1e9)
                distances[node] = -1;
        }
        
        return distances;
    }
};
