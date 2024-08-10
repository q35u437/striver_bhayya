class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(vector<int> adj[], int node, vector<int> &visited, vector<int> &path_visited){
        visited[node] = 1;
        path_visited[node] = 1;
        bool ans = false;
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                ans |= dfs(adj, neighbour, visited, path_visited);
            }else if(path_visited[neighbour]){
                return true;
            }
        }
        path_visited[node] = 0;
        return ans;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), path_visited(V, 0);
        
        for(int node = 0; node < V; node++){
            if(!visited[node]){
                if(dfs(adj, node, visited, path_visited)) return true;
            }
        }
        return false;
    }
};
