#include <iostream>
#include <vector>

using std::vector;

vector<int> insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int j = i-1;

        while (j >= 0 && arr[j+1] < arr[j]) {
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    return arr;
}

int main() {
    vector<int> arr = {5, 3, 1, 2, 4};

    vector<int> res = insertionSort(arr); 

    for (int i = 0; i < res.size(); i++) {
        printf("%d, ", res[i]);
    }
    printf("\n");

    return 0;
}