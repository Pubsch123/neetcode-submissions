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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* node = head;
        ListNode* prev = nullptr;
        while(node!=NULL){
            ListNode* ptr = node->next;
            node->next = prev;
            prev = node;
            node = ptr;
        }
        return prev;
    }
};
