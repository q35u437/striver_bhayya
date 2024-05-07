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
    ListNode *reverse(ListNode *head){
        ListNode *current = head;
        ListNode *previous = NULL;
        while(current){
            ListNode* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        return previous;
    }
    ListNode* doubleIt(ListNode* head) {
        ListNode *reversed = reverse(head);
        ListNode *current = reversed;
        ListNode *previous = NULL;
        int carry = 0;
        while(current){
            int value = carry + 2 * current->val;
            current->val = value % 10;
            carry = value / 10;
            previous = current;
            current = current->next;
        }
        if(carry){
            previous->next = new ListNode(1);
        }
        head = reverse(reversed);
        return head;
    }
};
