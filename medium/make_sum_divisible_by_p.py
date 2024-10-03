# Leetcode problem: 1590. Make Sum Divisible by P
# Problem link: https://leetcode.com/problems/make-sum-divisible-by-p/

class Solution(object):
    def minSubarray(self, nums, p):
        """
        :type nums: List[int]
        :type p: int
        :rtype: int
        """
        length = len(nums)
        
        # "x" represents the remainder of the sum when the array is divided by p
        x = sum(nums) % p
        
        # EDGE CASE -> if "x" is 0 -> array already divisible by p
        if x == 0:
            return 0
        
        prefix = 0
        map = {0: -1}
        minLength = length
        
        for i in range(length):
            prefix = (prefix + nums[i]) % p
            
            # Using the found prefix as key -> store the index
            map[prefix] = i
            
            # Checking if the wanted prefix is in our map
            target_prefix = (prefix - x) % p
            if target_prefix in map:
                minLength = min(minLength, i - map[target_prefix])
        
        # If found -> return min length -> otherwise return impossible "-1"
        return minLength if minLength < length else -1