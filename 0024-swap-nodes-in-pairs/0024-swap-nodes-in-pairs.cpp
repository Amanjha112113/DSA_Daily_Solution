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
            ListNode* nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
        }
        return;
    }

    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;

        ListNode* left = head;
        ListNode* prevleft = NULL;
        ListNode* res = NULL;
        ListNode* right; 
        int size = 2;

        while(true) {
            for(int i = 0; i < (size - 1); i++) 
            {
                right = left;
                if(right == NULL)
                    break;
                right = right->next;
            }

            if(right) 
            {  // left right mil chuka hea ji

                ListNode* nextleft = right->next;
                reverse(left, size);

                if(prevleft) 
                    prevleft->next = right;
                prevleft = left;

                if(res == NULL)
                    res = right;

                left = nextleft;
            }
            else  // jahtam hea sab
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