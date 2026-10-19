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
    typedef unsigned long long ll;
public:
    int widthOfBinaryTree(TreeNode* root) {
    queue<pair<TreeNode*,ll >> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (q.size() > 0) {
        int currLevelSize = q.size();
        ll stIdx = q.front().second;
        ll endIdx = q.back().second;

        maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

        for (int i = 0; i < currLevelSize; i++) {
            TreeNode* curr = q.front().first;
            ll index = q.front().second;
            q.pop();

            if (curr->left) {
                q.push({curr->left, index * 2 + 1});
            }

            if (curr->right) {
                q.push({curr->right, index * 2 + 2});
            }
        }
    }

    return maxWidth;
}
};