// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     long long t, sum = 0;
//     cin >> n >> t;

//     int a[n];
//     for (int i = 0; i < n; i++) {
//         cin >> a[i];
//         sum += a[i];
//     }

//     int count = 0;
//     for (int i = 0; i < n; i++) {
//         long long new_sum = sum - 2 * a[i];  // 计算替换后数组的和
//         if (new_sum >= 0 && new_sum <= t) {
//             count++;
//         }
//     }

//     cout << count << endl;
//     return 0;
// }



#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> map(0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        map[a[i]]++;
    }

    vector<int> res;

    for(int i=0;i<n;i++){
        map[a[i]]--;
        if(map[a[i]]==0){
            map.erase(a[i]);
        }
        for(int j=0;j<2*10^5;j++){
            if(!map.count(j)){
                res.push_back(j);
                break;
            }
            
        }
        map[a[i]]++;
    }

    for(int i=0;i<n;i++){
        cout<< res[i] <<" ";
    }




    return 0;
}
// 64 位输出请用 printf("%lld")
