#include<iostream>
#include<vector>

using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x,ListNode* next):val(x),next(next) {}
};

class Solution{
public:
    bool isPalindrome(ListNode* head){
        ListNode* cur = head;
        vector<int> vec;
        if(cur){
            vec.push_back(cur->val);
            cur= cur->next;
        }
        for(int i = 0, j = vec.size()-1;i<j;i++,j--){
            if(vec[i]!=vec[j])
                return false;
        }
        return true;
    }
};