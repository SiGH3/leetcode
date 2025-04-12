#include <iostream>
#include <vector>

using namespace std; 

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
    public:
        ListNode* reverseBetween(ListNode* head, int left, int right) {
            ListNode* dummy = new ListNode(0,head);
            ListNode* start = dummy;
            for(int i=0;i<left-1;i++){
                start = start->next;
            }
    
            ListNode* cur=start->next;
            ListNode* temp;
            ListNode* pre = nullptr;
            for(int i=0;i<right-left+1;i++){
                temp=cur->next;
                cur->next=pre;
                pre=cur;
                cur = temp;
            }
    
            start->next->next = cur;
            start->next = pre;
    
            return dummy->next;
    
        }
    };