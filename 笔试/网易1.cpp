#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Transaction {
    int sell_stock, buy_stock;
};

int main() {
    int N, M;
    double K;
    cin >> N >> M >> K;

    vector<vector<double>> prices(N, vector<double>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> prices[i][j];
        }
    }

    double cash = K;
    int holding_stock = -1;  // 当前持有的股票编号，-1表示持有现金
    double holding_shares = 0.0;  // 当前持有的股票份数

    vector<Transaction> transactions(N, {-1, -1});

    for (int day = 0; day < N; ++day) {
        int best_buy = -1;
        double max_profit = 0.0;

        // 找到最佳购买选择
        for (int j = 0; j < M; ++j) {
            if (holding_stock == -1) { // 当前持有现金
                if (day + 1 < N && prices[day + 1][j] > prices[day][j]) {
                    double profit = (prices[day + 1][j] - prices[day][j]) / prices[day][j];
                    if (profit > max_profit) {
                        max_profit = profit;
                        best_buy = j;
                    }
                }
            } else { // 当前持有股票
                double profit = (prices[day][j] - prices[day - 1][holding_stock]) / prices[day - 1][holding_stock];
                if (profit > max_profit) {
                    max_profit = profit;
                    best_buy = j;
                }
            }
        }

        // 执行交易
        if (holding_stock != -1) {  // 如果当前持有股票，则卖出
            cash = holding_shares * prices[day][holding_stock];
            transactions[day].sell_stock = holding_stock;
            holding_stock = -1;
            holding_shares = 0.0;
        }

        if (best_buy != -1) {  // 如果找到合适的股票，则买入
            holding_stock = best_buy;
            holding_shares = cash / prices[day][best_buy];
            cash = 0.0;
            transactions[day].buy_stock = best_buy;
        }
    }

    // 输出结果
    cout << fixed << setprecision(4) << cash << endl;
    for (const auto& t : transactions) {
        cout << t.sell_stock << " " << t.buy_stock << endl;
    }

    return 0;
}
