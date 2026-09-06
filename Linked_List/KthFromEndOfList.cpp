class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        Node* slow = head;
        Node* fast = head;
        for(int i=1;i<=k;i++){
            if(fast == NULL) return -1;
            fast = fast->next;
        }
        while(fast != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        return slow->data;
    }
};
