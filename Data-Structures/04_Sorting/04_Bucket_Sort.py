def bucketSort(arr):
    # Create empty buckets
    counts = [0] * (max(arr) + 1)

    # Count the quantity of each val in arr (frequency)
    for n in arr:
        counts[n] += 1
    
    # Create the sorted arr using counts
    i = 0
    for n in range(len(counts)):
        for j in range(counts[n]):
            arr[i] = n
            i += 1
    
    return arr

def main():
    arr = [2, 1, 5, 0, 0, 2]

    bucketSort(arr)
    print(arr)

if __name__ == "__main__":
    main()