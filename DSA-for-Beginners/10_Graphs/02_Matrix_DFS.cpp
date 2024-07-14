#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::min;

// Count paths (backtracking)
// In C++, it's easier to use a 2D array for visit rather than a hashset
int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& visit) {
    int ROWS = grid.size();
    int COLS = grid[0].size();

    // Base Cases
    if (min(r, c) < 0 || r == ROWS || c == COLS || visit[r][c] || grid[r][c]) {
        return 0;
    }
    if (r == ROWS - 1 && c == COLS - 1) {
        return 1;
    }

    // Mark coordinate as visited
    visit[r][c] = 1;

    // DFS matrix while keeping track of unique paths count
    int count = 0;
    count += dfs(grid, r + 1, c, visit); // down
    count += dfs(grid, r - 1, c, visit); // up
    count += dfs(grid, r, c + 1, visit); // right
    count += dfs(grid, r, c - 1, visit); // left
    
    // Mark coordinate as unvisited (for backtracking)
    visit[r][c] = 0;

    // Return unique paths count for this source coordinate
    return count;
    
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 0}
    };

    // Dimensions of grid
    int ROWS = grid.size();
    int COLS = grid[0].size();

    // 2D array of size 'ROWS x COLS' where each cell is initialized to '0'
    vector<vector<int>> visit(ROWS, vector<int>(COLS, 0));

    // Starting coordinate
    int r = 0;
    int c = 0;

    // Find the number of unique paths from the top left to the bottom right
    int count = dfs(grid, r, c, visit);
    printf("Unique paths count: %d\n", count);

    return 0;
}