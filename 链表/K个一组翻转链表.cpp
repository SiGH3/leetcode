#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* node = head;
            for(int i=0;i<k;i++){
                if(node==nullptr){
                    return node;
                }
                node=node->next;
            }
            ListNode* pre = nullptr;
            ListNode* cur = head;
            ListNode* temp;
            for(int i=0;i<k;i++){
                temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            //此时头节点已经换到这组（K个节点为一组）的最后一个，连接下一组
            head->next = reverseKGroup(cur,k);
            return pre;
        }
    };