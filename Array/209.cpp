#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    // 滑动窗口 O(2n)
    int minSubArrayLen(int target, vector<int>& nums) {
        // 左右指针都从0开始
        int left = 0, right = 0;
        int sum = 0, minn = 1e9;
        while (right < nums.size()) {
            sum += nums[right];
            while (sum >= target) {
                minn = min(minn, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        // 注意:没有更新minn时默认返回0
        return minn == 1e9 ? 0 : minn;
    }
};


// 最长模板:最长连续小球
// 初始化left, right, cur, maxx
// while(右指针没有到结尾){
//        窗口扩大:加入right对应元素，更新当前cur
//        while (cur不满足要求){                <-----------------不满足要求,要让窗口缩小使其满足要求
//            窗口缩小:移除left对应元素,更新当前cur,left右移
//        }
//        更新最优结果maxx                      <-----------------循环外更新(重点:更新时必须要满足要求)
//        right++;
// }
// 返回maxx;



// 最短模板:最短子数组
// 初始化left, right, cur, minn
// while(右指针没有到结尾){
//        窗口扩大:加入right对应元素,更新当前cur
//        while (cur满足要求){                  <------------------满足要求,要缩小窗口找到最小的满足要求
//            更新最优结果minn                   <------------------循环内更新(重点:更新时必须要满足要求)
//            窗口缩小:移除left对应元素,更新当前cur,left右移
//        }
//        right++;
// }
// 返回minn;
