void dfs(int r, int c, vector<vector<int>>& visited,
         vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    visited[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    while (!q.empty()) {
        int row = q.front().first;
        int column = q.front().second;
        q.pop();
        if (row - 1 >= 0) {
            if (not visited[row - 1][column] and
                grid[row - 1][column] == '1') {
                visited[row - 1][column] = 1;
                q.push({row - 1, column});
            }
        }
        if (row + 1 < n) {
            if (not visited[row + 1][column] and
                grid[row + 1][column] == '1') {
                visited[row + 1][column] = 1;
                q.push({row + 1, column});
            }
        }
        if (column - 1 >= 0) {
            if (not visited[row][column - 1] and
                grid[row][column - 1] == '1') {
                visited[row][column - 1] = 1;
                q.push({row, column - 1});
            }
        }

        if (column + 1 < m) {
            if (not visited[row][column + 1] and
                grid[row][column + 1] == '1') {
                visited[row][column + 1] = 1;
                q.push({row, column + 1});
            }
        }
    }
}
int numIslands(vector<vector<char>>& grid) {
    int counter = 0;
    vector<vector<int>> visited(grid.size(),
                                vector<int>(grid[0].size(), 0));
    for (int row = 0; row < grid.size(); row++) {
        for (int column = 0; column < grid[0].size(); column++) {
            if (not visited[row][column] and grid[row][column] == '1') {
                dfs(row, column, visited, grid);
                counter++;
            }
        }
    }
    return counter;
}
