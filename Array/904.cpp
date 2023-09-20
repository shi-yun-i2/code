#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 分析:区间内元素只有两种值的最长子数组,需要维护区间内两种值的个数
    // 注意:数据范围,分析边界情况
    int totalFruit(vector<int>& fruits) {
        int left = 0, right = 0;
        int maxx = -1e9;
        // 不需要排序时使用unordered_map优化时间复杂度
        unordered_map<int, int> mapp;
        while (right < fruits.size()) {
            mapp[fruits[right]]++;
            while (mapp.size() > 2) {
                mapp[fruits[left]]--;
                // 等于0时需要手动删除
                if (mapp[fruits[left]] == 0) {
                    mapp.erase(fruits[left]);
                }
                left++;
            }
            maxx = max(maxx, right - left + 1);
            right++;
        }
        return maxx;
    }
};