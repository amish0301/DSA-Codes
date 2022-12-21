class Solution{
    
public:
    Node* sortList(Node* head)
    {
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr != NULL) {
            
            if(curr->data < 0 && prev != NULL) {
                
                prev->next = curr -> next;
                curr -> next = head;
                head = curr; 
                curr = prev -> next;
                
            }else{
                
                prev = curr;
                curr = curr->next;
                
            }
            
        }
        return head;
    }
};

// #GFG Easy Way
// T.C = O(N) , S.C =  O(1)
