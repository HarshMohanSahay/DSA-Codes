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
    int currval =0;
    int currfrq = 0;
    int maxfreq = 0;
    vector<int>result;

    void inorder(TreeNode* root ){
        if(!root)return ;
        inorder(root->left);

        if(root->val==currval){
            currfrq++;
        }
        else{
            currval = root->val;
            currfrq = 1;
        }
        if(currfrq>maxfreq){
            result = {};
            maxfreq = currfrq;
        }
        if(currfrq == maxfreq){
            result.push_back(currval);
        }

        inorder(root->right);

    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return result;
    }
};