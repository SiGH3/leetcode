#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string s;
    cin >> s;

    vector<int> dp_prev(n + 1, -1e9);
    dp_prev[0] = 0;

    for (int i = 1; i <= k; ++i) {
        vector<int> dp_curr(n + 1, -1e9);
        for (int j = 1; j <= n; ++j) {
            int sum = 0;
            for (int l = j; l >= 1; --l) {
                int op = (s[l - 1] == '1') ? 1 : -1;
                sum += op * (a[l - 1] + i);
                dp_curr[j] = max(dp_curr[j], dp_prev[l - 1] + sum);
            }
        }
        dp_prev = dp_curr;
    }

    int maxVal = -1e9;
    for (int i = 1; i <= k; ++i) {
        maxVal = max(maxVal, dp_prev[n]);
    }

    cout << maxVal << endl;
    return 0;
}