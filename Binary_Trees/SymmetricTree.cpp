class Solution {
public:
    bool areInverts(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return true;
        if(p == NULL || q==NULL) return false;
        if(p->val != q->val) return false;
        return areInverts(p->left,q->right) && areInverts(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return areInverts(root->left, root->right);
    }

    // void invert(TreeNode* root){
    //     if(root == NULL) return;
    //     TreeNode* temp = root->left;
    //     root->left = root->right;
    //     root->right = temp;
    //     invert(root->left);
    //     invert(root->right);
    // }
    // bool isSameTree(TreeNode* p, TreeNode* q) {
    //     if(p==NULL && q==NULL) return true;
    //     if(p == NULL || q==NULL) return false;
    //     if(p->val != q-> val) return false;
    //     return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    // }
    // bool isSymmetric(TreeNode* root) {
    //     invert(root->right);
    //     bool ans = isSameTree(root->left,root->right);
    //     invert(root->right);
    //     return ans;
    // }
};
