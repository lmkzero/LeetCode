/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;
        TreeNode *p=root;
        while(!s.empty()||p!=nullptr){
            if(p!=nullptr){
                s.push(p);
                p=p->left;
            }else{
                p=s.top();
                s.pop();
                result.push_back(p->val);
                p=p->right;
            }
        }
        return result;
    }
};
// @lc code=end

