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
int prev = -1;
int ans = INT_MAX;
    int minDiffInBST(TreeNode* root) {
        MinimumDifference(root);
    return ans;
}

    void MinimumDifference(TreeNode* root) {
        if(root == NULL){
            return;
        }

        MinimumDifference(root->left);
        int diff = 0;
        if(prev == -1){
            prev = root->val;
        }
        else{
           diff = abs((root->val) - prev);
            ans = min(ans,diff);
            prev = root->val;
        }
        
        MinimumDifference(root->right);
        
             
        
        
        
    }
};
        
    