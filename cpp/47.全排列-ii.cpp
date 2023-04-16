/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
   public:
    vector<vector<int>> result;
    void func(vector<int> &nums, vector<int> &current, vector<bool> &nums1) {
        if (current.size() == nums1.size())
            result.push_back(current);
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (nums1[i]) {
                    if (i > 0 && nums[i] == nums[i - 1] && nums1[i - 1])  // 除重！！
                        continue;
                    current.push_back(nums[i]);
                    nums1[i] = false;
                    func(nums, current, nums1);
                    nums1[i] = true;
                    current.pop_back();
                }
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.size() == 0)
            return {};
        else if (nums.size() == 1)
            return {{nums[0]}};
        else {
            vector<bool> nums1(nums.size(), true);
            vector<int> current;
            sort(nums.begin(), nums.end());
            func(nums, current, nums1);
            return result;
        }
    }
};
// @lc code=end
