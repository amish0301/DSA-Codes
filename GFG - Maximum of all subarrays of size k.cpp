// MOST POPULAR Q.

class Solution
{
  public:
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        int i = 0 , j = 0;
        deque<int> q;
        
        while(j < n) {
            
            while(!q.empty() && q.back() < arr[j]) q.pop_back();
            q.push_back(arr[j]);
            
            if(j-i+1 < k) j++;
            else if(j - i + 1 == k) {
                
                // store the ans and check it front is not the max ele. along the window           
                ans.push_back(q.front());
                if(q.front() == arr[i]) q.pop_front();
              
                i++;
                j++;
            }
        }
        return ans;
    }
};

/* 
Concept Used : Sliding Window
T.C = O(N) , Auxiliary Space : O(K)
Here we've used deque insted of queue bcoz we need to pop ele. from both the end of Queue.
*/


/*
Step 1 : check every a[i] ele. it's smaller then the top of queue then don't need to add into queue bcoz eventually we need max. ele. and if window length is less then K then increment ptr.

Step 2 : once we reached the window size we need to perform 2 operation:
         1] store the ans. which is present at front side of Queue.
         2] check that whatever no. we'll removing is not the Max No. through out the window if it's max no. then we need consider max. which is next to that value in             window eg. 3 2 1 -> Suppose window here we can see 3 is Largest in window and we'll gonna remove this ele. so before removing it we just consider our next             max. no. is to 2
*/
