class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;
        ans.push_back(root->val);
        dfs(root->left,ans);
        dfs(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};
