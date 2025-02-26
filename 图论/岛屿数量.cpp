#include<vector>
#include<iostream>

using namespace std;

class Solution {
    public:
        int res = 0;
        vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0}};
        void dfs(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
            for(auto dir:dirs){
                int newx = x+dir[0];
                int newy = y+dir[1];
                //判断newx和newy是否越界
                if(newx<0||newx>=grid.size()||newy<0||newy>=grid[0].size()){
                    continue;
                }
                if(!visited[newx][newy]&&grid[newx][newy]=='1'){  //节点未访问过 且 节点是岛屿
                    visited[newx][newy]=true;
                    dfs(grid,visited,newx,newy);
                }
            }
        }
        int numIslands(vector<vector<char>>& grid) {
            vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
            for(int i=0;i<grid.size();i++){
                for(int j=0;j<grid[0].size();j++){
                    if(!visited[i][j] && grid[i][j]=='1'){
                        res++;
                        visited[i][j]=true;
                        dfs(grid,visited,i,j);
                    }
                }
            }
            return res;
        }
    };