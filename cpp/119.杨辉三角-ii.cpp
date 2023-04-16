/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
   public:
    vector<int> getRow(int rowIndex) {
        vector<int> nums(rowIndex + 1);
        nums[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                nums[j] += nums[j - 1];
            }
        }
        return nums;
    }
};
// @lc code=end
