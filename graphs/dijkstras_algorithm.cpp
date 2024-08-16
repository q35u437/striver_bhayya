class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distances(V, 1e9);
        distances[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int a = it[0];
                int b = it[1];
                if(distances[a] > distance + b){
                    distances[a] = distance + b;
                    pq.push({distances[a],a});
                }
            }
        }
        return distances;
    }
};
