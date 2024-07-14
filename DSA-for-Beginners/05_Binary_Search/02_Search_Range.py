def isCorrect(n):
    val = 10

    if n > val:
        return 1
    elif n < val:
        return -1
    else:
        return 0

def binarySearch(low, high):
    while low <= high:
        mid = (low + high) // 2

        if isCorrect(mid) > 0:
            high = mid - 1
        elif isCorrect(mid) < 0:
            low = mid + 1
        else:
            return mid
    
    return -1

def main():
    low = 1
    high = 100

    res = binarySearch(low, high)
    if res == -1:
        print("You did not guess the number")
    else:
        print("You guessed the number")

if __name__ == "__main__":
    main()