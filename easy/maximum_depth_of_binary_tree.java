// Leetcode problem: 104. Maximum Depth of Binary Tree
// Problem link: https://leetcode.com/problems/maximum-depth-of-binary-tree/

// Trying to solve the problem using Java

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public int maxDepth(TreeNode root) {
        // If there is no root -> depth is 0
        if (root == null) {
            return 0;
        }
        
        // Using recursion -> find depth of the left subtree
        int leftDepth = maxDepth(root.left);
        
        // Using recursion -> find depth of the right subtree
        int rightDepth = maxDepth(root.right);
        
        // Total depth -> maximum depth of the left and right subtree + 1 (because the root exists)
        return Math.max(leftDepth, rightDepth) + 1;
    }
}