// Leetcode problem: 13. Roman to Integer
// Problem link: https://leetcode.com/problems/roman-to-integer/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        
        // Store the values of each Roman numeral in a map
        unordered_map<char, int> numerals = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        
        for (int i = 0; i < s.size(); i++) {
            // If the Roman numeral is smaller than the next one we subtract
            if (i + 1 < s.size() && numerals[s[i]] < numerals[s[i + 1]]) {
            res -= numerals[s[i]];
            } else {
            // Otherwise we add
            res += numerals[s[i]];
            }
        }
        
        return res;
    }
};