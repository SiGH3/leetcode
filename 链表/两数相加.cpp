#include<iostream>
#include<list>

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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* dummyHead = new ListNode(0);  //虚拟头节点
            ListNode* cur = dummyHead;
            int carry = 0;  //进位
            while(l1||l2||carry!=0){
                int x = l1?l1->val:0;
                int y = l2?l2->val:0;
                int sum = x+y+carry;
                carry=sum/10;
                cur->next = new ListNode(sum%10);
                cur=cur->next;
                if (l1!=NULL) {
                    l1 = l1->next;
                }
                if (l2!=NULL) {
                    l2 = l2->next;
                }

            }
            return dummyHead->next;

        }
    };