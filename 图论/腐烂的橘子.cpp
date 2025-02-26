#include<vector>
#include<iostream>
#include<queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int fresh = 0;
        queue<pair<int,int>> que;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
                else if(grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }      
        while(fresh!=0 && !que.empty()){
            time++;
            int size = que.size();
            for(int i=0;i<size;i++){
                auto cur = que.front();
                que.pop();
                for(auto dir:dirs){
                    int x = cur.first+dir[0];
                    int y = cur.second+dir[1];
                    if(x<0||x>=grid.size()||y<0||y>=grid[0].size()){
                        continue;
                    }
                    if(grid[x][y]==1){
                        fresh--;
                        grid[x][y]=2;
                        que.push({x,y});
                    }
                }
            }
            
        }
        return fresh == 0 ? time : -1;
    }
};