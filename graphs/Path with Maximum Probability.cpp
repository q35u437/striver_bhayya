class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);

        for(int i=0;i<n;i++) adj[i] = {};
    
        for(int index=0;index<edges.size();index++){
            int u = edges[index][0];
            int v = edges[index][1];
            double w = succProb[index];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<double> distances(n, 1e9);
        distances[start_node] = 1.0;
        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({-1.0, start_node});
        while(!pq.empty()){
            auto [distance, node] = pq.top();
            pq.pop();
            if(node == end_node) return -distance;
            for(auto [neighbour, weight] : adj[node]){
                if(distances[neighbour] > distance * weight){
                    distances[neighbour] = distance * weight;
                    pq.push({distances[neighbour], neighbour});
                }
            }
        }
        return 0.0;
    }
};
