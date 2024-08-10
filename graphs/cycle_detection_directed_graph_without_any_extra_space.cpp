class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool dfs(vector<int> adj[], int node, vector<int> &visited){
        visited[node]++;
        visited[node]++;
        bool ans = false;
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                ans |= dfs(adj, neighbour, visited);
            }else if(visited[neighbour] == 2){
                return true;
            }
        }
        visited[node]--;
        return ans;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        
        for(int node = 0; node < V; node++){
            if(!visited[node]){
                if(dfs(adj, node, visited)) return true;
            }
        }
        return false;
    }
};
