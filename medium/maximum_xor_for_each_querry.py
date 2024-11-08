# Leetcode problem: 1829. Maximum XOR for Each Query
# Problem link: https://leetcode.com/problems/maximum-xor-for-each-query/

class Solution(object):
    def getMaximumXor(self, nums, maximumBit):
        """
        :type nums: List[int]
        :type maximumBit: int
        :rtype: List[int]
        """
        
        # First i need to calculate the maximum number that can be formed with maximumBit
        maxNumber = (1 << maximumBit) - 1
        current = 0
        res = []
        
        # Then i calculate the xor for all the numbers
        for num in nums:
            current ^= num
            max_xor = maxNumber ^ current
            res.append(max_xor)
        
        # Return the REVERSE of the result
        return [res[i] for i in range(len(res)-1, -1, -1)]