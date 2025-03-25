#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    bool backtracking(vector<int>& planks, int index, vector<int>& sides, int sideLen){
        if(index == planks.size()){
            for(int i=0;i<4;i++){
                if(sides[i]!=sideLen){
                    return false;
                }
            }
            return true;    
        }

        for(int i=0;i<4;i++){
            if(sides[i]+planks[index]<=sideLen){
                sides[i]+=planks[index];
                if(backtracking(planks,index+1,sides,sideLen)){
                    return true;
                }
                sides[i]-=planks[index];
            }
        }
        return false;
    }


    bool canFormSquare(vector<int>& planks) {
        // write code here
        int sum = 0;
        for(auto plank:planks){
            sum+=plank;
        }
        if(sum%4!=0){
            return false;
        }

        int sideLen = sum/4;
        vector<int> sides(4,0);

        return backtracking(planks,0,sides,sideLen);
    }
};