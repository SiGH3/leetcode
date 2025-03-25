#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 维护两个平衡集合：small(大根堆) 和 large(小根堆)
class MedianFinder {
public:
    multiset<int> small, large;

    void insert(int num) {
        if (small.empty() || num <= *small.rbegin()) {
            small.insert(num);
        }
        else {
            large.insert(num);
        }
        balance();
    }

    void erase(int num) {
        if (small.find(num) != small.end()) {
            small.erase(small.find(num));
        }
        else {
            large.erase(large.find(num));
        }
        balance();
    }

    int getMedian() {
        return *small.rbegin();
    }

private:
    void balance() {
        while (small.size() > large.size() + 1) {
            large.insert(*small.rbegin());
            small.erase(prev(small.end()));
        }
        while (small.size() < large.size()) {
            small.insert(*large.begin());
            large.erase(large.begin());
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int count = 0;

    // 滑动窗口 + 维护中位数
    for (int l = 0; l < n; l++) {
        MedianFinder medianFinder;

        for (int r = l; r < n; r++) {
            medianFinder.insert(p[r]); // 右扩展

            int len = r - l + 1;
            if (len % 2 == 1) { // 只有奇数长度的窗口才检查
                int midIndex = l + len / 2; // 计算真实的 mid 位置
                if (medianFinder.getMedian() == p[midIndex]) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

