#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // 初始化指针
    int left = 0; // 从左裁剪的起始位置
    int right = 0; // 从右裁剪的起始位置（基于反转后的数组）

    // 反转数组，用于从右裁剪
    vector<int> reversed_a(a.rbegin(), a.rend());

    while (q--) {
        char c;
        int x;
        cin >> c >> x;

        unordered_set<int> colors;
        if (c == 'L') {
            // 从左往右裁剪
            for (int i = 0; i < x; ++i) {
                colors.insert(a[(left + i) % n]);
            }
            // 更新 left 指针
            left = (left + x) % n;
        } else if (c == 'R') {
            // 从右往左裁剪
            for (int i = 0; i < x; ++i) {
                colors.insert(reversed_a[(right + i) % n]);
            }
            // 更新 right 指针
            right = (right + x) % n;
        }
        cout << colors.size() << endl;
    }

    return 0;
    
}