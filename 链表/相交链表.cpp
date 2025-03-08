#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA=0,lenB=0;
        while(curA){
            lenA++;
            curA = curA->next;
        }
        while(curB){
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        //把较长的链表为A，如过B长，AB交换
        if(lenA<lenB){
            swap(lenA,lenB);
            swap(curA,curB);
        }
        int dis=lenA-lenB;
        while(dis--){
            curA=curA->next;
        }
        while(curA!=NULL){
            if(curA == curB){
                return curA;
            }
            curA=curA->next;
            curB=curB->next;
        }
        return NULL;

    }
};