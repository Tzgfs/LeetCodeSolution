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
#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = new ListNode();
        ListNode* slow = new ListNode();
        fast = head;
        slow = head;

        while( fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow){
                ListNode *metNode = slow;
                ListNode *newHead = head;
                
                while(metNode != newHead)
                {
                    metNode = metNode->next;
                    newHead = newHead->next;
                }

                return metNode;
            }
        }

        return NULL;
    }
};