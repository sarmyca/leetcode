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
        
        # This represents the remainder of all the elements in the array when divided by p
        x = sum(nums) % p
        
        # If that remainder is 0 -> the array is already divisible by p
        if x == 0:
            return 0
        
        # EDGE CASE -> the sum of nums is less than p -> not possible to make the sum divisible by p
        if sum(nums) < p:
            return -1
        
        prefix = 0
        map = {0: -1}
        
        minLength = length
        
        current_sum = 0
        
        for i in range(length):
            # As we go through the array, we increment the total sum
            current_sum += nums[i]
            
            # Calculating the prefix
            prefix = current_sum % p
            
            # Using the prefix as a key -> store its index
            map[prefix] = i
            
            # CHecking if "x" is in the map
            if (prefix - x) % p in map:
            # If yes -> calculate the length of the subarray
                minLength = min(minLength, i - map[(prefix - x) % p])
        
        return minLength if minLength < length else -1