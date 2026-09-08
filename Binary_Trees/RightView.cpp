class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void preorder(TreeNode* root, int lvl, vector<int>& ans){
        if(root == NULL) return;
        ans[lvl] = root->val;
        preorder(root->left,lvl+1,ans);
        preorder(root->right,lvl+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        int n = levels(root);
        vector<int> ans(n);
        preorder(root,0,ans);
        return ans;
    }
};
