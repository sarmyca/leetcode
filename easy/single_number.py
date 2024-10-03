# Leetcode problem: 136. Single Number
# Problem link: https://leetcode.com/problems/single-number/
# Runtime complexity: O(n)
# Must use constant extra space

# I submitted two solutions for this problem. The first one uses a set to keep track of repeating numbers. The second one uses XOR operation
# Both solutions have the same runtime complexity, but the second one is far more efficient in terms of memory usage
# The first solution was my original submission, but afer reading other solutions i learned about the XOR operation and decided to implement it


# Solution 1: using a set to keep track of repeating numbers
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # This will keep track of repeating numbers
        visited = set()
        
        for num in nums:
            if num in visited:
                # Number is visited -> remove it
                visited.remove(num)
            else:
                # Number is not visited -> add it
                visited.add(num)
        
        # In the end the only number without a pair will be left in the set -> pop it
        return visited.pop()
    
# Solution 2: using XOR operation
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # XOR method
        #----------------------------------------------
        # 1. XOR of a number with itself is 0
        # 2. XOR of a number with 0 is the number itself
        # 3. XOR is commutative and associative
        #----------------------------------------------
        # Because of these three properties, all the pairs can cancel out (become 0) 
        # and when the lone number is xor-ed with 0 it will remain the same
        
        res = 0
        
        for num in nums:
            res ^= num
        
        return res