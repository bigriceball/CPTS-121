# Lab 11 – Nim Game: Function Hints

**1. printStatus()** – Display the current player and the number of stones remaining in each heap.

```c
void printStatus(int player, int heapCount1, int heapCount2, int heapCount3);
```

**2. getHeap()** – Ask the player to select a heap (1–3). Check the input and return the valid heap number.

```c
int getHeap(void);
```

**3. setHeapCountPointer()** – Use the selected heap number to identify the correct heap and return its address. Use `&` to get an address.

```c
int *setHeapCountPointer(int heap, int *heapCount1,
                         int *heapCount2, int *heapCount3);
```

**4. getTake()** – Ask how many stones the player wants to take. The number must be between 1 and the remaining stones in the selected heap. Return the number of stones taken.

```c
int getTake(int heap, int heapCount);
```

**5. playNim()** – Initialize the three heaps (3, 4, and 5 stones), switch between players, call the other four functions, update the selected heap using a pointer, and return the winner when all stones are taken.

```c
int playNim(void);
```

**Pointer Reminder:** `&` gets an address; a pointer stores an address; `*` accesses or modifies the value at that address.

**Do not modify the provided `main()` function.**
