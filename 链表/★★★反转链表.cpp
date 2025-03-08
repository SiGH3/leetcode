#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int x):val(x),next(nullptr){}
    ListNode(int x, ListNode* next):val(x),next(next){}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* temp;
        ListNode* pre = NULL;
        ListNode* cur = head;
        while(cur){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    void printList(ListNode* head){
        while(head){
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

    ListNode* readList(int n){
        if(n==0){
            return nullptr;
        }
        int x;
        cin >> x;
        ListNode* head = new ListNode(x);
        ListNode* cur = head;
        for(int i = 1;i<n;i++){
            cin >> x;
            cur->next = new ListNode(x);
            cur = cur->next;
        }
        return head;
    }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    ListNode* head = sol.readList(n);
    head = sol.reverseList(head);
    sol.printList(head);

    return 0;
}