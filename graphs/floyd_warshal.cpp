//User function template for C++

class Solution {
  public:
	vector<vector<int>>&matrix shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    for(int u = 0; u < n; u++){
	        for(int v = 0; v < n; v++){
	            if(u == v){
	                matrix[u][v] = 0;
	            }else if(matrix[u][v] == -1){
	                matrix[u][v] = 1e9;
	            }
	        }
	    }
	    for(int via = 0; via < n; via++){
	        for(int v = 0; v < n; v++){
	            for(int u = 0; u < n; u++){
	                if(u == v or u == via or v == via)
	                    continue;
	                matrix[u][v] = min(matrix[u][v], matrix[u][via] + matrix[via][v]);
	            }
	        }
	    }
	    
	    for(int u = 0; u < n; u++){
	        for(int v = 0; v < n; v++){
	            if(matrix[u][v] == 1e9)
	                matrix[u][v] = -1;
	        }
	    }
    return matrix;
	}
};
