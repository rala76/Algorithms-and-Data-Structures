## Arrays

#### 1. RAM
- **R**andom **A**ccess **M**emory can be thought of as a contiguous block of data
- RAM has two components: Value and Address
- RAM is measured in bytes
  - GB = $10^{9}$ bytes
  - Byte = 8 Bits
  - Bit = 0 or 1
- Integers take 4 bytes (32 bits) to store in memory
- Characters take 1 byte (8 bits) to store in memory

![alt text](../Images/image1.png)

#### 2. Static Arrays
- Static arrays are fixed size
- Read/Write i-th element is O(1)
  - Index of array is mapped to a location in memory making reading or writing data possible in constant time
- Insert/Remove end element is O(1)
  - Arrays are contiguous and its elements can be accessed with indexing which makes inserting or removing the end element possible in constant time
- Insert/Remove middle element is O(n)
  - The worst case is O(n) because we might need to shift every value in the array

#### 3. Dynamic Array