class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        int cnt = 1;
        ListNode* evenHead = NULL , *evenTail = NULL;
        ListNode* oddHead = NULL , *oddTail = NULL;
        
        if(head == NULL || head -> next == NULL)
            return head;

        while(head != NULL)
        {
            if(cnt % 2 == 0)
            {
                if(evenHead == NULL)
                {
                    evenHead = head;
                    evenTail = head;
                }
                else 
                {
                    evenTail -> next = head;
                    evenTail = evenTail -> next;
                }
            }
            else
            {
                if(oddHead == NULL)
                {
                    oddHead = head;
                    oddTail = head;
                }
                else
                {
                    oddTail -> next = head;
                    oddTail = oddTail -> next;
                }
            }

            head = head -> next;
            cnt++;
        }
        
        oddTail -> next = evenHead;
        evenTail -> next = NULL;
        return oddHead;
    }
};

// #LeetCode Medium way
// T.C = O(N) , S.C = O(1)
