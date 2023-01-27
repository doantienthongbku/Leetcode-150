/*
https://leetcode.com/problems/top-k-frequent-elements
Given an integer array nums and an integer k, return the k most frequent elements.
You may return the answer in any order.

Example 1:
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;


/*
Solution - hash map approach
    - first save all frequent of elements to unordered_map mp.
    - Then create a multimap mp_ordered and insert all item from mp, this will be 
    sort automatically greater.
    - using a i variable as a counting variable and add ele to result

Complexity:
    - Time complexity: O(m + n + k) = O(n) - beats 52.53%
        (with m is number of ele in nums, n is number of frequent ele and k is in test case)
    - Space complexity: O(m + n) = O(n) - beats 19.54%
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> mp;
        multimap<int, int, greater<int>> mp_ordered;
        int i = 0;

        for (auto num : nums) mp[num]++;
        for (auto item : mp)
            mp_ordered.insert({item.second, item.first});
        
        for (auto item : mp_ordered) {
            i++;
            if (i > k) return result;
            result.push_back(item.second);
        }

        return result;
    }
};
