class Solution {
public:
    void dfs(TreeNode* root, vector<int>& ans) {
        if(root == NULL) return;
        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> ans;
        dfs(root,ans);
        int n = ans.size();
        for(int i=0;i<n-1;i++){
            if(ans[i] >= ans[i+1]) return false;
        }
        return true;
    }
};
