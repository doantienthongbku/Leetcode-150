/*
https://leetcode.com/problems/group-anagrams
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase,
typically using all the original letters exactly once.

Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
My Solution: 
    first, sort all item in strs by sort() function in algorithm library with time complexity O(nlogn),
    and save it into unordered_map <string, vector<string>>. Then easily add into result vector
    
    - Time complexity: O(n^2 log n) - beats 76.54%
    - Space complexity: O(n) - beats 46.55%
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mp[tmp].push_back(strs[i]);
        }

        for (auto item : mp) {
            result.push_back(item.second);
        }

        return result;
    }
};
