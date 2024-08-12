class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
        vector<int> degrees(K, 0);
        vector<vector<int>> adj(K);
        
        for(int i=0;i<K;i++){
            adj[i] = {};
        }
        
        for(int index = 0; index < N-1; index++){
            int start = 0;
            while(start < min(dict[index].size(), dict[index+1].size())){
                if(dict[index][start] != dict[index+1][start]){
                    adj[dict[index][start]-'a'].push_back((dict[index+1][start]-'a'));
                    degrees[dict[index+1][start]-'a']++;
                    break;
                }
                start++;
            }
        }
        
        string answer;
        
        queue<int> q;
        
        for(int index = 0; index < K; index++){
            if(degrees[index]==0){
                q.push(index);
            }
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            answer += (char)('a'+node);
            
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
