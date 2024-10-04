// Leetcode problem: 2491. Divide Players into Teams of Equal Skill
// Problem link: https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // Soorting the array -> helps us get min and max quickly
        sort(skill.begin(), skill.end());
        
        int n = skill.size();
        long long totalChemistry = 0;

        // Since we are dividing the players into teams of equal skill -> min + max should be same for all teams
        int teamSkill = skill[0] + skill[n - 1];

        // Iterating frm the start and end -> every pair should have the same sum (min + max of the sorted array)
        for (int i = 0; i < n / 2; ++i) {
            if (skill[i] + skill[n - 1 - i] != teamSkill) {
                return -1; // If any of the pairs don't have the same sum -> return -1
            }

            // Update the total chemistry -> product of each pairs skills
            totalChemistry += static_cast<long long>(skill[i]) * skill[n - 1 - i];
        }
        
        return totalChemistry;
    }
};
