# Python arrays are dynamic by default, but this is an example of resizing
class DynamicArray:
    def __init__(self, capacity):
        self.capacity = capacity
        self.length = 0
        self.arr = [0] * capacity
    
    # Insert val in the last position of the array
    def pushback(self, val):
        if self.length == self.capacity:
            self.resize()

        # Insert at next empty position
        self.arr[self.length] = val
        self.length += 1
    
    def resize(self):
        # Create new array of double capacity
        self.capacity = 2 * self.capacity
        newArr = [0] * self.capacity
        
        # Copy elements to newArr
        for i in range(self.length):
            newArr[i] = self.arr[i]
        
        self.arr = newArr
    
    # Remove the last element in the array
    def popback(self):
        if self.length > 0:
            self.length -= 1

    # Get value at i-th index
    def get(self, i):
        if i < self.length:
            return self.arr[i]
        # Here we would throw an out of bounds exception

    # Insert val at i-th index
    def set(self, i, val):
        if i < self.length:
            self.arr[i] = val
        # Here we would throw and out of bounds exception

    # Return number of elements in the dynamic array
    def getSize(self):
        return self.length

    # Return capacity of the dynamic array
    def getCapacity(self):
        return self.capacity

def main():
    # Test Case 1
    # Input: ["Array", 1, "getSize", "getCapacity"]
    print("Test Case #1")
    arr1 = DynamicArray(1)
    print(f"getSize: {arr1.getSize()}")
    print(f"getCapacity: {arr1.getCapacity()}")
    print("\n")
    
    # Test Case 2
    # Input: ["Array", 1, "pushback", 1, "getCapacity", "pushback", 2, "getCapacity"]
    print("Test Case #2")
    arr2 = DynamicArray(1)
    arr2.pushback(1)
    print(f"getCapacity: {arr2.getCapacity()}")
    arr2.pushback(2)
    print(f"getCapacity: {arr2.getCapacity()}")
    print("\n")

    # Test Case 3
    # Input: ["Array", 1, "getSize", "getCapacity", "pushback", 1, "getSize", "getCapacity", 
    #         "pushback", 2, "getSize", "getCapacity", "get", 1, "set", 1, 3, "get", 1, 
    #         "popback", "getSize", "getCapacity"]
    print("Test Case #3")
    arr3 = DynamicArray(1)
    print(f"getSize: {arr3.getSize()}")
    print(f"getCapacity: {arr3.getCapacity()}")
    arr3.pushback(1)
    print(f"getSize: {arr3.getSize()}")
    print(f"getCapacity: {arr3.getCapacity()}")
    arr3.pushback(2)
    print(f"getSize: {arr3.getSize()}")
    print(f"getCapacity: {arr3.getCapacity()}")
    arr3.get(1)
    arr3.set(1, 3)
    arr3.get(1)
    arr3.popback()
    print(f"getSize: {arr3.getSize()}")
    print(f"getCapacity: {arr3.getCapacity()}")
    print("\n")
    
if __name__ == "__main__":
    main()