/*
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*/

bool compare(ListNode* head1, ListNode* head2){
        while(head1 and head2){
            if(head1->val != head2->val) return false;
            head1 = head1->next;
            head2 = head2->next;
        }
        if(!head1 and !head2) return true;
        return false;
    }
    
    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* res = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
    }
    
    
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next == NULL) return true;
        ListNode *hare = head, *tortoise = head, *prev = NULL;
        while(hare and hare->next){
            hare = hare->next->next;
            prev = tortoise;
            tortoise = tortoise->next;
        }
        ListNode *head1 = head, *head2 = NULL; 
        prev->next = NULL;
        if(hare and hare->next==NULL){ //odd length
            head2 = tortoise->next;
            tortoise->next = NULL;
        } else { //even length
            head2 = tortoise;
        }   
        head2 = reverse(head2);
        return compare(head1, head2);
    }
