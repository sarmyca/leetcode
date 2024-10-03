// Leetcode problem: 14. Longest Common Prefix
// Problem link: https://leetcode.com/problems/longest-common-prefix/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // Dont forget edgde cases :)
        if (strs.empty()) return "";

        string prefix = strs[0];
        
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;

            // Find the minimum length between the current prefix and the current string
            int minLength = min(prefix.size(), strs[i].size());

            // Compare characters until they are different or we reach the end of the shorter string
            while (j < minLength && prefix[j] == strs[i][j]) {
            j++;
            }

            // Update with the new prefix
            prefix = prefix.substr(0, j);

            // If its empty -> there is no common prefix
            if (prefix.empty()) break;
        }
        
        return prefix;
    }
};