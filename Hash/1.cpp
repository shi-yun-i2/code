#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapp;
        for (int i = 0; i < nums.size(); i++) {
            if (mapp.count(target - nums[i])) {
                // 返回固定数量元素可以直接使用{}构造vector<int>,返回固定数量元素
                return {mapp[target - nums[i]], i};
            } else {
                mapp[nums[i]] = i;
            }
        }
        // 返回空vector<int>{}
        return {};
    }
};