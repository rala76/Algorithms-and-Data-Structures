#include <iostream>
#include <vector>

using std::vector;

void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[right];
    int i = left; // pointer for the left side (top)

    // Partition: elements smaller than pivot on the left side
    for (int j = left; j < right; j++) { // pointer for the right side (bottom)
        if (arr[j] < pivot) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }

    // Move pivot in-between left and right sides
    arr[right] = arr[i];
    arr[i] = pivot;

    // Quick sort left and right sides using recursion
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}

int main() {
    vector<int> arr = {6, 2, 4, 1, 3};
    int left = 0;
    int right = arr.size() - 1;

    quickSort(arr, left, right);

    for (int i = 0; i < arr.size(); i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}