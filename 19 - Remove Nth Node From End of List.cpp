class Solution {
private:
    int getlen(ListNode* head)
    {
        ListNode* curr = head;
        int len = 0;
        while(curr != NULL)
        {
            len++;
            curr = curr -> next;
        }
        return len;
    }
  
  
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        // find len
        int len = getlen(head);
        
        if(len == n)return head -> next;
        
        // traverse till len-n node
        ListNode* curr = head;
        int pos = 1;
        while(curr != NULL && pos < (len-n))
        {
            pos++;
            curr = curr -> next;
        }
        
        curr -> next = curr -> next -> next; 
        return head;
    }
};

/*
Q. Remove the Nth Node from End of the List.

T.C = O(N) , S.C = O(1)
*/
