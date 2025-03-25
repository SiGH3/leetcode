#include <iostream>
using namespace std;

void find_fuel_combination(int A, int B, int C, int D, int N) {
  for (int x = 0; x <= 2500; ++x) {
      for (int y = 0; y <= 2500; ++y) {
          for (int z = 0; z <= 2500; ++z) {
              long long remaining = N - (long long)A * x - (long long)B * y - (long long)C * z;
              if (remaining < 0) break;  // 剪枝优化
              if (remaining % D == 0) {  // 确保整除
                  int w = remaining / D;
                  if (w >= 0 && w <= 2500) {  // w 在合法范围内
                      cout << x << " " << y << " " << z << " " << w << endl;
                      return;
                    }
                }
            }
        }
    }
  cout << -1 << endl;  // 无解
}

int main() {
  int A, B, C, D, N;
  cin >> A >> B >> C >> D >> N;
  find_fuel_combination(A, B, C, D, N);
  return 0;
}