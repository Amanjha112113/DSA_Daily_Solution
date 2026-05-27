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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* curr = head;
        int len = 0;

        while(curr != NULL) {
            curr = curr->next;
            len++;
        }

        int toreach = len - n;

        if(toreach == 0) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        curr = head;
        int i = 1;

        while(i < toreach) {
            curr = curr->next;
            i++;
        }

        ListNode* del = curr->next;
        curr->next = del->next;
        delete del;

        return head;
    }
};