// Leetcode problem: 20. Valid Parentheses
// Problem link: https://leetcode.com/problems/valid-parentheses/

#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // I use a stack to keep track of the open brackets
        stack<char> stack;
        
        
        for (char c : s) {
            // If the character is an open bracket -> push()
            if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
            } else {
            // If the stack is empty -> no matching open bracket
            if (stack.empty()) return false;
            
            // Checking if the current close bracket is the same as the top of the stack
            if (c == ')' && stack.top() != '(') return false;
            if (c == ']' && stack.top() != '[') return false;
            if (c == '}' && stack.top() != '{') return false;
            
            // If we have a match -> pop()
            stack.pop();
            }
        }
        
        // If the stack is empty -> all brackets are matched up successfully
        return stack.empty();
    }
};