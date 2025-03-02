#include<vector>
#include<iostream>
#include<stack>

using namespace std;

class Solution {
    public:
        int largestRectangleArea(vector<int>& heights) {
            int res=0;
            stack<int> st;
            //数组头尾加上0，为了避免数组本来就是按照从大到小的顺序排列    
            //走不到下面第三种情况中计算结果的那一步
            //如果是降序排列，最后栈里面弹出最后一个数就变成空栈了，会跳过计算结果的逻辑导致结果为0
            heights.insert(heights.begin(),0);
            heights.push_back(0);

            st.push(0);

            for(int i=1;i<heights.size();i++){
                if(heights[i] > heights[st.top()]){
                    st.push(i);
                }
                else if(heights[i] == heights[st.top()]){
                    st.pop();
                    st.push(i);
                }
                else{
                    while(!st.empty() && heights[i] < heights[st.top()]){
                        int mid = st.top();
                        st.pop();
                        if(!st.empty()){
                            int left = st.top();
                            int right = i;
                            int w = right-left-1;
                            int h = heights[mid];
                            res = max(res, w*h);
                        }
                    }
                    st.push(i);
                }
            }
            return res;
        }
    };