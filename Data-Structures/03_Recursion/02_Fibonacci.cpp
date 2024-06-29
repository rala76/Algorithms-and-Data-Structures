#include <iostream>

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int result = fibonacci(5);
    printf("5th Fibonacci Number: %d", result);

    return 0;
}