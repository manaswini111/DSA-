# LeetCode 2126 - Destroying Asteroids
#DAY -1 (31-05-2026)
## Problem Statement

You are given:  

* An integer `mass` representing the initial mass of a planet.
* An array `asteroids` where `asteroids[i]` represents the mass of the `i-th` asteroid.

The planet can collide with asteroids in **any order**.

### Collision Rules

* If the planet's mass is **greater than or equal to** the asteroid's mass:

  * The asteroid is destroyed.
  * The planet gains the asteroid's mass.
* Otherwise:

  * The planet is destroyed.

Return `true` if all asteroids can be destroyed, otherwise return `false`.

---

## Example

### Input

```cpp
mass = 10
asteroids = [3,9,19,5,21]
```

### Output

```cpp
true
```

### Explanation

Sort the asteroids:

```cpp
[3,5,9,19,21]
```

Process them one by one:

| Current Planet Mass | Asteroid | New Planet Mass |
| ------------------- | -------- | --------------- |
| 10                  | 3        | 13              |
| 13                  | 5        | 18              |
| 18                  | 9        | 27              |
| 27                  | 19       | 46              |
| 46                  | 21       | 67              |

All asteroids are destroyed successfully.

---

## Approach

### Key Observation

Since we can choose the collision order freely, it is always beneficial to destroy the **smallest asteroids first**.

Why?

* Smaller asteroids are easier to destroy.
* Destroying them increases the planet's mass.
* A larger mass makes it easier to destroy bigger asteroids later.

Therefore:

1. Sort the asteroid masses in ascending order.
2. Traverse the sorted array.
3. If the current planet mass is smaller than the asteroid mass, return `false`.
4. Otherwise, destroy the asteroid and add its mass to the planet.
5. If all asteroids are processed, return `true`.

---

## Solution

```cpp
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

        sort(asteroids.begin(), asteroids.end());

        long long curMass = mass;

        for (int asteroid : asteroids) {

            if (curMass < asteroid)
                return false;

            curMass += asteroid;
        }

        return true;
    }
};
```

---

## Why Use `long long`?

The planet's mass keeps increasing after every collision.

Example:

```cpp
2147401610 + 94196
```

This exceeds the maximum value of an `int`:

```cpp
INT_MAX = 2147483647
```

Using `int` can cause integer overflow.

To avoid this, we store the running mass in:

```cpp
long long curMass
```

---

## Complexity Analysis

### Time Complexity

Sorting the array:

```cpp
O(n log n)
```

Traversing the array:

```cpp
O(n)
```

Overall:

```cpp
O(n log n)
```

---

### Space Complexity

Ignoring the space used by the sorting algorithm:

```cpp
O(1)
```

If sorting space is considered:

```cpp
O(log n)
```

due to recursion used by the sorting implementation.

---

## What I Learned

* Greedy problems often become easier after sorting.
* When the order of operations can be chosen freely, sorting can reveal the optimal strategy.
* Always consider integer overflow when values keep growing during computation.
* `long long` is safer than `int` when cumulative sums can become very large.

---

## Tags

`Greedy` `Sorting` `Arrays`

---

### LeetCode

Problem: 2126 - Destroying Asteroids
