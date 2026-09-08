class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;
        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        dfs(root,ans);
        return ans[k-1];
    }
};
