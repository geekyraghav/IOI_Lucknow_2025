class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        int lenA = 0;
        while(tempA != NULL){
            lenA++;
            tempA = tempA->next;
        }
        ListNode* tempB = headB;
        int lenB = 0;
        while(tempB != NULL){
            lenB++;
            tempB = tempB->next;
        }

        tempA = headA;
        tempB = headB;

        if(lenA > lenB){
            for(int i=1;i<=lenA-lenB;i++){
                tempA = tempA->next;
            }
        }
        else{
            for(int i=1;i<=lenB-lenA;i++){
                tempB = tempB->next;
            }
        }
        
        while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
        }
        return tempA;
    }
};
