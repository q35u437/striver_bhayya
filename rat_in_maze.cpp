vector<string> paths;
void getTotalWays(int crow, int ccolumn, vector<vector<int>> &grid, int size, set<pair<int, int>> s, string path) {
    if(crow <= -1 or ccolumn <= -1 or crow >= size or ccolumn >= size) {
        return;
    }else if(grid[crow][ccolumn] == 0) {
        return;
    }else if(crow == size-1 and ccolumn == size-1) {
        paths.push_back(path);
    }else {
        s.insert({crow, ccolumn});
        if(s.find({crow-1, ccolumn}) == s.end()) {
            getTotalWays(crow-1, ccolumn, grid, size, s, path + "U");
        }
        if(s.find({crow, ccolumn+1}) == s.end()) {
            getTotalWays(crow, ccolumn+1, grid, size, s, path + "R");
        }
        if(s.find({crow+1, ccolumn}) == s.end()) {
            getTotalWays(crow+1, ccolumn, grid, size, s, path + "D");
        }
        if(s.find({crow, ccolumn-1}) == s.end()) {
            getTotalWays(crow, ccolumn-1, grid, size, s, path + "L");
        }
    }
}
