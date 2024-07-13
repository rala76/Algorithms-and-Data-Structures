#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using std::vector;
using std::queue;
using std::pair;
using std::min;

int bfs(vector<vector<int>>& grid) {
    int ROWS = grid.size(), COLS = grid[0].size();

    // In C++ it's easier to use a 2D array than a hashset
    vector<vector<int>> visit(ROWS, vector<int>(COLS, 0));
    queue<pair<int, int>> queue;
    queue.push(pair<int, int>(0, 0));
    visit[0][0] = 1;

    int length = 0;
    while (!queue.empty()) {
        // Get the number of elements in the current level
        int queueLength = queue.size();

        // Iterate over elements in the current level
        for (int i = 0; i < queueLength; i++) {
            pair<int, int> curPair = queue.front();
            queue.pop();

            int r = curPair.first, c = curPair.second;
            if (r == ROWS - 1 && c == COLS - 1) {
                return length;
            }

            // We can directly build the four neighbors - down, up, right, left
            int neighbors[4][2] = {{r + 1, c}, {r - 1, c}, {r, c + 1}, {r, c - 1}};
            for (int j = 0; j < 4; j++) {
                int newR = neighbors[j][0], newC = neighbors[j][1];

                if (min(newR, newC) < 0 || newR == ROWS || newC == COLS || visit[newR][newC] || grid[newR][newC]) {
                    continue;
                }

                queue.push(pair<int, int>(newR, newC));
                visit[newR][newC] = 1;
            }
        }

        // Increment length after each level is fully processed
        length++;
    }

    // No path from top left to bottom right
    return -1;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 0}
    };

    // Find the length of the shortest paths from the top left to the bottom right
    int length = bfs(grid);
    printf("Length of shortest path: %d\n", length);

    return 0;
}