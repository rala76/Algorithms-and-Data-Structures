# Matrix (2D Grid)
grid = [[0, 0, 0, 0], 
        [1, 1, 0, 0],
        [0, 0, 0, 1],
        [0, 1, 0, 0]]

def dfs(grid, r, c, visit):
    ROWS, COLS = len(grid), len(grid[0])

    # Base cases
    if min(r, c) < 0 or r == ROWS or c == COLS or (r, c) in visit or grid[r][c] == 1:
        return 0
    if r == ROWS - 1 and c == COLS - 1:
        return 1
    
    # Mark coordinate as visited
    visit.add((r, c))

    # DFS matrix while keeping track of unique paths count
    count = 0
    count += dfs(grid, r + 1, c, visit) # down
    count += dfs(grid, r - 1, c, visit) # up
    count += dfs(grid, r, c + 1, visit) # right
    count += dfs(grid, r, c - 1, visit) # left

    # Mark coordinate as unvisited (for backtracking)
    visit.remove((r, c))

    # Return unique paths count for this source coordinate
    return count

def main():
    # Dimension of grid
    ROWS, COLS = len(grid), len(grid[0])

    # HashSet of visited positions
    visit = set()

    # Starting coordinate
    r, c = 0, 0

    count = dfs(grid, r, c, visit)
    print(count)

if __name__ == "__main__":
    main()