# Leetcode problem: 118. Pascal's Triangle
# Problem link: https://leetcode.com/problems/pascals-triangle/

class Solution(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        # EDGE CASE: first row
        result = [[1]]
        
        for i in range(1, numRows):
            # Current row -> first element
            row = [1]
            
            # Go through the previous row -> add the sum of the two elements above
            for j in range(1, i):
                row.append(result[i-1][j-1] + result[i-1][j])
            
            # Adding the last element of the row
            row.append(1)
            result.append(row)
        
        return result    