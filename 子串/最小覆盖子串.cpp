#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            unordered_map<char ,int> mp_t;
            unordered_map<char ,int> mp_s;
            //统计t的字符
            for(char& c : t){
               mp_t[c]++;
            }   
            
            int left=0, right=0;   //滑动窗口的左右边界
            
            int valid = 0;   //窗口中满足需求的字符种类数
            int start =0;    //最小窗口的起点
            int minLen = INT_MAX;           //最小窗口的长度

            while(right<s.size()){
                //扩展窗口
                char c = s[right];
                right++;
                if(mp_t.count(c)){   //只考虑在t中出现的字符
                    mp_s[c]++;
                    if(mp_s[c]==mp_t[c]) valid++;
                }
                //看能不能缩小窗口
                while(valid==mp_t.size()){  //当窗口完全覆盖t
                    if(right-left < minLen){
                        start = left;
                        minLen = right-left;
                    }
                    char d =s[left];
                    left++;   //缩小窗口
                    if(mp_t.count(d)) {
                        if(mp_s[d]==mp_t[d]) valid--;
                        mp_s[d]--;
                    }
                }
            }
            return minLen == INT_MAX ? "" : s.substr(start, minLen); 
        }
    };


int main(){
    Solution sol;
    string s = "ADOBECODEBANC", t = "ABC";
    string res = sol.minWindow(s,t);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}
