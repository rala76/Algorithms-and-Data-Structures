# Brute Force
def bruteForce(n):
    if n <= 1:
        return n
    return bruteForce(n - 1) + bruteForce(n - 2)

# Memoization (Top-down)
def memoization(n, cache):
    if n <= 1:
        return n
    if n in cache:
        return cache[n]

    cache[n] = memoization(n - 1, cache) + memoization(n - 2, cache)
    return cache[n]

# Dynamic Programming (Bottom-up)
def dp(n):
    if n <= 1:
        return n
    
    dp = [0, 1]
    i = 2
    while i <= n:
        tmp = dp[1]
        dp[1] = dp[0] + dp[1]
        dp[0] = tmp
        i += 1
    
    return dp[1]

def main():
    n = 5
    cache = {} # HashMap

    # Brute Force
    res1 = bruteForce(n)
    print(res1)

    # Memoization
    res2 = memoization(n, cache)
    print(res2)

    # Dynamic Programming
    res3 = dp(n)
    print(res3)

if __name__ == "__main__":
    main()