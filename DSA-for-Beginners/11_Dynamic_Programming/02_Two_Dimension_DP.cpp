#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

// Brute Force - Time: O(2 ^ (n + m)), Space: O(n + m)
int bruteForce(int r, int c, int rows, int cols) {
    if (r == rows || c == cols) {
        return 0;
    }
    if (r == rows - 1 || c == cols - 1) {
        return 1;
    }

    return bruteForce(r + 1, c, rows, cols) + bruteForce(r, c + 1, rows, cols);
}

// Memoization - Time and Space: O(n * m)
int memoization(int r, int c, int rows, int cols, vector<vector<int>>& cache) {
    if (r == rows || c == cols) {
        return 0;
    }
    if (cache[r][c] > 0) {
        return cache[r][c];
    }
    if (r == rows - 1 || c == cols - 1) {
        return 1;
    }

    cache[r][c] = memoization(r + 1, c, rows, cols, cache) + memoization(r, c + 1, rows, cols, cache);
    return cache[r][c];
}

// Dynamic Programming - Time: O(n * m), Space: O(m), where m is num of cols
int dp(int rows, int cols) {
    vector<int> prevRow(cols, 0);

    for (int r = rows - 1; r >= 0; r--) {
        vector<int> currRow(cols, 0);
        currRow[cols - 1] = 1;

        for (int c = cols - 2; c >= 0; c--) {
            currRow[c] = currRow[c + 1] + prevRow[c];
        }

        prevRow = currRow;
    }

    return prevRow[0];
}

int main() {
    int rows = 4;
    int cols = 4;

    int r = 0;
    int c = 0;

    // Brute Force
    int res1 = bruteForce(r, c, rows, cols);
    cout << "Number of Unique Paths (Brute Force): " << res1 << endl;

    // Memoization
    vector<vector<int>> cache(rows, vector<int>(cols, 0));
    int res2 = memoization(r, c, rows, cols, cache);
    cout << "Number of Unique Paths (Memoization): " << res2 << endl;

    // Dynamic Programming
    int res3 = dp(rows, cols);
    cout << "Number of Unique Paths (DP): " << res3 << endl;

    return 0;
}