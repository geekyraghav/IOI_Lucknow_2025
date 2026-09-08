class Solution {
public:
    // TreeNode* invertTree(TreeNode* root) {
    //     if(root == NULL) return root;
    //     TreeNode* temp = invertTree(root->left);
    //     root->left = invertTree(root->right);
    //     root->right = temp;
    //     return root;
    // }

    void invert(TreeNode* root){
        if(root == NULL) return;
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        invert(root->left);
        invert(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};
