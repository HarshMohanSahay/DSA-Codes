
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int maxWidth = 0;

        while (!q.empty()) {
            int currLevelSize = q.size();

            long long miniindex = q.front().second;
            long long stIdx = q.front().second;
            long long endIdx = q.back().second;

            maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

            for (int i = 0; i < currLevelSize; i++) {
                TreeNode* curr = q.front().first;
                long long index = q.front().second - miniindex;
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
