#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool isGoodArr(vector<int>& nums,int left ,int right){
    int n =right-left+1;
    int mid = left+(n/2);
    int midValue = nums[mid];
    int count =0;
    for(int i=left;i<=right;i++){
        if(nums[i]<midValue){
            count++;
        }
    }
    return count ==(n/2);
}

int main() {
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin >> nums[i];
        }

        int count=0;
        int left =0,right=0;
        for(int left =0;left<n;left++){
            for(int right=left;right<n;right+=2){
                int len = right-left+1;
                if(len%2==1){
                    
                    if(isGoodArr(nums,left,right)){
                    count++;
                    }
                }
            }
        }
                
    cout << count << endl;
    }

    return 0;
}
// 64 位输出请用 printf("%lld")