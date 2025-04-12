#include <iostream>
using namespace std;

// 判断一个数字是否是蛇形数
bool isSnakeNumber(int num) {
  int temp=num;
  int prevDigit = -1;  // 前一位数字，初始化为-1，保证第一位可以通过
  while (temp > 0) {
      int digit = temp % 10;  // 提取当前数字的最后一位
      if (digit >= prevDigit) {
          prevDigit = digit;  // 更新前一位
        } else {
          return false;  // 如果当前数字不大于前一位，返回false
        }
      temp /= 10;  // 去掉最后一位数字
    }
  cout<<num<<endl;
  return true;  // 如果所有数字都是升序的，则是蛇形数
}

int main() {
  long long l, r;
  cin >> l >> r;  // 输入区间 [l, r]

  int count = 0;
  for (long long i = l; i <= r; ++i) {
      if (isSnakeNumber(i)) {
          count++;  // 如果是蛇形数，计数器加1
        }
    }

  cout << count << endl;  // 输出蛇形数的数量
  return 0;
}