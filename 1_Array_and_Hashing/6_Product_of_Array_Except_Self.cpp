/*
Given an integer array nums, return an array answer such that answer[i]
is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
    Input: nums = [1,2,3,4]
    Output: [24,12,8,6]
*/

#include <iostream>
#include <vector>
using namespace std;


/*
My Solution explanation - Prefix and Postfix multiple
    - Divide array to prefix and postfix part of specific element are pointed to 
    - Initialize result and pre, pos variable with value 1 fill all
    - Use two loop with opposite direction to calculate pre and pos, then multiple to corresponding element

Complexity analysis:
    - Time complexity: O(n + n) = O(n) - beats 88.99%
    - Space complexity: O(1) - beats 54.34%
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result(nums.size(), 1);
        int pre = 1, pos = 1;
        // prefix multiple
        for (int i = 1; i < nums.size(); i++) {
            pre *= nums[i - 1];
            result[i] *= pre; 
        }
        // posfix multiple
        for (int i = nums.size() - 2; i >= 0; i--) {
            pos *= nums[i + 1];
            result[i] *= pos;
        }

        return result;
    }
};

/*
Other approach solution: optimize the process - 4ms runtime
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int arr1[len], arr2[len];
        arr1[len - 1] = 1; arr2[0] = 1;
        
        for (int i = len - 2; i >= 0; i--)
            arr1[i] = nums[i + 1] * arr1[i + 1];
        for (int i = 1; i < len; i++)
            arr2[i] = nums[i - 1] * arr2[i - 1];
        
        vector<int> result;
        for (int i = 0; i < len; i++)
            result.push_back(arr1[i] * arr2[i]);
        
        return result;
    }
};
