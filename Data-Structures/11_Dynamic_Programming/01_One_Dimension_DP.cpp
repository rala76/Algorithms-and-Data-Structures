#include <iostream>
#include <unordered_map>

using std::unordered_map;
using std::cout;
using std::endl;

// Brute Force
int bruteForce(int n) {
    if (n <= 1) {
        return n;
    }

    return bruteForce(n - 1) + bruteForce(n - 2);
}

// Memoization (Top-down)
int memoization(int n, unordered_map<int, int>& cache) {
    if (n <= 1) {
        return n;
    }
    if (cache.count(n)) {
        return cache[n];
    }
    
    cache[n] = memoization(n - 1, cache) + memoization(n - 2, cache);
    return cache[n];
}

// Dynamic Programming (Bottom-up)
int dp(int n) {
    if (n < 2) {
        return n;
    }

    int dp[] = {0, 1};
    int i = 2;
    while (i <= n) {
        int temp = dp[1];
        dp[1] = dp[0] + dp[1];
        dp[0] = temp;
        i++;
    }

    return dp[1];
}

int main() {
    int n = 5;

    // Brute Force
    int res1 = bruteForce(n);
    cout << "Brute Force: F(" << n << ") = " << res1 << endl;

    // Memoization (Top-down)
    unordered_map<int, int> cache;
    int res2 = memoization(n, cache);
    cout << "Memoization (Top-down): F(" << n << ") = " << res2 << endl;

    // Dynamic Programming (Bottom-up)
    int res3 = dp(n);
    cout << "Dynamic Programming (Bottom-up): F(" << n << ") = " << res3 << endl;

    return 0;
}