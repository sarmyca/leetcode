// Leetcode problem: 70. Climbing Stairs
// Problem link: https://leetcode.com/problems/climbing-stairs/

// First idea was recursive solution -> Time limit exceeded -> O(2^n)
// Second idea was to try and use use dynamic programming -> O(n) time complexity and O(n) space complexity


#include <iostream>

using namespace std;

// Recursive solution:
class Solution {
public:
    int climbStairs(int n) {
        // Base case -> if n is less than or equal to 2 (we can climb 1 or 2 steps) -> return the total number of ways calculated
        if (n <= 2) return n;
        // if n is greater than 2 -> we can climb n-1 steps and then 1 step or we can climb n-2 steps and then 2 steps -> return the sum of these two ways
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// Dynamic programming solution:
class Solution {
public:
    int climbStairs(int n) {
        // Base case -> same thing as the recursive solution
        if (n <= 2) return n;

        int prev1 = 1, prev2 = 2;
        
        // Iterate from the 3rd step to the nth step (because we already know the number of ways to reach the 1st and 2nd step)
        for (int i = 3; i <= n; ++i) {
            // For any step i -> total number of ways to reach that step is the sum of the number of ways to reach the previous two steps (similar to the recursive solution)
            int current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }

        return prev2;
    }
};