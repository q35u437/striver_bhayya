class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<int> &colors, int node, int current_color){
        colors[node] = current_color;
        bool ans = true;
        for(int neighbour : graph[node]){
            if(colors[neighbour] == -1){
                ans &= dfs(graph, colors, neighbour, !current_color);
            }else{
                if((colors[neighbour] == current_color)) return false;
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> colors(nodes, -1);
        for(int node = 0; node < nodes; node++){
            if(colors[node] == -1){
                if(!dfs(graph, colors, node, 0)) return false;
            }
        }
        return true;
    }
};
