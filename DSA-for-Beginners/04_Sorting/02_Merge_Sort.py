def mergeSort(arr, left, right):
    if left >= right:
        return arr
    
    # The middle index of the array
    mid = (left + right) // 2

    # Sort the left half
    mergeSort(arr, left, mid)
    
    # Sort the right half
    mergeSort(arr, mid + 1, right)

    # Merge sorted halfs
    merge(arr, left, mid, right)

    return arr

# Merge in-place
def merge(arr, left, mid, right):
    # Copy the sorted left & right halfs to temp arrays
    L = arr[left: mid + 1]
    R = arr[mid + 1: right + 1]

    i = 0 # index for L
    j = 0 # index for R
    k = left # index for arr

    # Merge the two sorted halfs into the original array
    while i < len(L) and j < len(R):
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
    
    # One of the halfs will have elements remaining
    while i < len(L):
        arr[k] = L[i]
        i += 1
        k += 1
    while j < len(R):
        arr[k] = R[j]
        j += 1
        k += 1

def main():
    arr = [3, 2, 4, 1, 6]
    left = 0
    right = len(arr) - 1

    mergeSort(arr, left, right)
    print(arr)

if __name__ == "__main__":
    main()