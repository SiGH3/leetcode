#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Transaction {
  int sell_stock;
  int buy_stock;
};

// 计算最大现金余额及交易策略
pair<double, vector<Transaction>> maximizeProfit(int N, int M, double K, vector<vector<double>>& prices) {
  double cash = K;  // 当前现金
  int last_buy = -1;  // 记录上一天买入的股票编号
  vector<Transaction> transactions(N, {-1, -1});  // 交易记录

  for (int i = 0; i <= N - 1; i++) {  // 只需遍历前 N-1 天（最后一天不用买）
      int best_stock = -1;
      double best_ratio = 1.0;

      // 如果前一天买了股票，则当天卖出
      if (last_buy != -1) {
          cash = cash *(prices[i][last_buy] /(prices[i-1][last_buy]));  // 计算卖出金额

          transactions[i].sell_stock = last_buy;  // 记录卖出股票
          last_buy = -1;
        }
      // 计算每支股票的次日收益比
      if(i!=(N-1))
        {for (int j = 0; j < M; j++)
            {
              double ratio = prices[i + 1][j] / prices[i][j];
              if (ratio > best_ratio) {
                  best_ratio = ratio;
                  best_stock = j;
                }
            }
        }

      // 只有当次日收益比大于 1.0 时才买入
      if (best_stock != -1&&i!=(N-1)) {
          last_buy = best_stock;
          transactions[i].buy_stock = best_stock;  // 记录买入股票
          //cash -= cash;  // 现金全买
        }
    }
  return {cash, transactions};
}

int main() {
  int N, M;
  double K;
  cin >> N >> M >> K;
  vector<vector<double>> prices(N, vector<double>(M));

  for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
          cin >> prices[i][j];
        }
    }

  auto result = maximizeProfit(N, M, K, prices);

  // 输出最终现金余额
  cout << fixed << setprecision(1) << result.first << endl;

  // 输出每天的交易情况
  for (const auto& t : result.second) {
      cout << t.sell_stock << " " << t.buy_stock << endl;
    }

  return 0;
}
/*
5 5 100
3.0 1.0 5.0 7.0 4.0
2.0 4.0 6.0 4.0 7.0
8.0 3.0 9.0 3.0 5.0
10.0 4.0 8.0 6.0 9.0
3.0 8.0 10.0 5.0 6.0*/