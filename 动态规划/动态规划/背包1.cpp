#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, bagweight;  //n����Ʒ����������Ϊbagweight

	cin >> n >> bagweight;

	vector<int> weight(n, 0);   //ÿ����Ʒ������
	vector<int> value(n, 0);  //ÿ����Ʒ�ļ�ֵ

	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}

	for (int j = 0; j < n; j++)
	{
		cin >> value[j];
	}

	//dp����, weight.size()�У�ÿ����bagweight+1��Ԫ�أ���ʼ��Ϊ0
	//dp[i][j]����������ռ�Ϊj�������,���±�Ϊ[0, i]����Ʒ��������ȡ,�ܴﵽ������ֵ
	vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));


	//j<weight[0]������ѱ���ʼ��Ϊ0
	//i=0ʱ��j>=weight[0]�������ԷŽ���0����Ʒ����dp��ʼ��Ϊ��0����Ʒ�ļ�ֵ
	for (int j = weight[0]; j <= bagweight; j++)
	{
		dp[0][j] = value[0];
	}

	//��0�г�ʼ����ϣ���ʼ����1�������붫��
	for (int i = 1; i < weight.size(); i++)  //������Ʒ
	{
		for (int j = 0; j <= bagweight; j++)  //������������
		{ 
			if (j < weight[i])  //���װ���������Ʒi���ͼ̳���һ�У�����������һ����Ʒ�󱳰���״̬���ļ�ֵ
			{
				dp[i][j] = dp[i - 1][j];
			}
			else
			{
				//������ǰ������װ�������Ʒi�������Ƿ�Ҫװ��ȥ
				//1.������Ʒi��ȥ�����ܼ�ֵΪdp[i - 1][j]
				//2.����Ʒi������Ҫ���㡰�����ճ���Ʒi����������״̬���ܼ�ֵ+��Ʒi�ļ�ֵ
				//���У������ճ���Ʒi������Ϊj-weight[i]
				//��������Ϊj - weight[i]�Ҳ�����Ʒi������ֵΪdp[i - 1][j - weight[i]] 
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i] + value[i]]);
			}
		}
	}
	cout << dp[n - 1][bagweight] << endl;

	return 0;

}