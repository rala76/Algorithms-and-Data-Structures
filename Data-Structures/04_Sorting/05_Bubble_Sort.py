def bubbleSort(arr):
    n = len(arr)

    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    
    return arr

def main():
    arr = [2, 8, 5, 3, 8, 4, 1]

    bubbleSort(arr)
    print(arr)

if __name__ == "__main__":
    main()