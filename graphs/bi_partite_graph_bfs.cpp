class Solution {
public:
    bool bfs(vector<vector<int>> &graph, vector<int> &colors, int node){
        queue<int> q;
        q.push(node);
        colors[node] = 0;

        while(!q.empty()){
            int nude = q.front();
            int given_color = colors[nude];
            q.pop();
            for(int neighbour : graph[nude]){
                if(colors[neighbour] == -1){
                    q.push(neighbour);
                    colors[neighbour] = !given_color;
                }else{
                    if(given_color == colors[neighbour]){
                        return false;
                    }
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        // 0 -> red
        // 1 -> blue
        int nodes = graph.size();
        vector<int>  colors(nodes, -1);
        for(int node = 0; node < nodes; node++){
            if(colors[node] == -1){
                if(!bfs(graph, colors, node)) return false;
            }
        }
        return true;
    }
};
