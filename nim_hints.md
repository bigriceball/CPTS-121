# Lab 11 – Nim Game: Function Hints

The Nim game uses **five functions** to organize the program. Each function has a specific task.

### 1. `printStatus()`
- Display the current player's turn.
- Display the number of stones remaining in each of the three heaps.

```c
void printStatus(int player, int heapCount1, int heapCount2, int heapCount3);
```

### 2. `getHeap()`
- Ask the player which heap to take stones from (1, 2, or 3).
- Check that the heap number is valid.
- Return the selected heap number.

```c
int getHeap(void);
```

### 3. `setHeapCountPointer()`
- Use the selected heap number to identify the correct heap.
- Return the address of that heap.
- Remember: use `&` to get an address.

```c
int *setHeapCountPointer(int heap, int *heapCount1,
                         int *heapCount2, int *heapCount3);
```

### 4. `getTake()`
- Ask the player how many stones to take.
- The player must take at least 1 stone and cannot take more than the number of stones remaining in the selected heap.
- Return the number of stones taken.

```c
int getTake(int heap, int heapCount);
```

### 5. `playNim()`
- Initialize the three heaps with 3, 4, and 5 stones.
- Switch between Player 1 and Player 2.
- Call the other four functions to play the game.
- Use a pointer to update the selected heap.
- Stop when all stones have been taken.
- Return the winner.

```c
int playNim(void);
```

**Important pointer reminders:**
- `&variable` – get the address of a variable.
- `pointer` – store an address.
- `*pointer` – access or modify the value at that address.

**Note:** Do not modify the provided `main()` function.