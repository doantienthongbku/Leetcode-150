/*
https://leetcode.com/problems/longest-consecutive-sequence/
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

Example 1:
    Input: nums = [100,4,200,1,3,2]
    Output: 4
    Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

/*
Solution: set approach
Complexity analysis:
    - Time complexity: O(n + n) = O(n) - beats 83.64%
    - Space complexity: O(n) - beats 71.41%
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;
        for (auto item : s) {
            if (!s.count(item - 1)) {
                int length = 1;
                while (s.count(item + length))
                    length++;
                longest = max(length, longest);
            }
        }
        return longest;
    }
};