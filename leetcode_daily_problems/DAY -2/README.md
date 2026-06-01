# 2144. Minimum Cost of Buying Candies With Discount

## Problem

A shop offers a special discount:

- For every **2 candies purchased**, you can get **1 candy for free**.
- The free candy must have a cost **less than or equal to** the cheaper of the two purchased candies.

Given an integer array `cost`, where `cost[i]` represents the cost of the `i-th` candy, return the **minimum cost required to buy all candies**.

---

## Approach

To maximize the discount:

1. Sort the candy costs in **descending order**.
2. Process candies in groups of **3**.
3. In each group:
   - Pay for the first two (most expensive) candies.
   - Get the third candy for free.
4. Add the cost of all candies except every third candy.

Since the array is sorted in descending order, the third candy in each group is the most valuable candy that can be taken for free.

---

## Example

### Input

```text
cost = [6,5,7,9,2,2]
```

### Sorted

```text
[9,7,6,5,2,2]
```

### Groups

```text
[9,7,6] → Pay 9 + 7, Free 6
[5,2,2] → Pay 5 + 2, Free 2
```

### Output

```text
23
```

---

## Solution

```cpp
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());

        int total = 0;

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 != 0) {
                total += cost[i];
            }
        }

        return total;
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** `O(n log n)`
  - Sorting the array takes `O(n log n)`.
  - Traversing the array takes `O(n)`.

- **Space Complexity:** `O(1)`
  - No extra data structures are used (excluding sorting space).

---

## Test Cases

### Test Case 1

```text
Input:  [1,2,3]
Output: 5
```

### Test Case 2

```text
Input:  [6,5,7,9,2,2]
Output: 23
```

### Test Case 3

```text
Input:  [5,5]
Output: 10
```

### Test Case 4

```text
Input:  [8,6,4,2,1]
Output: 17
```

---