# Leetcode problem: 1. Two Sum
# Provlem link: https://leetcode.com/problems/two-sum/
# Complexity must be <O(n^2)

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        
        for i in range(len(nums)):
            # Check if the complement (target - current number) exists in the dictionary
            if target - nums[i] in dict:
            # If found, return the index of the complement and the index of the current number
                return [dict[target - nums[i]], i]
            dict[nums[i]] = i
        return []
    