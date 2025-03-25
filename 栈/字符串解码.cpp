#include <iostream>
#include <string>
#include <stack>
#include<vector>

using namespace std;

class Solution {
    public:
        string decodeString(string s) {
            stack<string> strStack;
            stack<int> numStack;
            string res;
            int num =0;

            for(auto c:s){
                if(isdigit(c)){
                    num = num*10+(c-'0');
                }
                else if(c=='['){
                    numStack.push(num);
                    num=0;
                    strStack.push(res);
                    res = "";
                }
                else if(c==']'){
                    int repeat = numStack.top();
                    numStack.pop();
                    string temp = strStack.top();
                    strStack.pop();

                    for(int i=0;i<repeat;i++){
                        temp+=res;
                    }
                    res= temp;
                }
                else{
                    res+=c;
                }

            } 
            return res;
        }
    };



//题解
class Solution {
    public:
        string decodeString(string s) {
            stack<char> stk1;
            stack<char> stk2;
    
            for(int i = 0; i < s.size(); i++) {
                if(s[i] == ']') {
                    // 转换
                    
                    while(stk1.top() != '[') {
                        stk2.push(stk1.top());
                        stk1.pop();
                    }
                    stk1.pop();
    
                    // 记录stk2没有插入数字之前的长度
                    int srcLength = stk2.size();
                    // 此处模拟n的操作也很需要
                    while(!stk1.empty() && stk1.top() >= '0' && stk1.top() <= '9') {
                        stk2.push(stk1.top());
                        stk1.pop();
                    }
                    int digitLength = stk2.size() - srcLength;
                    string digit(digitLength, ' ');
                    for(int i = 0; i < digitLength; i++) {
                        digit[i] = stk2.top();
                        stk2.pop();
                    }
                    int n = stoi(digit);
    
    
                    int length = stk2.size();
                    string s(length, ' ');
                    for(int j = 0; j < length; j++) {
                        s[j]= stk2.top();
                        stk2.pop();
                    }
                    for(int j = 0; j < n; j++) {
                        for(int k = 0; k < length; k++) {
                            stk1.push(s[k]);
                        }
                    }
                } else {
                    stk1.push(s[i]);
                }
            }
    
            std::string res(stk1.size(), ' ');
            for(int i = stk1.size() - 1; i >= 0; i--) {
                res[i] = stk1.top();
                stk1.pop();
            }
            return res;
        }
    };