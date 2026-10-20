## Understanding the Null Terminator (`\0`) in C

Let's look at this example:

```c
char name[6] = "Alice";
```

### How C Stores the String "Alice"

| Index | 0 | 1 | 2 | 3 | 4 | 5 |
|---|---|---|---|---|---|---|
| Character | `'A'` | `'l'` | `'i'` | `'c'` | `'e'` | `'\0'` |

The array has **6 positions: 5 letters and 1 null terminator**.

### Classroom Explanation

"In C, a string needs a special character at the end called the **null terminator**, written as backslash zero (`\0`).

It tells C where the string ends.

For example, Alice has five letters, but we need six spaces to store it as a string."

### Why Do We Use `%49s`?

Now let's look at another example:

```c
char name[50];
scanf("%49s", name);
```

We have an array that can hold 50 characters.

However, we need to reserve one position for the null terminator (`\0`).

Therefore:

- **49 positions** are available for the actual characters.
- **1 position** is reserved for the null terminator.
- **Total: 50 positions.**

That's why we use `%49s` instead of `%50s`.

### Key Takeaway

**A C string needs one extra position for the null terminator (`\0`).**

The null terminator is not the same as the character `'0'`. It is a special character that marks the end of a string.