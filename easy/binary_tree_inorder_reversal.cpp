// Leetcode problem: 94. Binary Tree Inorder Traversal
// Problem link: https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <vector>
#include <stack>
#include <tuple>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<tuple<TreeNode*, bool>> stk; // Stack of tuples (TreeNode*, boolean) implemented -> storing the current node and checking if the node has been visited or not
        stk.push(make_tuple(root, false)); //Initialising 

        // While there are still nodes to visit -> traverse the tree -> left child is visited first -> then the current node -> then the right child (inorder traversal)
        while (!stk.empty()) {
            TreeNode* curr;
            bool visited;
            tie(curr, visited) = stk.top(); // I do this to get the current node and check if it has been visited or not without removing it from the stack
            stk.pop(); // Lastly -> pop the top element

            // Current node is null -> no need to visit it
            if (curr == nullptr) {
                continue;
            }
            

            // Current node has been visited -> adding it to the result vector 
            // Current node has not been visited -> push() the right child, the current node and the left child
            if (visited) {
                res.push_back(curr->val);
            } else {
                stk.push(make_tuple(curr->right, false));
                stk.push(make_tuple(curr, true));
                stk.push(make_tuple(curr->left, false));
            }
        }

        return res;
    }
};