#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MultiSort {
private:
    vector<int> arr;
public:
    void readInput() {
        int n;
        cin >> n;
        arr.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
    }

    void printResult() {
        sort(arr.begin(), arr.end());
        int mid = (arr.size() + 1) / 2;

        // 前半段升序输出
        for (int i = 0; i < mid; ++i) {
            if (i > 0) cout << " ";
            cout << arr[i];
        }

        // 后半段倒序输出
        for (int i = arr.size() - 1; i >= mid; --i) {
            cout << " " << arr[i];
        }

        
    }
};

int main() {
    MultiSort sorter;
    sorter.readInput();
    sorter.printResult();
    return 0;
}