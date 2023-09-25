#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // 默认是首项,可以解决只有一个元素的情况,也不会漏掉第一个元素是最大的情况
        int maxx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            nums[i] = max(nums[i], nums[i - 1] + nums[i]);
            maxx = max(nums[i], maxx);
        }
        return maxx;
    }
};