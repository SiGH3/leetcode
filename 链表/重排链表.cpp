#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() :val(0),next(nullptr) {}
    ListNode(int x) : val(x),next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x),next(next) {}
};

class Solution{
public:
    ListNode* reverseList(ListNode* node){
        ListNode* cur = node;
        ListNode* pre = nullptr;
        ListNode* temp;
        while(cur){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
    void mergeList(ListNode* l1,ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* node = dummy;
        while(l1&&l2){
            node->next = l1;
            l1=l1->next;
            node = node->next;

            node->next = l2;
            l2=l2->next;
            node = node->next;    
            
        }
        node->next=l1?l1:l2;
    }
    void reorderList(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next&&fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* tail = slow->next;
        slow->next = nullptr;
        tail = reverseList(tail);

        mergeList(head,tail);
    }
};