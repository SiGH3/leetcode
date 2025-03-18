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
    //归并排序

    ListNode* mergeList(ListNode* l1,ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while(l1&&l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1? l1:l2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* pre=nullptr;
        while(fast&&fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr; //从中间断开链表，分为两个链表left和right，头节点分别为head和slow

        //递归排序两个链表
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);

        return mergeList(left,right);

    }

    ListNode* readList(int n){
        if(n==0){
            return nullptr;
        }
        int x;
        cin >> x;
        ListNode* head = new ListNode(x);
        ListNode* cur = head;
        for(int i=1;i<n;i++){
            cin >> x;
            cur->next = new ListNode(x);
            cur = cur->next;
        }
        return head;
    }

    void printList(ListNode* head){
        while(head){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};