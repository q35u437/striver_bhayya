class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> ways(n, 0);
        vector<long long> distances(n, LLONG_MAX);
        vector<pair<int, int>> adj[n];
        long long int MOD = 1e9 + 7;
        for(auto it : roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        distances[0] = 0;
        ways[0] = 1;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        while(!pq.empty()){
            auto [distance, node] = pq.top();
            pq.pop();
            for(auto [neighbour, weight] : adj[node]){
                if(distances[neighbour] > distance + weight){
                    distances[neighbour] = distance + weight;
                    ways[neighbour] = (ways[node]) % MOD;
                    pq.push({distances[neighbour], neighbour});
                }else if(distances[neighbour] == distance + weight){
                    ways[neighbour] = (ways[neighbour] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};
