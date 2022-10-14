class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow = head , *fast = head->next;

        if(head == NULL || head->next == NULL) return NULL;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow -> next;
            fast = fast->next->next;
        }

        // if we reached here means we are at the position before the node which we want to delete
        slow->next = slow->next->next;
        return head;
    }
};

// T.C = O(N) , S.C = O(1)
// Level : Medium
