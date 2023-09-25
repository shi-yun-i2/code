#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 先遍历物品后遍历背包是这样,比如,外层循环固定coins[1],在内层循环遍历背包时,随着背包不断增加,
    // coins[1]可以重复被添加进来,而由于外层循环固定了,
    // 因此coins[2]只能在下一次外层循环添加进不同大小的背包中,这么看的话,coins[i+1]只能在coins[i]之后了；
    
    // 如果先遍历背包后遍历物品,那么外层循环先固定背包大小j,然后在大小为j的背包中循环遍历添加物品,
    // 然后在下次外层循环背包大小变为j+1,此时仍要执行内层循环遍历添加物品,
    // 也就会出现在上一轮外层循环中添加coins[2]的基础上还能再添加coins[1]的情况,
    // 那么就有了coins[1]在coins[2]之后的情况了。
    int coinChange(vector<int>& coins, int bagSize) {
        vector<int> dp(bagSize + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= bagSize; j++) {
                // 如果dp[j - coins[i]]是初始的最大值,即没有任何一种硬币可以组成剩余金额j - coins[i],
                // 那么加上一枚面额为coins[i]的硬币也无法得到完整的金额j,
                // 这种情况下就没有选择coins[i]硬币的必要,因为此时dp[j]不会有任何变化。
                // 因此,在遍历j的过程中,只有当dp[j - coins[i]]不等于初始最大值时,
                // 才需要考虑是否选择硬币coins[i],从而实现dp[j]的更新。
                if (dp[j - coins[i]] != INT_MAX) {
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
                }
            }
        }

        return dp[bagSize] == INT_MAX ? -1 : dp[bagSize];
    }
};

