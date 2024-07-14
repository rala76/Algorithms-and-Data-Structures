def main():
    names = ["alice", "brad", "collin", "brad", "dylan", "kim"]

    countMap = {}
    for name in names:
        # If countMap does not contain name
        if name not in countMap:
            countMap[name] = 1
        else:
            countMap[name] += 1
    
    for key, value in countMap.items():
        print(f"{key}: {value}")

if __name__ == "__main__":
    main()