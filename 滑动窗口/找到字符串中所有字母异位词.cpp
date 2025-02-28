#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
    public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> res;
            if(s.size()<p.size()){
                return res;
            }
            unordered_map<char, int> p_mp;
            for(auto ch : p){
                p_mp[ch]++;
            }

            int left=0;
            int right=0;
            unordered_map<char, int> s_mp;

            while(right<s.size()){
                s_mp[s[left]]++;
                if(right-left+1 > p.size()){
                    s_mp[s[left]]--;
                    if(s_mp[s[left]==0]){
                        s_mp.erase(s[left]);
                    }
                    left++;
                }

                if(right-left+1 == p.size() && p_mp == s_mp){
                    res.push_back(left);
                }
                right++;
            }


        }
    };