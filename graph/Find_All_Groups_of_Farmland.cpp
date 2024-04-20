void doDFS(vector<vector<int>> &grid, vector<vector<int>> &visited, int sr, int sc, vector<int> &cordinates){
    stack<pair<int, int>> s;
    visited[sr][sc] = 1;
    s.push({sr, sc});
    int fr = sr, fc = sc;
    int n = grid.size();
    int m = grid[0].size();
    while(!s.empty()){
        int row = s.top().first;
        int column = s.top().second;
        s.pop();
        if(row - 1 >= 0){
            if(not visited[row-1][column] and grid[row-1][column]){
                s.push({row-1, column});
                visited[row-1][column] = 1;
                if(fr < row-1){
                    fr = row-1;
                    fc = column;
                }else if(fr == row-1){
                    fc = max(fc, column);
                }
            }
        }

        if(column -  1 >= 0){
            if(not visited[row][column-1] and grid[row][column-1]){
                s.push({row, column-1});
                visited[row][column-1] = 1;
                if(fr < row){
                    fr = row;
                    fc = column-1;
                }else if(fr == row){
                    fc = max(fc, column-1);
                }
            }
        }

        if(column + 1 < m ){
            if(not visited[row][column+1] and grid[row][column+1]){
                s.push({row, column+1});
                visited[row][column+1] = 1;
                if(fr < row){
                    fr = row;
                    fc = column+1;
                }else if(fr == row){
                    fc = max(fc, column+1);
                }
            }
        }

        if(row + 1 < n){
            if(not visited[row+1][column] and grid[row+1][column]){
                s.push({row+1, column});
                visited[row+1][column] = 1;
                if(fr < row+1){
                    fr = row+1;
                    fc = column;
                }else if(fr == row+1){
                    fc = max(fc, column);
                }
            }
        }
    }
    cordinates.push_back(fr);
    cordinates.push_back(fc);
}
vector<vector<int>> findFarmland(vector<vector<int>>& grid) {
    vector<vector<int>> answer;
    vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[0].size(); j++){
            if(grid[i][j] and not visited[i][j]){
                vector<int> cordinates;
                cordinates.push_back(i);
                cordinates.push_back(j);
                doDFS(grid, visited, i, j, cordinates);
                answer.push_back(cordinates);
            }
        }
    }
    return answer;
}
