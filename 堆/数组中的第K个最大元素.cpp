#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

//最大根堆

class Solution {
    public:
        void maxHeapify(vector<int>& a, int i,int heapSize){
            int l = i*2+1, r = i*2+2;  //i为完全二叉树的某个父节点，它的左右节点分别为l，r
            int largest = i;  //将父节点初始化为最大
            if(l<heapSize && a[l] > a[largest]){
                largest = l;
            }
            if(r<heapSize && a[r] > a[largest]){
                largest = r;
            }
            if(largest!=i){
                swap(a[i],a[largest]);
                maxHeapify(a,largest,heapSize);
            }
        }

        void buildMaxHeap(vector<int>& a, int heapSize){
            for(int i = heapSize /2 -1;i>=0;--i){
                maxHeapify(a,i,heapSize);
            }
        }

        int findKthLargest(vector<int>& nums, int k) {
            int heapSize = nums.size();
            buildMaxHeap(nums,heapSize);
            for(int i = nums.size()-1;i>=nums.size()-k+1;--i){
                swap(nums[0],nums[i]);  //将堆顶元素置换到底部
                --heapSize;  //删除置换到底部的堆顶元素（用堆的大小来控制
                maxHeapify(nums,0,heapSize);
            }
            return nums[0];
        }
    };