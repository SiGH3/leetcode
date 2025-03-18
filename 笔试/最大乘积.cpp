#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maximumProduct(const vector<int>& nums) {
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    int min1 = INT_MAX, min2 = INT_MAX;

    for (int num : nums) {
        if (num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = num;
        } else if (num > max2) {
            max3 = max2;
            max2 = num;
        } else if (num > max3) {
            max3 = num;
        }

        if (num < min1) {
            min2 = min1;
            min1 = num;
        } else if (num < min2) {
            min2 = num;
        }
    }

    return max(max1 * max2 * max3, min1 * min2 * max1);
}

int main() {
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);  // 读取输入的所有数
        if (cin.get() == '\n') break;  // 如果输入到换行符，结束输入
    }

    cout << maximumProduct(nums) << endl;  // 输出最大乘积
    return 0;
}
