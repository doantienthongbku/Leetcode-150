/*
https://leetcode.com/problems/two-sum
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*Simplest solution: Time complexity: O(n^2), Space complexity: O(1)*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size() - 1; i++)
            for (int j = i+1; j < nums.size(); j++) 
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
        return result;
    }
};

/*Hashmap solution: Time complexity: O(n) - beats 65.25%, Space complexity: O(n) - beats 29.74%*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (seen.count(diff)) {
                result.push_back(i);
                result.push_back(seen[diff]);
                return result;
            }
            seen[nums[i]] = i;
        }
        return result;
    }
};