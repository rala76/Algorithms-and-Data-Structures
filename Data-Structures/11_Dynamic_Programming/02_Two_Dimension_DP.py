# Brute Force - Time: O(2 ^ (n + m)), Space: O(n + m)
def bruteForce(r, c, rows, cols):
    if r == rows or c == cols:
        return 0
    if r == rows - 1 and c == cols - 1:
        return 1
    
    return bruteForce(r + 1, c, rows, cols) + bruteForce(r, c + 1, rows, cols)

# Memoization - Time and Space: O(n * m)
def memoization(r, c, rows, cols, cache):
    if r == rows or c == cols:
        return 0
    if cache[r][c] > 0:
        return cache[r][c]
    if r == rows - 1 and c == cols - 1:
        return 1
    
    cache[r][c] = memoization(r + 1, c, rows, cols, cache) + memoization(r, c + 1, rows, cols, cache)
    return cache[r][c]

# Dynamic Programming - Time: O(n * m), Space: O(m), where m is num of cols
def dp(rows, cols):
    prevRow = [0] * cols

    for r in range(rows - 1, -1, -1):
        curRow = [0] * cols
        curRow[cols - 1] = 1

        for c in range(cols - 2, -1, -1):
            curRow[c] = curRow[c + 1] + prevRow[c]
        
        prevRow = curRow
        
    return prevRow[0]

def main():
    rows, cols = 4, 4
    r, c = 0, 0
    cache = [[0] * 4 for i in range(4)]

    # Brute Force
    res1 = bruteForce(r, c, rows, cols)
    print(res1)

    # Memoization
    res2 = memoization(r, c, rows, cols, cache)
    print(res2)

    # Dynamic Programming
    res3 = dp(rows, cols)
    print(res3)

if __name__ == "__main__":
    main()