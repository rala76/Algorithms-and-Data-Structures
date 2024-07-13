def fibonacci(n):
    # Base case
    if n <= 1:
        return n
    
    # Recursive step
    return fibonacci(n - 1) + fibonacci(n - 2)

def main():
    n = 12
    result = fibonacci(n)
    print(f"Fibonacci {n} = {result}")

if __name__ == "__main__":
    main()