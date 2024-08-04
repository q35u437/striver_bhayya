void getAnswer(vector<int> adj[], vector<int> &answer, vector<int> &visited, int node){
    visited[node] = 1;
    answer.push_back(node);
    for(int neighbour : adj[node]){
        if(!visited[neighbour]){
            getAnswer(adj, answer, visited, neighbour);
        }
    }
}

