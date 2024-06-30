#include <iostream>
#include <vector>

using std::vector;

int binarySearch(vector<int> arr, int n, int target) {
    int L = 0;
    int R = n;

    while (L <= R) {
        int mid = (L + R) / 2;

        if (target > arr[mid]) {
            L = mid + 1;
        } else if (target < arr[mid]) {
            R = mid - 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {1, 3, 3, 4, 5, 6, 7, 8};
    int n = arr.size();
    int target = 7;

    int res = binarySearch(arr, n, target);

    if (res == -1) {
        printf("Target value %d not found", target);
    } else {
        printf("Target value %d found at index %d", target, res);
    }

    return 0;
}