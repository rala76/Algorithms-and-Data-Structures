#include <iostream>
#include <vector>

using std::vector;

// My implementation
void bubbleSortV1(vector<int>& arr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// W3 Schools implementation
void bubbleSortV2(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Michael Sambol implementation
void bubbleSortV3(vector<int>& arr, int n) {
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    vector<int> arr = {2, 8, 5, 3, 8, 4, 1};
    int n = arr.size();

    // bubbleSortV1(arr, n);
    bubbleSortV2(arr, n);
    // bubbleSortV3(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}