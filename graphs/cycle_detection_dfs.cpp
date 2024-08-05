class Solution {
  public:
  
    bool doDFS(int node, vector<int> &visited, vector<int> adj[], int parent){
        visited[node] = 1;
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                bool ans = doDFS(neighbour, visited, adj, node);
                if(ans) return ans;
            }else if(neighbour != parent){
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        
        for(int node = 0; node < V; node++){
            if(!visited[node]){
                bool ans = doDFS(node, visited, adj, -1);
                if(ans) return true;
            }
        }
        return false;
    }
};
