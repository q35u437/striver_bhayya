class Solution
{
public:
//Function to find sum of weights of edges of the Minimum Spanning Tree.
//you can modify this code so that you can gget all the edges involved in the MST

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    int sum = 0;
    pq.push({0, 0, -1});
    vector<int> visited(V, 0);
    while(!pq.empty()){
        vector<int> info = pq.top();
        pq.pop();
        int weight = info[0];
        int node = info[1];
        int parent = info[2];
        
        if(!visited[node]){
            sum += weight;
            visited[node] = 1;
            for(auto it : adj[node]){
                int otherend = it[0];
                int weight = it[1];
                if(!visited[otherend])
                    pq.push({weight, otherend, node});
            }
        }
    }
    return sum;
}
};
