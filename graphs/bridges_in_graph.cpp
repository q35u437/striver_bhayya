class Solution {
private:
int timer = 0;
public:
    void dfs(int node, int parent, vector<int> &visited, vector<int> adj[], vector<int> &time, vector<int> &low, vector<vector<int>> &bridges){
        visited[node] = 1;
        time[node] = low[node] =  timer;
        timer++;

        for(int neighbour : adj[node]){
            if(neighbour == parent) continue;
            if(!visited[neighbour]){
                dfs(neighbour, node, visited, adj, time, low, bridges);
                low[node] = min(low[node], low[neighbour]);
                if(time[node] < low[neighbour]){
                    bridges.push_back({node, neighbour});
                }
            }else{
                low[node] = min(low[node], low[neighbour]);
            }

        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> bridges;
        vector<int> visited(n, 0);
        vector<int> tim(n, 0);
        vector<int> low(n, 0);
        vector<int> adj[n];
        for(int connection = 0; connection < connections.size(); connection++){
            adj[connections[connection][0]].push_back(connections[connection][1]);
            adj[connections[connection][1]].push_back(connections[connection][0]);
        }
        dfs(0, -1, visited, adj, tim, low, bridges);
        return bridges;
    }
};
