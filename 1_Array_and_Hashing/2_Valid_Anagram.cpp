/*
https://leetcode.com/problems/valid-anagram
Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true

My solution:
    Time complexity: O(n) - beats 85.76%
    Space complexity: O(n) - beats 84.22%
*/

#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int len_S = s.length();
        if (len_S != t.length()) return false;
        int ind1[26] = {0};
        int ind2[26] = {0};
        for (int i = 0; i < len_S; i++) {
            ind1[s[i] - 'a']++;
            ind2[t[i] - 'a']++;            
        }
        for (int i = 0; i < 26; i++) 
            if (ind1[i] != ind2[i]) return false;
        
        return true;
    }
};