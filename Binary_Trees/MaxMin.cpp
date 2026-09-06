class Solution {
  public:
    int findMax(Node *root) {
        if(root == NULL) return INT_MIN;
        int leftMax = findMax(root->left);
        int rightMax = findMax(root->right);
        return max(root->data,max(leftMax,rightMax));
    }

    int findMin(Node *root) {
        if(root == NULL) return INT_MAX;
        int leftMin = findMin(root->left);
        int rightMin = findMin(root->right);
        return min(root->data,min(leftMin,rightMin));
    }
};
