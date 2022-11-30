class Solution{ 
public:

    Node* reverseList(Node* head) {
        
        Node* prev = NULL , *forward = NULL;
        
        while(head != NULL) {
            
            forward = head->next;
            head->next = prev;
            
            prev = head;
            head = forward;
            
        }
        
        return prev;
    }
    
  
void reorderList(Node* head) {
        
    if(head -> next != NULL) {
            
        // fiding mid ele. of ll
        Node* slow = head , *fast = head , *prev = NULL;
        
        while(fast != NULL && fast->next != NULL) {
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        prev->next = NULL;
        
        
        Node* reverseHead = reverseList(slow);
        Node* mainListHead = head , *revListHead = reverseHead;
        
        while(mainListHead != NULL) {
            
            Node* mainForward = mainListHead->next;
            Node* revForward = revListHead->next;
            
            mainListHead->next = revListHead;
            if(mainForward != NULL) revListHead->next = mainForward;
            
            mainListHead = mainForward;
            revListHead = revForward;
        }
        
        }
    }
};

// #GFG Hard Way
// T.C = O(N) , S.C = O(1)

// Most of the time LinkedList Q. are based on Implementive/Constructive //
