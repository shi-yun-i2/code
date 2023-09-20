#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mapp;
        for (int i = 0; i < nums.size(); i++) {
            mapp[nums[i]]++;
        }
        vector<pair<int, int>> v(mapp.begin(), mapp.end());
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(v[i].first);
        }
        return res;
    }
};