vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    stack<int> st;
    vector<int> answer;
    vector<int> visited(V, 0);

    st.push(0);
    
    
    while(!st.empty()){
        int node = st.top();
        st.pop();
        if(!visited[node]){
            visited[node] = 1;
            answer.push_back(node);
            for(int index = adj[node].size()-1; index >=0; index--){
                if(!visited[adj[node][index]]){
                    st.push(adj[node][index]);
                }
            }
        }
    }
    return answer;
}
