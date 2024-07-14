#include <iostream>
#include <vector>

using std::vector;

// Adjacency list
class GraphNode {
public:
    int val;
    vector<int> neighbors;

    GraphNode(int val) {
        this->val = val;
    }
};

int main() {
    // Matrix (2D Grid)
    int grid[4][4] =  {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 0}
    };

    // Adjacency matrix
    int adjMatrix[4][4] = {
        {0, 0, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 0, 0}
    };

    return 0;
}