// Leetcode problem: 4. Median of Two Sorted Arrays
// Problem link: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // IMPORTANT Edge case: if nums1 is larger than nums2 -> swap them :)
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int x = nums1.size();
        int y = nums2.size();
        
        int low = 0;
        int high = x;
        
        // Using binary search to find the correct partition
        while (low <= high) {
            int partX = low + (high - low) / 2;
            int partY = (x + y + 1) / 2 - partX;
            
            // Edge values for partitions :)
            int maxX = (partX == 0) ? INT_MIN : nums1[partX - 1];
            int minX = (partX == x) ? INT_MAX : nums1[partX];
            
            int maxY = (partY == 0) ? INT_MIN : nums2[partY - 1];
            int minY = (partY == y) ? INT_MAX : nums2[partY];
            
            // Checking if the found partition is correct
            if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) { // If the length is even
                return (std::max(maxX, maxY) + std::min(minX, minY)) / 2.0; 
            } 
            else {  // If the length is odd
                return std::max(maxX, maxY);
            }
            } else if (maxX > minY) { //Go left in nums1
            high = partX - 1;
            } 
            else { // Go right in nums1
            low = partX + 1;
            }
        }
        return 0.0;
    }
};