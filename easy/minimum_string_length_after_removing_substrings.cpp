// Leetcode problem: 2696. Minimum String Length After Removing Substrings
// Problem link: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        int position;

        // Find the position of "AB" or "CD" -> erase them -> repeat until there is no "AB" or "CD"
        while ((position = s.find("AB")) != string::npos || (position = s.find("CD")) != string::npos) {
            s.erase(position, 2);
        }

        return s.length();
    }
};