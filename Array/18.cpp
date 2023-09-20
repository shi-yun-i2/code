#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> nSum(vector<int>& nums, int n, int start, long target) {
        int size = nums.size();
        vector<vector<int>> res;
        if (n < 2 || size < n) {
            return res;
        }
        if (n == 2) {
            int lo = start, hi = size - 1;
            while (lo < hi) {
                int left = nums[lo], right = nums[hi];
                long sum = left + right;
                if (sum > target) {
                    // 储存初始值可以直接移动到与初始值不同的位置,并且不用担心数组越界
                    while (lo < hi && nums[hi] == right) {
                        hi--;
                    }
                } else if (sum < target) {
                    while (lo < hi && nums[lo] == left) {
                        lo++;
                    }
                } else {
                    res.push_back({left, right});
                    while (lo < hi && nums[hi] == right) {
                        hi--;
                    }
                    while (lo < hi && nums[lo] == left) {
                        lo++;
                    }
                }
            }
        } else {
            for (int i = start; i < size; i++) {
                // 首项大于target时不一定返回,例如{-10,-1,-2},target = -13
                // 三数之和可以通过nums[i] > 0就返回了，因为0已经是确定的数了
                // if (nums[i] > target) {
                //     return res;
                // }
                vector<vector<int>> sub = nSum(nums, n - 1, i + 1, target - nums[i]);
                // 向子数组添加元素,每次递归都会添加元素
                for (vector<int>& arr : sub) {
                    arr.push_back(nums[i]);
                    res.push_back(arr);
                }
                // 首项去重,因为这是后面的操作,所以第一次取首项时不会收到影响,在后面所以向后去重
                while (i < size - 1 && nums[i] == nums[i + 1]) {
                    i++;
                }
            }
        }
        return res;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // 递归里面不要排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> res = nSum(nums, 4, 0, target);
        return res;
    }
};


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            // 剪枝,某项大于target 并且 这一项 >= 0
            if (nums[k] > target && nums[k] >= 0) {
                break;
            }
            // 首项去重,在前面所以要向前去重
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            for (int i = k + 1; i < nums.size(); i++) {
                // 等价于上面的操作
                if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                    break;
                }
                // 等价于上面的操作
                if (i > k + 1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1, right = nums.size() - 1;
                while (left < right) {
                    // 用long接收并不会改变数据类型,需要在算式中强转才能改变数据类型
                    long sum = (long) nums[left] + nums[right] + nums[i] + nums[k];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        res.push_back({nums[left], nums[right], nums[i], nums[k]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return res;
    }
};