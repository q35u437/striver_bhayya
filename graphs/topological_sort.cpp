class Solution
{
	public:
	
	void dfs(vector<int> adj[], int node, vector<int> &visited, vector<int> &answer){
	    visited[node] = 1;
	    
	    for(int neighbour : adj[node]){
	        if(!visited[neighbour]){
	            dfs(adj, neighbour, visited, answer);
	        }
	    }
	    answer.push_back(node);
	}
	
	
	
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> visited(V, 0), answer;
	    
	    for(int node = 0; node < V; node++){
	        if(!visited[node]){
	            dfs(adj, node, visited, answer);
	        }
	    }
	    
	    reverse(answer.begin(), answer.end());
	    
	    return answer;
	}
};
