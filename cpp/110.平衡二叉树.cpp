/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return balancedHeight(root)>=0;
    }
    int balancedHeight(TreeNode *root){
        if(root==nullptr){
            return 0;
        }
        int left=balancedHeight(root->left);
        int right=balancedHeight(root->right);
        if(left<0||right<0||abs(left-right)>1){
            return -1;
        }
        return max(left,right)+1;
    }
};
// @lc code=end

