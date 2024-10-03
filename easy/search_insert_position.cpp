// Leetcode problem: 35. Search Insert Position
// Problem link: https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <vector>

using namespace std;

// Solution using binary search -> O(log n)
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // Setup left and right pointers -> we will use them to find the target index
        int left = 0, right = nums.size() - 1;

        // While we haven't found the target index (pointers havent crossed each other)
        while (left <= right) {
            // Calculate the middle index -> use it to compare the target with the middle element
            int middle = left + (right - left) / 2;

            // If the middle element is the target -> we return the index
            if (nums[middle] == target) {
            return middle;

            // If the middle element is smaller than the target -> we move the left pointer to the right of the middle element
            } else if (nums[middle] < target) {
            left = middle + 1;

            // If the middle element is greater than the target -> we move the right pointer to the left of the middle element
            } else {
            right = middle - 1;
            }
        }
        return left;
    }
};