class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> degrees(V, 0);
	    for(int node = 0; node < V; node++){
	        for(int adjacent : adj[node]){
	            degrees[adjacent]++;
	        }
	    }
	    vector<int> answer;
	    queue<int> q;
	    for(int node = 0; node < V; node++){
	        if(degrees[node] == 0){
	            q.push(node);
	        }
	    }
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
          answer.push_back(node);
	        for(int neighbour : adj[node]){
	            degrees[neighbour]--;
	            
	            if(degrees[neighbour] == 0){
	                q.push(neighbour);
	            } 
	        }
	    }
	    return answer;
	}
};
