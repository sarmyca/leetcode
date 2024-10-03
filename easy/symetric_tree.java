// Leetcode problem: 101. Symmetric Tree
// Problem link: https://leetcode.com/problems/symmetric-tree/

// Trying to solve the problem using Java (not well versed with Java)

import java.util.LinkedList;
import java.util.Queue;

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
    public boolean isSymmetric(TreeNode root) {
        // No root -> symmetric
        if (root == null) {
            return true;
        }

        // Using a queue -> add the left and right children of the root -> check if they are symmetric
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root.left);
        queue.add(root.right);

        while (!queue.isEmpty()) {
            TreeNode left = queue.poll();
            TreeNode right = queue.poll();

            // Both nodes are null -> they are symmetric -> keep checking
            if (left == null && right == null) {
                continue;
            }
            // Either one of the nodes is null OR either one of the nodes has a different value -> not symmetric -> return false
            if (left == null || right == null || left.val != right.val) {
                return false;
            }

            // Add the children of each node to the queue so that they can be checked for symmetry in the next iteration
            queue.add(left.left);
            queue.add(right.right);
            queue.add(left.right);
            queue.add(right.left);
        }
        
        return true;
    }
}