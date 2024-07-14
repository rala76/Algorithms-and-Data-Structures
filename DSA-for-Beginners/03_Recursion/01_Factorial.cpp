#include <iostream>

int factorial(int n) {
    // Base case
    if (n <= 1) {
        return 1;
    }

    // Recursive step
    return n * factorial(n-1);
}

int main() {
    int n = 5;
    int result = factorial(n);
    printf("%d! = %d\n", n, result);

    return 0;
}