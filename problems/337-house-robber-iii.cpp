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
    pair<int, int> solve(TreeNode* node){
        if(node == NULL)
            return make_pair(0, 0);

        // taking left and not taking left
        pair<int, int> left = solve(node->left);
        // taking right and not taking right
        pair<int, int> right = solve(node->right);
        // rob this, have to skip next
        int rob = left.second + right.second;
        // not rob this, can skip next or take next
        int notRob = max(left.second, left.first) + max(right.second, right.first);
        return make_pair(rob + node->val, notRob);
    }
    int rob(TreeNode* root) {
        pair<int, int> answer = solve(root);
        return max(answer.first, answer.second);
    }
};