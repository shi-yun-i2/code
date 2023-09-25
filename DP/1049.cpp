#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 从一堆石头中,每次拿两块重量分别为x,y的石头,若x=y,则两块石头均粉碎;
    // 若x<y,两块石头变为一块重量为y-x的石头求最后剩下石头的最小重量(若没有剩下返回0)
    // 问题转化为：把一堆石头分成两堆,求两堆石头重量差最小值
    // 进一步分析：要让差值小,两堆石头的重量都要接近sum/2;
    // 我们假设两堆分别为A和B,同时A < sum/2,B > sum/2,若A更接近sum/2,B也相应更接近sum/2
    // 进一步转化：将一堆stone放进最大容量为sum/2的背包,求放进去的石头的最大重量MaxWeight,最终答案即为sum-2*MaxWeight;、
    // 0/1背包最值问题：外循环stones,内循环target=sum/2倒序,应用转移方程1
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }
        // bagSize向下取整 --> target <= sum / 2
        int bagSize = sum / 2;

        vector<int> dp(bagSize + 1, 0);

        for (int i = 0; i < stones.size(); i++) {
            for (int j = bagSize; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        // dp[target] <= target
        // target <= sum / 2
        // sum >= 2target >= 2dp[target]
        // sum - dp[target] >= dp[target]

        return (sum - dp[bagSize]) - dp[bagSize];
    }
};
