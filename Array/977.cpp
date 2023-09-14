#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int pre = 0, back = nums.size() - 1;
        int idx = nums.size() - 1;
        // 比较绝对值大小
        while (pre <= back) {
            int x = abs(nums[pre]);
            int y = abs(nums[back]);
            if (x >= y) {
                res[idx] = pow(x, 2);
                pre++;
            } else {
                res[idx] = pow(y, 2);
                back--;
            }
            idx--;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // 初始化vector大小才能用下标访问
        vector<int> res(nums.size());
        // 数组两边数字的绝对值最大,相比之后可以确定数组的最大值,反向填充res数组
        int idx = nums.size() - 1;
        // 每一次比较都会填充一个值,idx--
        for (int i = 0, j = nums.size() - 1; i <= j; idx--) {
            if (nums[i] * nums[i] >= nums[j] * nums[j]) {
                res[idx] = nums[i] * nums[i];
                // 记得移动相应指针
                i++;
            } else {
                res[idx] = nums[j] * nums[j];
                j--;
            }
        }
        return res;
    }
};