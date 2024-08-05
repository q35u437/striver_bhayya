//there is some issue in the question that is given in gfg
class Solution {
  public:
  
    void doTraversal(int rbase, int cbase, int rsize, int colsize, set<string> &s, vector<vector<int>> &visited, vector<vector<int>> &grid){
        queue<pair<int, int>> q;
        
        q.push({rbase, cbase});
        vector<pair<int, int>> sele;
        sele.push_back({rbase, cbase});
        visited[rbase][cbase] = 1;
        
        while(!q.empty()){
            int row = q.front().first;
            int column = q.front().second;
            
            q.pop();
            
            if(row - 1 >= 0){
                if(!visited[row-1][column] and grid[row-1][column]){
                    q.push({row-1, column});
                    visited[row-1][column] = 1;
                    sele.push_back({row-1,column});
                }
            }
            
            if(row + 1 < rsize){
                if(!visited[row+1][column] and grid[row+1][column]){
                    q.push({row+1, column});
                    visited[row+1][column] = 1;
                    sele.push_back({row+1, column});
                }
            }
            
            if(column-1 >= 0){
                if(!visited[row][column-1] and grid[row][column-1]){
                    q.push({row, column-1});
                    visited[row][column-1] = 1;
                    sele.push_back({row, column-1});
                }
            }
      
            if(column+1 < colsize){
                if(!visited[row][column+1] and grid[row][column+1]){
                    q.push({row, column+1});
                    visited[row][column+1] = 1;
                    sele.push_back({row, column+1});
                }
            }
        }
        
        
        string ans = "";
        
        for(auto it : sele){
            it.first = it.first - rbase;
            it.second = it.second - cbase;
            ans += to_string(it.first) + to_string(it.second);
        }
        s.insert(ans);
    }
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        int rsize = grid.size();
        int colsize = grid[0].size();
        vector<vector<int>> visited(rsize, vector<int>(colsize, 0));
        set<string>s;
        
        for(int row = 0; row < rsize; row++){
            for(int column = 0; column < colsize; column++){
                if(grid[row][column] == 1){
                    if(!visited[row][column]){
                        doTraversal(row, column, rsize, colsize, s, visited, grid);
                    }
                }
            }
        }
        return s.size();
    }
};
