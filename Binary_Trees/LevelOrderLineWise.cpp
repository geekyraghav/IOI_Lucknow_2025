class Solution {
public:
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>> ans(n, vector<int>(0));
        queue<pair<TreeNode*,int>> q;
        if(root != NULL) q.push({root,0});
        while(q.size() > 0){
            pair<TreeNode*,int> front = q.front();
            q.pop();
            TreeNode* node = front.first;
            int lvl = front.second;
            ans[lvl].push_back(node->val);
            if(node->left != NULL) q.push({node->left,lvl+1});
            if(node->right != NULL) q.push({node->right,lvl+1});
        }
        return ans;
    }
};
