def selectionSort(arr):
    n = len(arr)

    for i in range(n):
        # Index of min value in unsorted part of arr
        m = i
        
        # Find the minimum in the unsorted part of arr
        for j in range(i + 1, n):
            if arr[j] < arr[m]:
                m = j
        
        # Move the min value to the front of the unsorted part of arr
        arr[i], arr[m] = arr[m], arr[i]

    return arr

def main():
    arr = [2, 8, 5, 3, 9, 4, 1]

    selectionSort(arr)
    print(arr)

if __name__ == "__main__":
    main()