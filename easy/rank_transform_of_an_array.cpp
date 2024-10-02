// Leetcode problem: 1331. Rank Transform of an Array
// Problem link: https://leetcode.com/problems/rank-transform-of-an-array/

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        // Creating a copy of the original array and sorting it
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        // Creating a map to store the rank of each element
        map<int, int> ranks;
        int r = 1;

        // Assigning ranks to the elements in the sorted array
        for (int i = 0; i < sorted.size(); i++) {
            if (ranks.find(sorted[i]) == ranks.end()) {
                ranks[sorted[i]] = r;
                r++;
            }
        }

        // Creating the result by replacing each element with its allocated rank
        vector<int> res;
        for (int i = 0; i < arr.size(); i++) {
            res.push_back(ranks[arr[i]]);
        }

        return res;
    }
};