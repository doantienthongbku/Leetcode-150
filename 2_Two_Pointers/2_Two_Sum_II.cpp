/*

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
find two numbers such that they add up to a specific target number.
Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

Example 1:
    Input: numbers = [2,7,11,15], target = 9
    Output: [1,2]
    Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
*/

#include <iostream>
#include <vector>
using namespace std;

/*
Solution: two pointers approach
    - Using 2 pointers loop toward each other until they meet in the middle of string
    - If sum of 2 numbers in 2 pointers equal to target, return the result
    - Else, increase left pointer if sum less than target and decrease right pointer if sum larger than target

Complexity analysis:
    - Time complexity: O(n) - beats 68.67%
    - Space complexity: O(1) - beats 79.63%
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;

        while (i < j) {
            int num = numbers[i] + numbers[j]; 
            if (num == target) {
                return {i+1, j+1};
            } else if (num < target) i++;
            else j--;
        }

        return { };
    }
};