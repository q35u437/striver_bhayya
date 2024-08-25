class disJointSubset{
    private:
    vector<int> rank;
    vector<int> parent;
    
    public:
    disJointSubset(int size){
        rank.resize(size, 0);
        parent.resize(size);
        for(int node = 0; node < size; node++){
            parent[node] = node;
        }
    }
    
    int findParent(int node){
        if(parent[node] == node) return node;
        return (parent[node] = findParent(parent[node]));
    }
    
    bool UnionByRank(int node1, int node2){
        int node1_p = findParent(node1);
        int node2_p = findParent(node2);
        
        
        if(node1_p == node2_p) return false;
        
        if(rank[node1_p] > rank[node2_p]){
            parent[node2_p] = node1_p;
        }else if(rank[node1_p] < rank[node2_p]){
            parent[node1_p] = node2_p;
        }else{
            parent[node1_p] = node2_p;
            rank[node2_p]+=1;
        }
        return true;
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<vector<int>> edges;
        for(int node = 0; node < V; node++){
            for(auto it : adj[node]){
                edges.push_back({it[1], node, it[0]});
            }
        }
        
        sort(edges.begin(), edges.end());
        int edge = 0;
        int index = 0;
        int answer = 0;
        disJointSubset ds = disJointSubset(V);
        while(edge < V-1){
            int weight = edges[index][0];
            int u = edges[index][1];
            int v = edges[index][2];
            if(ds.UnionByRank(u, v)){
                answer += weight;
                edge+=1;
            }
            index += 1;
        }
        return answer;
    }   
};
