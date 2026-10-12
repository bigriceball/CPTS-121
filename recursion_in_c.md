# 06 - Recursion in C

## 1. What Is Recursion?

**Recursion** is a technique in which a function calls itself to solve a smaller version of the same problem.

A recursive function needs two important parts:

1. **Base case**: the condition that stops the recursion.
2. **Recursive case**: the part where the function calls itself with a smaller or simpler input.

Without a base case, the function may keep calling itself until the program runs out of stack space.

---

## 2. Example: Sum of Numbers from 1 to `n`

The sum of the integers from `1` to `n` can be defined as:

$$
\operatorname{sum}(n)=
\begin{aligned}
&1, && n=1,\\
&n+\operatorname{sum}(n-1), && n>1.
\end{aligned}
$$

In C:

```c
#include <stdio.h>

int sum(int n)
{
    if (n == 1) {
        return 1;  /* Base case */
    }

    return n + sum(n - 1);  /* Recursive case */
}

int main(void)
{
    printf("%d\n", sum(5));
    return 0;
}
```

Output:

```text
15
```

The function works by adding `n` to the sum of all smaller positive integers.

### How `sum(5)` works

The recursive calls go down until the base case is reached:

```text
sum(5) = 5 + sum(4)
sum(4) = 4 + sum(3)
sum(3) = 3 + sum(2)
sum(2) = 2 + sum(1)
sum(1) = 1
```

Then the results return back through the calls:

```text
sum(1) = 1
sum(2) = 2 + 1 = 3
sum(3) = 3 + 3 = 6
sum(4) = 4 + 6 = 10
sum(5) = 5 + 10 = 15
```

This version assumes `n >= 1`. If the function should also accept `n == 0`, use `if (n <= 1) return n;` as the base case. Negative inputs are not valid for this definition.

---

## 3. Example: Factorial

The factorial of a positive integer `n`, written `n!`, is the product of all positive integers from `1` to `n`.

For example:

$$
5! = 5 \times 4 \times 3 \times 2 \times 1 = 120
$$
The recursive definition is:

$$
n! =
\begin{cases}
1, & n \leq 1 \\
n \times (n-1)!, & n > 1
\end{cases}
$$

C implementation:

```c
#include <stdio.h>

int factorial(int n)
{
    if (n <= 1) {
        return 1;  /* Base case */
    }

    return n * factorial(n - 1);  /* Recursive case */
}

int main(void)
{
    printf("%d\n", factorial(5));
    return 0;
}
```

Output:

```text
120
```

This example assumes `n` is non-negative and small enough that the result fits in an `int`. Large factorials overflow ordinary integer types quickly.

---

## 4. Example: Fibonacci Numbers

The Fibonacci sequence begins:

```text
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
```

Each term after the first two is the sum of the previous two terms:

$$
F(n) =
\begin{cases}
0, & n = 0 \\
1, & n = 1 \\
F(n-1) + F(n-2), & n \geq 2
\end{cases}
$$

A recursive implementation in C:

```c
#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0) {
        return 0;  /* First base case */
    }

    if (n == 1) {
        return 1;  /* Second base case */
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
    for (int i = 0; i < 10; i++) {
        printf("%d ", fibonacci(i));
    }

    printf("\n");
    return 0;
}
```

Output:

```text
0 1 1 2 3 5 8 13 21 34
```

This straightforward recursive implementation repeats many calculations, so it becomes slow for larger values of `n`. It is useful for learning recursion, but an iterative solution or a version that stores previously computed values is more efficient for larger inputs.

The function assumes `n >= 0`; negative input is not handled by this definition.

---

## 5. Understanding the Call-and-Return Process

Consider this function:

```c
int countdown_sum(int n)
{
    if (n <= 0) {
        return 0;
    }

    return n + countdown_sum(n - 1);
}
```

Calling `countdown_sum(3)` creates a chain of function calls:

```text
countdown_sum(3)
    3 + countdown_sum(2)
            2 + countdown_sum(1)
                    1 + countdown_sum(0)
                            returns 0
```

When the base case returns `0`, the waiting calls finish one by one:

```text
countdown_sum(0) = 0
countdown_sum(1) = 1 + 0 = 1
countdown_sum(2) = 2 + 1 = 3
countdown_sum(3) = 3 + 3 = 6
```

The important idea is that each call pauses while the next recursive call is evaluated. Once the base case returns, the paused calls continue and return their results.

---

## 6. Common Mistakes

### Forgetting the base case

Incorrect:

```c
int sum(int n)
{
    return n + sum(n - 1);
}
```

This function never stops calling itself for ordinary inputs. A recursive function needs a stopping condition.

### Not moving toward the base case

Incorrect:

```c
int sum(int n)
{
    if (n == 1) {
        return 1;
    }

    return n + sum(n + 1);
}
```
Output:
```
sum(3)
= 3 + sum(4)
= 3 + 4 + sum(5)
= 3 + 4 + 5 + sum(6)
= ...
```
For an initial value greater than `1`, `n` keeps increasing and never reaches `1`. Each recursive call should move toward the base case.

### Confusing the recursive call with the final answer

In `return n + sum(n - 1);`, the function does not know the complete answer immediately. It waits for `sum(n - 1)` to return, then adds `n`.

---

## Summary

- **Recursion** means a function calls itself.
- The **base case** stops the recursive calls.
- The **recursive case** solves a smaller version of the problem.
- Each recursive call has its own parameter values and waits for its result.
- Recursion is useful for problems that can be broken into smaller versions of themselves, but some recursive solutions can be inefficient or use substantial stack space.
