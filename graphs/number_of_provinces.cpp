class Solution {
public:
    void doDFS(vector<vector<int>> &isConnected, int node, vector<int> &visited){
        visited[node] = 1;
        for(int start = 1; start <= isConnected[node-1].size(); start++){
            if(isConnected[node-1][start-1]){
                if(!visited[start]){
                    doDFS(isConnected, start, visited);
                }
            }
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int nodes = isConnected.size();
        vector<int> visited(nodes+1, 0);
        int count = 0;

        for(int i = 1; i <= nodes; i++){
            if(!visited[i]){
                doDFS(isConnected, i, visited);
                count++;
            }
        }
        return count;
    }
};
