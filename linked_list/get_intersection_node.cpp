//
// Created by 姚轩 on 2023/4/6.
//
#include "common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA or !headB){
            return nullptr;
        }
        ListNode *cur_ptr = headA;
        unordered_set<ListNode *> node_set;
        while (cur_ptr){
            node_set.insert(cur_ptr);
            cur_ptr = cur_ptr->next;
        }
        cur_ptr = headB;
        while (cur_ptr){
            if(node_set.find(cur_ptr) != node_set.end()){
                return cur_ptr;
            }
            else{
                cur_ptr = cur_ptr->next;
            }
        }
        return nullptr;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA or !headB){
            return nullptr;
        }
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        while (ptrA != ptrB){
            // there isn't intersection
            if ((ptrA->next == nullptr) and (ptrB->next == nullptr)) return nullptr;
            ptrA = (ptrA->next == nullptr) ? headB : ptrA->next;
            ptrB = (ptrB->next == nullptr) ? headA : ptrB->next;
        }
        return ptrA;
    }
};

int main() {
}