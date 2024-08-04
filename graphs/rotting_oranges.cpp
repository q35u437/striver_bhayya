class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rsize = grid.size(), csize = grid[0].size();
        int ttime = 0;
        
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(rsize, vector<int>(csize, 0));


        for(int row = 0; row < rsize; row++){
            for(int column = 0; column < csize; column++){
                if(grid[row][column] == 2){
                    q.push({{row, column}, 0});
                    visited[row][column] = 2;
                }
            }
        }

        while(!q.empty()){
            int crow = q.front().first.first;
            int ccol = q.front().first.second;
            int timee = q.front().second;
            q.pop();

            if(crow - 1 >= 0){
                if(grid[crow-1][ccol] == 1 and !visited[crow-1][ccol]){
                    q.push({{crow-1, ccol}, timee+1});
                    visited[crow-1][ccol] = 2;
                }
            }

            if(crow + 1 <= rsize-1){
                if(grid[crow+1][ccol] == 1 and !visited[crow+1][ccol]){
                    q.push({{crow+1, ccol}, timee+1});
                    visited[crow+1][ccol] = 2;
                }
            }

            if(ccol-1 >= 0){
                if(grid[crow][ccol-1] == 1 and !visited[crow][ccol-1]){
                    q.push({{crow, ccol-1}, timee+1});
                    visited[crow][ccol-1] = 2;
                }
            }

            if(ccol+1 <= csize-1){
                if(grid[crow][ccol+1] == 1 and !visited[crow][ccol+1]){
                    q.push({{crow, ccol+1}, timee+1});
                    visited[crow][ccol+1] = 2;
                }
            }

            ttime = max(ttime, timee);
        }

        for(int i=0; i < rsize; i++){
            for(int j=0; j < csize; j++){
            if(grid[i][j] == 1 and visited[i][j] != 2){
                return -1;
            }
            }
        }
        return ttime;
    }
};
