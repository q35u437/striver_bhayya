vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    vector<int> answer;
    queue<int> q;
    
    q.push(0);
    visited[0] = 1;

    
    while(!q.empty()){
        int node = q.front();
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
            }
        }
        q.pop();
        answer.push_back(node);
    }
    return answer;
}
