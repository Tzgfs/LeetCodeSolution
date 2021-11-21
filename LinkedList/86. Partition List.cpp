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
    ListNode* partition(ListNode* head, int x) {
        ListNode* biggerNode = new ListNode();
        ListNode* smallNode = new ListNode();
        ListNode* bigHead = biggerNode;
        ListNode* smallHead = smallNode;

        while(head != NULL){
            int val = head->val;

            if(val <= x){
                smallNode->next = head;
                smallNode = smallNode->next;
            }else{
                biggerNode->next = head;
                biggerNode = biggerNode->next;
            }
            head = head->next;
        }

        smallNode->next = bigHead->next;
        biggerNode->next = nullptr;

        return smallHead->next;
    }
};