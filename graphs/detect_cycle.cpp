class Solution {
  public:
    bool doBFS(int node, vector<int> adj[], vector<int> &visited){
        queue<pair<int, int>> q;

        visited[node] = 1;
        q.push({node, -1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
                
            q.pop();
            
            for(int neighbour : adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push({neighbour, node});
                }else if(neighbour != parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        
        for(int node = 0; node < V; node++){
            if(!visited[node]){
                bool ans = doBFS(node, adj, visited);
                if(ans){
                    return true;
                }
            }
        }
        return false;
    }
};
