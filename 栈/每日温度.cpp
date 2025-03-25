#include<vector>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            vector<int> res(temperatures.size(),0);
            if(temperatures.size()==1) return res;
            stack<int> stk;
            stk.push(0);
            for(int i = 1;i < temperatures.size();i++){
                if(temperatures[i] < temperatures[stk.top()]){
                    stk.push(i);
                }
                else if(temperatures[i] == temperatures[stk.top()]){
                    stk.push(i);
                }
                else{
                    while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                        res[stk.top()]=i-stk.top();
                        stk.pop();
                    }
                    stk.push(i);
                }
            }
            return res;
        }
    };