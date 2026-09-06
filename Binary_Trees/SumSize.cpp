class Solution {
  public:
    int sumBT(Node* root) {
        if(root == NULL) return 0;
        return root->data + sumBT(root->left) + sumBT(root->right);
    }
    int getSize(Node* root) {
        if(root == NULL) return 0;
        return 1 + getSize(root->left) + getSize(root->right);
    }
};
