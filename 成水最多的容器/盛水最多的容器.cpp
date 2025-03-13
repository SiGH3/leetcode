#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        int area =0;
        int a = 0;
        int b = height.size()-1;
        int maxArea = (b-a)*min(height[a],height[b]);
        if(maxArea>=area){
            while(a<b){
                if(height[a]<=height[b]){
                    a+=1;
                    area = (b-a)*min(height[a],height[b]);
                }
                else{
                    b-=1;
                    area=(b-a)*min(height[a],height[b]);
                }
                maxArea=max(maxArea,area);
            }
            
        }
        return maxArea;

    }
};

int main(){
    Solution sol;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<< sol.maxArea(height);
    return 0;
}