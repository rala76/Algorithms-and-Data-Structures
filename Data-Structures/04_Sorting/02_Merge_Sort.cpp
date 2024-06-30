#include <iostream>
#include <vector>

using std::vector;

void merge(vector<int>& arr, int left, int mid, int right) {
    // Copy the sorted left and right halfs to temp arrays
    vector<int> L = {arr.begin() + left, arr.begin() + mid + 1};
    vector<int> R = {arr.begin() + mid + 1, arr.begin() + right + 1};
    
    int i = 0; // index for L
    int j = 0; // index for R
    int k = left; // index for arr
    
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // One of the halfs will have elements remaining
    while (i < L.size()) {
        arr[k++] = L[i++];
    }
    while (j < R.size()) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    // The middle of the array
    int mid = (left + right) / 2; // 'left + (right - left) / 2' fixes overflow

    // Sort the left half
    mergeSort(arr, left, mid);

    // Sort the right half
    mergeSort(arr, mid + 1, right);
    
    // Merge sorted halfs
    merge(arr, left, mid, right);
}

int main() {
    vector<int> arr = {3, 2, 4, 1, 6};
    int left = 0;
    int right = arr.size() - 1;

    mergeSort(arr, left, right);

    for (int i = 0; i < arr.size(); i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}