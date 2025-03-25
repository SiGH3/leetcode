#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    unordered_set<int> possible = { k };

    for (char cmd : s) {
        unordered_set<int> new_possible;
        for (int pos : possible) {
            if (cmd == 'L') {
                if (pos > 1) new_possible.insert(pos - 1);
                else new_possible.insert(pos);
            }
            else if (cmd == 'R') {
                if (pos < n) new_possible.insert(pos + 1);
                else new_possible.insert(pos);
            }
            else if (cmd == '?') {
                if (pos > 1) new_possible.insert(pos - 1);
                if (pos < n) new_possible.insert(pos + 1);
            }
        }
        possible = new_possible;
    }

    for (int i = 1; i <= n; ++i) {
        if (possible.find(i) != possible.end()) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }
    cout << endl;

    return 0;
}
/*
3 2
LR?
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    // 初始化 DP 数组
    vector<bool> dp_prev(n + 1, false);
    dp_prev[k] = true;

    for (char cmd : s) {
        vector<bool> dp_current(n + 1, false);
        for (int pos = 1; pos <= n; ++pos) {
            if (dp_prev[pos]) {
                if (cmd == 'L') {
                    if (pos > 1) dp_current[pos - 1] = true;
                    else dp_current[pos] = true;
                }
                else if (cmd == 'R') {
                    if (pos < n) dp_current[pos + 1] = true;
                    else dp_current[pos] = true;
                }
                else if (cmd == '?') {
                    if (pos > 1) dp_current[pos - 1] = true;
                    if (pos < n) dp_current[pos + 1] = true;
                }
            }
        }
        dp_prev = dp_current;
    }

    for (int i = 1; i <= n; ++i) {
        if (dp_prev[i]) {
            cout << "1";
        }
        else {
            cout << "0";
        }
    }
    cout << endl;

    return 0;
}
/*
3 2
LR?
*/