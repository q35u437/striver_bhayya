#include<bits/stdc++.h>
using namespace std;



void dfs(vector<vector<char>> &grid, vector<vector<int>> &visited, int row, int col) {
    visited[row][col] = 1;

    if(row-1 >= 0) {
        if(grid[row-1][col] == '.' and !visited[row-1][col])
            dfs(grid, visited, row-1, col);
    }

    if(row+1 < grid.size()) {
        if(grid[row+1][col] == '.' and !visited[row+1][col])
            dfs(grid, visited, row+1, col);
    }

    if(col-1 >= 0) {
        if(grid[row][col-1] == '.' and !visited[row][col-1])
            dfs(grid, visited, row, col-1);
    }

    if(col+1 < grid[0].size()) {
        if(grid[row][col+1] == '.' and !visited[row][col+1])
            dfs(grid, visited, row, col+1);
    }
}

int main() {
    int n, m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m,' '));

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            char ch;
            cin>>ch;
            grid[row][col] = ch;
        }
    }


    vector<vector<int>> visited(n, vector<int>(m, 0));
    int counter = 0;

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            if(!visited[row][col] and grid[row][col] == '.') {
                dfs(grid, visited, row, col);
                counter++;
            }
        }
    }
    cout<<counter<<endl;
    return 0;
}
