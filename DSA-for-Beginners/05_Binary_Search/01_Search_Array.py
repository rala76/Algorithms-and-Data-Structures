def binarySearch(arr, target):
    L, R = 0, len(arr) - 1

    while L <= R:
        mid = (L + R) // 2

        if target > arr[mid]:
            L = mid + 1
        elif target < arr[mid]:
            R = mid - 1
        else:
            return mid
    
    return -1

def main():
    arr = [1, 3, 3, 4, 5, 6, 7, 8]
    target = 7

    res = binarySearch(arr, target)
    if res == -1:
        print(f"Target value {target} not found")
    else:
        print(f"Target value {target} found at index {res}")

if __name__ == "__main__":
    main()