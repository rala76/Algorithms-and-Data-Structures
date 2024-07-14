# Insert val into arr at the next open position.
# Length is the number of 'real' values in arr, and capacity is the size (aka memory allocated for the fixed size array).
def insertEnd(arr, val, length, capacity):
    if length < capacity:
        arr[length] = val
    
    # Increase length by 1
    length += 1

    return length

# Remove from the last position in the array if the array is not empty (i.e. length is non-zero)
def removeEnd(arr, length):
    if length > 0:
        arr[length - 1] = 0
    
    # Decrease length by 1
    length -= 1

    return length

# Insert val into index i after shifting elements to the right
# Assuming i is a valid index and arr is not full
def insertMiddle(arr, i, val, length):
    # Shift starting from the end to i
    for index in range(length - 1, i - 1, -1):
        arr[index + 1] = arr[index]
    
    # Insert at i
    arr[i] = val

    # Increase length by 1
    length += 1

    return length

# Remove value at index i before shifting elements to the left
# Assuming i is a valid index
def removeMiddle(arr, i, length):
    for index in range(i + 1, length):
        arr[index - 1] = arr[index]
        
    # Remove arr[i]
    arr[length - 1] = 0
    
    # Decrease length by 1
    length -= 1

    return length

def main():
    # Lists are arrays in python

    # Initialize an empty list
    arr1 = []

    # Initialize a list with values
    arr2 = [1, 2, 3, 4, 5]

    # Initialize a list using list comprehension
    arr3 = [i for i in range(5)]

    # Initialize a list of zeroes using * operator
    arr4 = [0] * 5

    # Initialize a list using list()
    arr5 = list((1, 2, 3, 4, 5))
    arr6 = list(range(5))

    # Initialize list after declaration (using loops)
    arr7 = []
    for i in range (5):
        arr7.append(i + 1)

    # List operations
    capacity = 5
    length = 3
    arr8 = [1, 2, 3] + ([0] * (capacity - length))
    print("Original: ", arr8)
    
    print("Insert '5' at the next open position: ")
    length = insertEnd(arr8, 5, length, capacity)
    print(arr8)

    print("Insert '4' at index 3: ")
    length = insertMiddle(arr8, 3, 4, length)
    print(arr8)

    print("Remove the last element in the array: ")
    length = removeEnd(arr8, length)
    print(arr8)

    print("Remove '2' at index 1: ")
    length = removeMiddle(arr8, 1, length)
    print(arr8)

    # Built-in methods for lists/arrays
    arr9 = []
    print("Original: ", arr9)

    arr9.append(1)
    arr9.append(3)
    arr9.append(4)
    print(arr9)

    arr9.insert(1, 2)
    print(arr9)

    arr9.remove(2)
    arr9.remove(4)
    print(arr9)

    arr9.pop()
    print(arr9)

    arr9.clear()
    print(arr9)

    arr9 = arr8.copy()
    print(arr9)

    # Others
    # arr9.count(0)
    # arr9 = arr9.reverse()
    # arr9.sort()

if __name__ == "__main__":
    main()