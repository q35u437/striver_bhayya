struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};


class Solution {
public:
    void dfs(int x, int y, queue<pair<int, int>> &q, unordered_set<pair<int, int>, pair_hash> &seen, vector<vector<int>> &distances, vector<vector<int>> &grid){
        if(x > 0 and seen.find({x-1, y}) == seen.end()){
            seen.insert({x-1, y});
            if(grid[x-1][y]){
                distances[x-1][y] = distances[x][y]+1;
                q.push({x-1, y});
            }else{
                distances[x-1][y] = distances[x][y];
                dfs(x-1, y, q, seen, distances, grid);
            }
        }


        if(x < grid.size()-1 and seen.find({x+1, y}) == seen.end()){
            seen.insert({x+1, y});
            if(grid[x+1][y]){
                distances[x+1][y] = distances[x][y]+1;
                q.push({x+1, y});
            }else{
                distances[x+1][y] = distances[x][y];
                dfs(x+1, y, q, seen, distances, grid);
            }
        }


        if(y > 0 and seen.find({x, y-1}) == seen.end()){
            seen.insert({x, y-1});
            if(grid[x][y-1]){
                distances[x][y-1] = distances[x][y]+1;
                q.push({x, y-1});
            }else{
                distances[x][y-1] = distances[x][y];
                dfs(x, y-1, q, seen, distances, grid);
            }
        }

        if(y < grid[0].size()-1 and seen.find({x, y+1}) == seen.end()){
            seen.insert({x, y+1});
            if(grid[x][y+1]){
                distances[x][y+1] = distances[x][y]+1;
                q.push({x, y+1});
            }else{
                distances[x][y+1] = distances[x][y];
                dfs(x, y+1, q, seen, distances, grid);
            }
        }
    }

    
    int minimumObstacles(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({0, 0});
        unordered_set<pair<int, int>, pair_hash> seen;
        vector<vector<int>> distances(grid.size(), vector<int>(grid[0].size(), 0));
        seen.insert({0, 0});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            dfs(x, y, q, seen, distances, grid);
        }
        return distances[grid.size()-1][grid[0].size()-1];
    }
};
