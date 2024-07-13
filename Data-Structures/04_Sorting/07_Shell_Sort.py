def shellSort(arr):
    n = len(arr)

    # Start with a big gap, then reduce the gap
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            tmp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > tmp:
                arr[j] = arr[j - gap]
                j -= gap
            
            arr[j] = tmp
        gap //= 2

def main():
    arr = [7, 6, 8, 9, 3, 2, 10, 5, 1]

    shellSort(arr)
    print(arr)

if __name__ == "__main__":
    main()