//
// Created by Administrator on 25-3-23.
//

//
// Created by Administrator on 25-3-23.
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;



// 层次遍历函数
vector<vector<int> > rerankItems(vector<vector<int> >& items) {
    // write code here
   
   vector<vector<int>> remain;
   vector<vector<int>> zeroRemain;
   
   for(const auto& item:items){
       if(item[1]>0){
           remain.push_back(item);
       }
       else{
           zeroRemain.push_back(item);
       }
   }
   
   remain.insert(remain.end(),zeroRemain.begin(),zeroRemain.end());
   return remain;

}



