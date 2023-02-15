/*
https://leetcode.com/problems/valid-palindrome
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters 
and removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
    Input: s = "A man, a plan, a canal: Panama"
    Output: true
    Explanation: "amanaplanacanalpanama" is a palindrome.
*/

#include <iostream>
#include <algorithm>
using namespace std;

/*
Solution: 2 pointer approach
    - This solution first step convert all character in string s to lower
    - using 2 pointers loop toward each other until they meet in the middle of string
    - If the character not be a alphabet, the character is ignored

Complexity analysis:
    - Time complexity: O(1/2 n) + O(1/2 n) = O(n) - beats 100%
    - Space complexity: O(1) - beats 84.19%
*/

class Solution {
public:
    bool isPalindrome(string s) {
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0, j = s.length() - 1;

        while (i < j) {
            while (!isalnum(s[i]) && i < j) { i++; }
            while (!isalnum(s[j]) && i < j) { j--; }
            if (s[i] != s[j]) return false;
            i++; j--;
        }

        return true;
    }
};