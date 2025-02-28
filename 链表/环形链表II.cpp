#include<iostream>

using namespace std;

//Definition for singly-linked list.
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
            ListNode* fast = head;
            ListNode* slow = head;
            int x,y,z =0;
            while(fast!=nullptr&&fast->next!=nullptr){
                fast = fast->next->next;
                slow = slow->next;
                if(slow==fast){
                    ListNode* l1 = head;
                    ListNode* l2 = fast;
                    while(l1!=l2){
                        l1=l1->next;
                        l2=l2->next;
                    }
                    return l1;   
                }
            }
            return nullptr;
        }
    };