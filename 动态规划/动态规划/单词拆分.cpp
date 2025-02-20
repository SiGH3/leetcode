#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	//如果求组合数就是外层for循环遍历物品，内层for遍历背包。
	//如果求排列数就是外层for遍历背包，内层for循环遍历物品。
	//本题求排列
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		
		//dp[i] : 字符串长度为i的话，dp[i]为true，表示可以拆分为一个或多个在字典中出现的单词。
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++) {   //遍历背包
			for (int j = 0; j < i; j++) {       //遍历物品
				string word = s.substr(j, i - j);
				if (wordSet.find(word) != wordSet.end() && dp[j]) {
					dp[i] = true;
				}
			}
		}
		return dp[s.size()];
	}
};
