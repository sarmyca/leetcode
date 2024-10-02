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
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());

        // Creating a map to store the rank of each element
        map<int, int> rank;
        int r = 1;

        // Assigning ranks to the elements in the sorted array
        for (int i = 0; i < sorted_arr.size(); i++) {
            if (rank.find(sorted_arr[i]) == rank.end()) {
                rank[sorted_arr[i]] = r;
                r++;
            }
        }

        // Creating the result by replacing each element with its allocated rank
        vector<int> result;
        for (int i = 0; i < arr.size(); i++) {
            result.push_back(rank[arr[i]]);
        }

        return result;
    }
};