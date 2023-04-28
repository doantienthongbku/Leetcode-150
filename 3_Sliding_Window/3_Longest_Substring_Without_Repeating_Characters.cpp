/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
Given a string s, find the length of the longest 
substring without repeating characters.

Example 1:
    Input: s = "abcabcbb"
    Output: 3
    Explanation: The answer is "abc", with the length of 3.
*/

#include <iostream>
#include <unordered_map>
using namespace std;

/*
Solution 1: sliding window + check duplicate
Complexity analysis:
    - Time complexity: O(n^2) - beats 5.1%
    - Space complexity: O(1) - beats 5.4%
*/
class Solution {
public:
    bool containsDuplicate(string nums) {
        unordered_map<char, char> freq;
        for (auto num:nums) {
            if (freq[num]) return true;
            freq[num]++;
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int start_char = 0, max_char = 1;
        int i = 0;
        if (s.length() == 0) return 0;
        while (i < s.length()) {
            if (i == start_char) {i++; continue;}
            if (containsDuplicate(s.substr(start_char, i - start_char + 1))) {
                start_char++;
            } else {
                max_char = max(max_char, i - start_char + 1);
            }
            i++;
        }
        return max_char;
    }
};

/*
Solution 2: sliding window + hashmap
Complexity analysis:
    - Time complexity: O(n) - beats 71.2%
    - Space complexity: O(n) - beats 78.6%
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int i = 0, j = 0, len = s.size(), max_substr = 1;
        if (len == 0) return 0;
        while (j < len) {
            if (freq[s[j]]) {
                freq[s[i]]--;
                i++;
            } else {
                freq[s[j]]++;
                max_substr = max(max_substr, j - i + 1);
                j++;
            }
        }

        return max_substr;
    }
};