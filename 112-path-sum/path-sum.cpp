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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        bool result = false;
        int sum = 0;
        hasPathSumHelper(root, targetSum, sum, result);
        return result;
    }

    void hasPathSumHelper(TreeNode* root, int targetSum, int& sum, bool& result) {
        if (root == nullptr) {
            return;
        }

        sum += root->val;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == targetSum) {
                result = true;
                return;
            }
        }


        hasPathSumHelper(root->left, targetSum, sum, result);
        hasPathSumHelper(root->right, targetSum, sum, result);

        sum -= root->val;

    }
};