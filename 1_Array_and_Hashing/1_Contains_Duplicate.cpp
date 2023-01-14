/*
Given an integer array nums, return true if any value appears at least twice in the array, 
and return false if every element is distinct.

Example 1:
    Input: nums = [1,2,3,1]
    Output: true

My solution:
    Time complexity: O(n) - beats 81.44%
    Space complexity: O(n) - beats 39.59%
*/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (auto num:nums) {
            if (freq[num]) return true;
            freq[num]++;
        }
        return false;
    }
};