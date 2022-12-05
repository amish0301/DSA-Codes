class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        if(head -> next == NULL) return head;

        ListNode* slow = head , *fast = head;

        while(fast != NULL && fast->next != NULL && fast->next->next != NULL) {

            fast = fast->next->next;
            slow = slow->next;
        }

        if(fast->next == NULL) return slow;
        else return slow->next;
    }
};

// #LeetCode Easy Way
// T.C = O(N/2) = O(N) , S.C = O(1)

// #EzPz
