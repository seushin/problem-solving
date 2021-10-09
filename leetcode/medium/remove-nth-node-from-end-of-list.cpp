#include <cstdio>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* prev = head;
        ListNode* nth = head;
        int len = 1;

        while (curr != NULL)
        {
            if (n < len)
            {
                prev = nth;
                nth = nth->next;
            }
            curr = curr->next;
            len++;
        }
        if (nth == head)
            return head->next;
        prev->next = nth->next;
        return head;
    }
};
