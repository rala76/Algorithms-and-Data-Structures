#include <iostream>
#include <vector>

int isCorrect(int n) {
    int val = 10;
    
    if (n > val) {
        return 1;
    } else if (n < val) {
        return -1;
    } else {
        return 0;
    }
}

int binarySearch(int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;

        if (isCorrect(mid) > 0) {
            high = mid - 1;
        } else if (isCorrect(mid) < 0) {
            low = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

int main() {
    int low = 1;
    int high = 100;

    int res = binarySearch(low, high);

    if (res == -1) {
        printf("Value not found");
    } else {
        printf("Correctly guessed the value %d", res);
    }

    return 0;
}