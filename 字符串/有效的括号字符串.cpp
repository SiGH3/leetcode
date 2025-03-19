#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
//两个栈，一个存放（，一个存放*
//优先）与（匹配，然后）和*匹配
    bool checkValidString(string s) {
        stack<int> leftst;
        stack<int> starst;
        int n = s.size();
        for(int i =0;i<n;i++){
            if(s[i]=='('){
                leftst.push(i);
            }
            else if(s[i]=='*'){
                starst.push(i);
            }
            //如果是），先看有没有（与之匹配，再看有没有*与之匹配
            else{
                if(!leftst.empty()){
                    leftst.pop();
                }
                else if(!starst.empty()){
                    starst.pop();
                }
                else{
                    return false;
                }
            }
        }
        //如果遍历完字符串后（栈和*栈都不空，则将*视为）与（匹配
        //要求*的索引比（的索引大，即*在（的右边
        while(!leftst.empty()&&!starst.empty()){
            int leftIndex = leftst.top();
            leftst.pop();
            int starIndex = starst.top();
            starst.pop();
            if(leftIndex>starIndex){
                return false;
            }
        }
        //结算（栈和*栈
        //*栈如果还有剩余可以视为空字符串，所以只需要考虑（栈
        //如果（栈空了，说明匹配成功
        return leftst.empty();
    }
};    