// Leetcode problem: 22. Generate Parentheses
// Problem link: https://leetcode.com/problems/generate-parentheses/

#include <vector>
#include <string>
#include <stack>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        stack<tuple<string, int, int>> stk; // Stack of tuples (string, number, number) implemented -> to store the current state and numbers of open and close parentheses
        stk.push(make_tuple("", 0, 0)); //Initialising 

        while (!stk.empty()) {
            string curr;
            int open, close;
            tie(curr, open, close) = stk.top(); // Returns a refrence to the top element of the stack (without removing it)
            stk.pop(); // All that is left is to pop the top element

            // Current string is valid -> we can add it to the result vector
            if (curr.size() == n * 2) {
                res.push_back(curr);
                continue;
            }

            // Number of open parentheses is less than the total number of parentheses -> add open parentheses -> push new state to the stack
            if (open < n) {
                stk.push(make_tuple(curr + "(", open + 1, close));
            }

            // Number of close parentheses is less than the number of open parentheses -> add close parentheses -> push new state to the stack
            if (close < open) {
                stk.push(make_tuple(curr + ")", open, close + 1));
            }
        }

        return res;
    }
};
        
