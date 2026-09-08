class Solution {
  public:
    int levels(Node* root){
        if(root == NULL) return 0;
        return 1 + max(levels(root->left),levels(root->right));
    }
    void preorder(Node* root, int lvl, vector<int>& ans){
        if(root == NULL) return;
        if(ans[lvl] == -1) ans[lvl] = root->data;
        preorder(root->left,lvl+1,ans);
        preorder(root->right,lvl+1,ans);
    }
    vector<int> leftView(Node *root) {
        int n = levels(root);
        vector<int> ans(n,-1);
        preorder(root,0,ans);
        return ans;
    }
};
