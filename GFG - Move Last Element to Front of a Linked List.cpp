class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(head->next == NULL) return head;
        
        ListNode* curr = head;
        
        while(curr->next != NULL && curr->next->next != NULL) {
            curr = curr->next;
        }
        
        ListNode* newNode = curr->next;
        curr->next = NULL;
        
        newNode->next = head;
        return newNode;
        
    }
};

// T.C = O(N) , S.C = O(1)
// #chindii
