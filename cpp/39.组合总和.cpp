/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
   private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;

   public:
    void DFS(int start, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);
            DFS(i, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);

        return res;
    }
};
// @lc code=end
