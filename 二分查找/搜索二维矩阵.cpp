#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix,int target){
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0,high = m*n-1;
        while(low<=high){
            int mid = (high-low)/2+low;
            int x = matrix[mid/n][mid%n];
            if(x<target){
                low=mid+1;
            }
            else if(x>target){
                high=mid-1;
            }
            else{
                return true;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix,int target){
        //upper_bound(first, last, value, comp) 
        //在 已排序 的范围 [first, last) 中 
        //查找第一个 满足 comp(value, element) == true 的 element，并返回其 迭代器。
        //如果找不到这样的元素，就返回 last。

        //upper_bound的返回类型是vector<vector<int>>::iterator
        auto row = upper_bound(matrix.begin(),matrix.end(),target,[](const int b,const vector<int>& a){
            return b<a[0];
        });
        //lambda语法：[捕获列表](参数列表) -> 返回类型 { 函数体 };
        //作为 upper_bound 的 自定义比较函数。
        //比较 target (b) 是否小于 a[0]（当前行的第一个元素）。
        //upper_bound 通过它 找到第一行 a[0] > target 的行。
        if (row==matrix.begin()){
            return false;  //如果定位到的行就是第一行，target比矩阵所有元素都小
        } 
        --row;
        return binary_search(row->begin(),row->end(),target);
    }
};




