#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
            int longestValidParentheses(string s) {
                int res=0;
                int n = s.size();
                vector<int> dp(n,0);
                //dp[i]表示到i位置为止，有效括号的长度
                for(int i=1;i<n;i++){
                    if(s[i-1]=='(' && s[i]==')'){
                        dp[i]=(i>=2?dp[i-2]:0)+2;
                    }
                    else if(s[i-1]==')'&& s[i]==')'){
                        if(i - dp[i - 1] > 0 && s[i-dp[i-1]-1]=='('){
                            dp[i]=((i-dp[i-1])>=2?dp[i-dp[i-1]-2]:0)+dp[i-1]+2;
                        }
                    }
                    res = max(res,dp[i]);
                }    
                return res;
            }
    };