#include <iostream>
#include <vector>
#include <algorithm>    // std::max_element()

using std::vector;

void bucketSort(vector<int>& arr) {
    // Assuming arr only contains 0, 1, or 2
    // int max_val = 2;
    // int counts[] = {0, 0, 0};

    // Create empty buckets
    int max_val = *std::max_element(arr.begin(), arr.end());
    vector<int> counts(max_val + 1, 0);

    // Count the frequency of each val in arr
    for (int n: arr) {
        counts[n]++;
    }

    // Create the sorted arr only using counts
    int i = 0;
    for (int n = 0; n < max_val + 1; n++) {
        for (int j = 0; j < counts[n]; j++) {
            arr[i] = n;
            i++;
        }
    }
}

int main() {
    // vector<int> arr = {2, 1, 2, 0, 0, 2};
    vector<int> arr = {2, 1, 5, 0, 0, 2};

    bucketSort(arr);

    for (int n: arr) {
        printf("%d, ", n);
    }
    printf("\n");

    return 0;
}