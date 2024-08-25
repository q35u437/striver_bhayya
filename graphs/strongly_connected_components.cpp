class Solution
{
    private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &st){
        visited[node] = 1;
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj, visited, st);
            }
        }
        st.push(node);
    }
    
    void dfz(int node, vector<int> &visited, vector<int> adj[]){
        visited[node] = 1;
        for(int neighbour : adj[node]){
            if(!visited[neighbour])
                dfz(neighbour, visited, adj);
        }
    }
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> visited(V, 0);
        stack<int> st;
        
        //sort by finishing time(the last finishing at top of stack)
        for(int node = 0; node < V; node++){
            if(!visited[node]){
                dfs(node, adj, visited, st);
            }
        }
        
        
        //reverse the whole graph
        vector<int> adjT[V];
        for(int node = 0; node < V; node++){
            for(int neighbour : adj[node]){
                adjT[neighbour].push_back(node);
            }
        }
        
        
        
        //call dfs for each connected component
        int scc = 0;
        visited.clear();
        visited.resize(V, 0);
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!visited[node]) {
                dfz(node, visited, adjT);
                scc++;
            }
        }
        return scc;
    }
};
