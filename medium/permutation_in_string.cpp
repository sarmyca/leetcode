// Leetcode problem: 567. Permutation in String
// Problem link: https://leetcode.com/problems/permutation-in-string/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        
        // EDGE CASE ->  s1 bigger than s2 -> no permutation possible
        if (size1 > size2) {
            return false;
        }
        
        // Make a simple array of size 26 -> to store the frequency of each character in s1 and s2
        // By having the frequency (count) of each character in s1 and s2 -> we can compare them to check if they are permutations
        vector<int> frequency1(26, 0);
        vector<int> frequency2(26, 0);
        
        // Getting the frequency of each character in s1 and s2 -> for the first n characters (size of s1) 
        for (int i = 0; i < size1; ++i) {
            frequency1[s1[i] - 97]++; // -> 97 is the ASCII value of 'a'
            frequency2[s2[i] - 97 ]++;
        }
        
        // Start from the n-th character -> keep updating the frequency of each character in s2
        // IMPORTATNT: remove the frequency of the (i - n)th character -> keeps the window size same as s1
        // If the frequencies of s1 and s2 characters are the same -> they are permutations
        for (int i = size1; i < size2; ++i) {
            if (frequency1 == frequency2) {
                return true;
            }
            
            frequency2[s2[i] - 'a']++;
            frequency2[s2[i - size1] - 'a']--;
        }
        
        return frequency1 == frequency2;
    }   
};