#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, bagweight;  //n个物品，背包容量为bagweight

	cin >> n >> bagweight;

	vector<int> weight(n, 0);   //每个物品的重量
	vector<int> value(n, 0);  //每个物品的价值

	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}

	for (int j = 0; j < n; j++)
	{
		cin >> value[j];
	}

	//dp数组, weight.size()行，每行有bagweight+1个元素，初始化为0
	//dp[i][j]代表行李箱空间为j的情况下,从下标为[0, i]的物品里面任意取,能达到的最大价值
	vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));


	//j<weight[0]的情况已被初始化为0
	//i=0时，j>=weight[0]表明可以放进第0个物品，将dp初始化为第0的物品的价值
	for (int j = weight[0]; j <= bagweight; j++)
	{
		dp[0][j] = value[0];
	}

	//第0行初始化完毕，开始往第1行里填入东西
	for (int i = 1; i < weight.size(); i++)  //遍历物品
	{
		for (int j = 0; j <= bagweight; j++)  //遍历背包容量
		{ 
			if (j < weight[i])  //如果装不下这个物品i，就继承上一行（即考虑完上一件物品后背包的状态）的价值
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				//背包当前容量能装下这个物品i，则考虑是否要装进去
				//1.不放物品i进去，则总价值为dp[i - 1][j]
				//2.放物品i，则需要计算“背包空出物品i的容量”的状态下总价值+物品i的价值
				//其中，背包空出物品i的容量为j-weight[i]
				//背包容量为j - weight[i]且不放物品i的最大价值为dp[i - 1][j - weight[i]] 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i] + value[i]]);
			}
		}
	}
	cout << dp[n - 1][bagweight] << endl;

	return 0;

}