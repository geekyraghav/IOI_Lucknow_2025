class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        while(q.size() > 0){
            Node* front = q.front();
            q.pop();
            ans.push_back(front->data);
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
        }
        return ans;
    }
};
