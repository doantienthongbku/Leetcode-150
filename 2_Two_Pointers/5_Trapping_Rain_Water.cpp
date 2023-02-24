/*
https://leetcode.com/problems/trapping-rain-water
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.

Example 1:
    Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
    Output: 6
    Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
    In this case, 6 units of rain water (blue section) are being trapped.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Solution: Two pointers approach

Complexity analysis:
    - Time complexity: O(n) - beats 88.64%
    - Space complexity: O(1) - beats 86.80%
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int amount = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            while (l + 1 < r && height[l + 1] >= height[l]) l++;
            while (l < r - 1 &&height[r - 1] >= height[r]) r--;
            if (height[l] < height[r]) {
                int i = 1;
                while (height[l + i] < height[l] && l + i < r) {
                    amount += (height[l] - height[l + i]);
                    i++;
                }
                l = l + i;
            } else {
                int j = 1;
                while (height[r - j] < height[r] && l < r - j) {
                    amount += (height[r] - height[r - j]);
                    j++;
                }
                r = r - j;
            }
        }

        return amount;
    }
};