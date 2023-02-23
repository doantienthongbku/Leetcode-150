/*
https://leetcode.com/problems/container-with-most-water
You are given an integer array height of length n. There are n vertical lines drawn such that
the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Example 1:
    Input: height = [1,8,6,2,5,4,8,3,7]
    Output: 49
    Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. 
    In this case, the max area of water (blue section) the container can contain is 49.
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Solution: Two pointer approach
    - initialize max_container = 0 and 2 pointer left, right
    - loop until left >= right, compute amount_of_water compare with max_container, and update max_container
    - update pointer with smaller height
Complexity analysis:
    - Time complexity: O(n) - beats 83.66%
    - Space complexity: O(1) - beats 91.63%
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_container = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int amount_of_water = (right - left) * min(height[left], height[right]);
            if (max_container < amount_of_water) max_container = amount_of_water;
            if (height[left] < height[right]) left++;
            else { right--; }
        }

        return max_container;
    }
};