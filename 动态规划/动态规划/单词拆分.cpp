#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
	//�����������������forѭ��������Ʒ���ڲ�for����������
	//������������������for�����������ڲ�forѭ��������Ʒ��
	//����������
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
		
		//dp[i] : �ַ�������Ϊi�Ļ���dp[i]Ϊtrue����ʾ���Բ��Ϊһ���������ֵ��г��ֵĵ��ʡ�
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 1; i <= s.size(); i++) {   //��������
			for (int j = 0; j < i; j++) {       //������Ʒ
				string word = s.substr(j, i - j);
				if (wordSet.find(word) != wordSet.end() && dp[j]) {
					dp[i] = true;
				}
			}
		}
		return dp[s.size()];
	}
};
