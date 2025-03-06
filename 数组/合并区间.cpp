#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        vector<vector<int>> res;
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            if(intervals.size()==0){
                return {};
            }
            sort(intervals.begin(), intervals.end());
            for(int i=0;i<intervals.size();i++){
                int left = intervals[i][0];
                int right = intervals[i][1];
                if(!res.size()||res.back()[1]<left){
                    res.push_back({left,right});
                }
                else{
                    res.back()[1]=max(res.back()[1],right);
                }        
            }
            return res;
        }
        
    };

    // int main(){
    //     Solution solution;
    //     vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};
    //     solution.merge(input);
    //     for(int i=0;i<solution.res.size();i++){
    //         cout << solution.res[i][0] << " " << solution.res[i][1] << endl;
    //     }
        
    // }
