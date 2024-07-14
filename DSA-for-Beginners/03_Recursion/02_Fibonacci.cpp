#include <iostream>

int fibonacci(int n) {
    // Base Case
    if (n <= 1) {
        return n;
    }

    // Recursive step
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int result = fibonacci(5);
    printf("5th Fibonacci Number: %d", result);

    return 0;
}