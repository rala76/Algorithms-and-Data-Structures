def quickSort(arr, left, right):
    if left >= right:
        return arr
    
    pivot = arr[right]
    i = left # pointer for left side

    # Partition: elements smaller than pivot on left side
    for j in range(left, right):
        if arr[j] < pivot:
            tmp = arr[i]
            arr[i] = arr[j]
            arr[j] = tmp
            i += 1
    
    # Move pivot in-between left and right sides
    arr[right] = arr[i]
    arr[i] = pivot

    # Quick sort left and right side
    quickSort(arr, left, i - 1)
    quickSort(arr, i + 1, right)

    return arr

def main():
    arr = [6, 2, 4, 1, 3]
    left = 0
    right = len(arr) - 1

    quickSort(arr, left, right)
    print(arr)

if __name__ == "__main__":
    main()