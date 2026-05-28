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
    void reverse(ListNode* head, int times) 
    {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(times--)
        {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        }
        return;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) 
            return head;

        ListNode* left = head;
        ListNode* prevleft = NULL;
        ListNode* res = NULL;
        ListNode* right;

        while(true) 
        {
            right = left; // due to not fixed 2 loop

            for(int i = 0; i < k-1; i++) {

                if(right == NULL)
                    break;
                right = right->next;
            }

            if(right) 
            {
                ListNode* nextleft = right->next;
                reverse(left, k);

                if(prevleft) 
                    prevleft->next = right;
                prevleft = left;

                if(res == NULL) 
                    res = right;
                
                left = nextleft;
            }
            else
            {
                if(prevleft) 
                    prevleft->next = left;
                
                if(res == NULL)
                    res = left;

                break;
            }
        }
        return res;
    }
};