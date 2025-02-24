#include <iostream>
#include <vector> 
#include <string>

class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.size();
            vector<vector<bool>> dp(n,vector<bool>(n,false));
            int maxLen = 0;
            int left = 0;
            for(int i = n-1;i>=0;i--){
                for(int j = i;j<n;j++){
                    if(s[i]==s[j]){
                        if(j-i<=1){
                            dp[i][j]=true;
                        }
                        else if(dp[i+1][j-1]){
                            dp[i][j]=true;
                        }
                    }
                    if(dp[i][j]&&j-i+1>maxLen){
                        maxLen = j-i+1;
                        left = i;
                    }
                }
                
            }
           return s.substr(left,maxLen); 
        }
    };