/*
https://leetcode.com/problems/permutation-in-string/
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
    Input: s1 = "ab", s2 = "eidbaooo"
    Output: true
    Explanation: s2 contains one permutation of s1 ("ba").
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Solution 1: sliding window + check duplicate
Complexity analysis:
    - Time complexity: O(n^2) - beats 24.29%
    - Space complexity: O(1) - beats 14.71%
*/

class Solution {
public:
    bool isSameVec(vector<int> v1, vector<int> v2) {
        int len = v1.size();
        for (int i = 0; i < len; i++)
            if (v1[i] != v2[i]) return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> freqS1(26, 0);
        for (auto c: s1) freqS1[c - 'a']++;

        vector<int> freqS2(26, 0);
        int i = 0, j = 0;

        while(j < s2.size()) {
            freqS2[s2[j] - 'a']++;

            if (j - i + 1 == s1.size())
                if (isSameVec(freqS1, freqS2)) return true;
            
            if (j - i + 1 < s1.size()) j++;
            else {
                freqS2[s2[i] - 'a']--;
                i++; j++;
            }
        }

        return false;
    }
};
