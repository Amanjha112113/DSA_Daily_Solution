/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL || k == 0)
            return head;

        int count = 1;
        ListNode* tail = head;
        ListNode* copy = head;

        while(tail->next != NULL) {
            tail = tail->next;
            count++;
        }

        ListNode* curr = head;
        ListNode* nex = NULL;

        //rotation is done.
        k = k % count;
        if(k == 0)
            return head;

        // 1 is sub just due to the pointer is in node1 itself and count start form node2
        int times = count - k - 1; // (5 - 2 - 1) = 2 its stops at node3. 
        
        while(times--)
        {
            curr = curr->next; 
        }    
        nex = curr->next;
        curr->next = NULL;

        head = nex;
        tail->next = copy;

        return head;
    }
};