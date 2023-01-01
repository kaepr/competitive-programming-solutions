#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;

        // string -> freq array
        // group strings by that frequency array

        map<vector<int>, vector<string>> mp;
        for (auto x : strs) {

            vector<int> freq(26);
            for (auto y : x) {
                freq[y - 'a']++;
            }

            mp[freq].push_back(x);
        }


        for (auto x : mp) {
            ans.push_back(x.second);
        }


        return ans;
    }
};