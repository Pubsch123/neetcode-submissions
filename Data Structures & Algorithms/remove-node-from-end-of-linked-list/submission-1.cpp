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
        ListNode* temp = head;
        ListNode* ptr = head;
        int i = 0;
        int N = 0;
        while(ptr){
            N++;
            ptr = ptr->next;
        }
        int idx = N-n;
        if(idx == 0)
        return head->next;
        while(temp && i<idx-1)
        {
            i++;
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};
