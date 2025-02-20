#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;


class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        set<char> exist;
        int start = 0;
        int max_count = 0;
        for (int end = 0; end < s.length(); end++)
        {
            while (exist.find(s[end]) != exist.end())
            {
                exist.erase(s[start]);
                start++;
            }
            exist.insert(s[end]);
            max_count = max(max_count, end - start + 1);
        }
        return max_count;
                  
    }
};