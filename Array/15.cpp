#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        // 排序去重
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            // 对于任意一组,第一项大于0,则不可能凑出0
            if (nums[i] > 0) {
                return res;
            }
            // 前面的可以多次使用重复值,后面的全部情况已经被前面包含,所以保留前面的重复数字
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 相向指针
            int left = i + 1;
            int right = nums.size() - 1;
            // 取等时指向同一个元素,不满足三个数的条件
            while (left < right) {
                int cur = nums[i] + nums[left] + nums[right];
                // 可以搜索到以nums[i]开始的全部合法序列
                if (cur > 0) {
                    right--;
                } else if (cur < 0) {
                    left++;
                } else {
                    // 收集元素后对b和c去重,因为在以nums[i]开始的这一组中,
                    //  i,left,right对应的元素已经组成了合法的一组序列,保证没有重复元素
                    res.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // right指向的元素左侧是不同的元素,如果使用右侧会有数组越界异常,left同理
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    // 左侧和右侧是不同的元素,需要再次移动指针
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};


class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                return res;
            }
            // a去重
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int lo = i + 1;
            int hi = nums.size() - 1;
            while (lo < hi) {
                // 缓存初始值
                int left = nums[lo], right = nums[hi];
                int sum = left + right + nums[i];
                if (sum > 0) {
                    // 循环去重,储存初始值可以直接移动到与初始值不同的位置,并且不用担心数组越界
                    while (lo < hi && nums[hi] == right) {
                        hi--;
                    }
                } else if (sum < 0) {
                    while (lo < hi && nums[lo] == left) {
                        lo++;
                    }
                } else {
                    res.push_back({nums[i], left, right});
                    while (lo < hi && nums[hi] == right) {
                        hi--;
                    }
                    while (lo < hi && nums[lo] == left) {
                        lo++;
                    }
                }
            }
        }
        return res;
    }
};


class Solution3 {
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
                vector<vector<int>> sub = nSum(nums, n - 1, i + 1, target - nums[i]);
                for (vector<int>& arr : sub) {
                    arr.push_back(nums[i]);
                    res.push_back(arr);
                }
                while (i < size - 1 && nums[i] == nums[i + 1]) {
                    i++;
                }
            }
        }
        return res;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nSum(nums, 3, 0, 0);
    }
};

// 超时
class XSolutionX {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        multiset<int> sett(nums.begin(), nums.end());
        set<multiset<int>> temp;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int target = 0 - (nums[i] + nums[j]);
                if (target == nums[i] || target == nums[j]) {
                    if (sett.count(target) == 1) {
                        continue;
                    }
                }
                if (nums[i] == 0 && nums[j] == 0) {
                    if (sett.count(0) <= 2) {
                        continue;
                    }
                }
                if (sett.count(target)) {
                    temp.insert({nums[i], nums[j], target});
                }
            }
        }
        vector<vector<int>> res;
        for (multiset<int> multi : temp) {
            vector<int> v(multi.begin(), multi.end());
            res.push_back(v);
        }
        return res;
    }
};
