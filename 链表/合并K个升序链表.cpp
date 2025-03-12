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
        ListNode* merge(ListNode* l1,ListNode* l2){
            ListNode* dummy = new ListNode(0);
            ListNode* cur = dummy;
            while(l1&&l2){
                if(l1->val<l2->val){
                    cur->next = l1;
                    l1= l1->next;
                }
                else{
                    cur->next =l2;
                    l2= l2->next;
                }
                cur=cur->next;
            }
            cur->next = l1? l1:l2;
            return dummy->next;
        }
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            if(lists.empty()) return nullptr;
            ListNode* res = nullptr;
            for(int i =0;i< lists.size();i++){
                res = merge(res,lists[i]);
            }
            return res;
        }
    };
    