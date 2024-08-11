class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> degrees(V, 0);
        for(int node = 0; node < V; node++){
            for(int i : adj[node]){
                degrees[i]++;
            }
        }
        
        queue<int> q;
        vector<int> answer;
        
        for(int node = 0; node < V; node++){
            if(degrees[node] == 0)
                q.push(node);
        }
        
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
            answer.push_back(node);
            
            for(int neighbour : adj[node]){
                degrees[neighbour]--;
                if(degrees[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        return answer.size() != V;
    }
};
