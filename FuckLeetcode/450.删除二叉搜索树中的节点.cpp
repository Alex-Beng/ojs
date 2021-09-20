/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void delNode(TreeNode* &root, int key) {
        if (root==nullptr) {
            return;
        }
        if (key < root->val) {
            delNode(root->left, key);
        }
        else if (key > root->val) {
            delNode(root->right, key);
        }
        else {
            // del root
            if (root->left!=nullptr && root->right!=nullptr) {
                auto t_ptr = root->right;
                while (t_ptr->left != nullptr) {
                    t_ptr = t_ptr->left;
                }
                root->val = t_ptr->val;
                
                delNode(root->right, t_ptr->val);
            }
            else {
                auto t_ptr = root;
                if (root->left==nullptr) {
                    root = root->right;
                }
                else {
                    root = root->left;
                }
                delete t_ptr;
            }
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        delNode(root, key);
        return root;
    }
};
// @lc code=end

