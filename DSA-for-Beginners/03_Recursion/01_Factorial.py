def factorial(n):
    # Base case
    if n <= 1:
        return 1
    
    # Recursive step
    return n * factorial(n - 1)

def main():
    n = 5
    result = factorial(n)
    print(f"{n}! = {result}")

if __name__ == "__main__":
    main()