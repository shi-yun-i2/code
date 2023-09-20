#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    // 分析:区间内元素覆盖子串全部字符的最短子数组,维护子串全部字符的映射关系
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int minn = 1e9;
        // left一直在更新,使用变量记录合法位置的起始位置
        int start = 0;
        // 有限的范围内,使用哈希数组提升时间和空间效率,初始化为0
        int hash[128] = {0};
        for (int i = 0; i < t.size(); i++) {
            // 有大写字母时要减去'A'映射,每一次使用到都要减去'A'
            // 数组开了128包括了全部ascii字符,可以不用映射
            hash[t[i]]++;
        }
        while (right < s.size()) {
            // 不在格式串中的字母的哈希值小于等于0,不影响check条件的判断
            // cur
            hash[s[right]]--;
            while (check(hash)) {
                if (right - left + 1 < minn) {
                    // 满足条件后更新最小值为了让后面的最小值持续更新
                    minn = right - left + 1;
                    // 一直使用substr会不断创建新的字符串对象使内存溢出,记录起始位置即可
                    start = left;
                }
                // cur
                hash[s[left]]++;
                left++;
            }
            right++;
        }
        return minn == 1e9 ? "" : s.substr(start, minn);
    }

    bool check(int hash[]) {
        for (int i = 0; i < 128; i++) {
            if (hash[i] > 0) {
                return false;
            }
        }
        return true;
    }
};


class Solution2 {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int minn = 1e9;
        int start = 0;
        // 维护窗口内各字符的数量
        unordered_map<char, int> need, window;
        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }
        // valid维护窗口和需求重叠的字符个数
        int valid = 0;
        while (right < s.size()) {
            // cur
            window[s[right]]++;
            // window增加的字符还没有超过need的字符数量时才是增加的有效字符
            // cur
            if (window[s[right]] <= need[s[right]]) {
                valid++;
            }
            // valid == t.size()的时候是合法情况
            while (valid == t.size()) {
                if (right - left + 1 < minn) {
                    minn = right - left + 1;
                    start = left;
                }
                // 移出去之前的字符数量小于等于需要的数量时才是删除的有效字符
                // cur
                if (window[s[left]] <= need[s[left]]) {
                    valid--;
                }
                // 先维护窗口元素
                // cur
                window[s[left]]--;
                // 最后进行指针的移动
                left++;
            }
            right++;
        }
        return minn == 1e9 ? "" : s.substr(start, minn);
    }
};

// 确定移动窗口会影响几个变量,它们都属于cur
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int minn = 1e9;
        int start = 0;
        // 注意:使用数组一定要先初始化
        int need[128] = {0};
        int window[128] = {0};
        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }
        int valid = 0;
        while (right < s.size()) {
            window[s[right]]++;
            if (window[s[right]] <= need[s[right]]) {
                valid++;
            }
            while (valid == t.size()) {
                if (right - left + 1 < minn) {
                    minn = right - left + 1;
                    start = left;
                }
                if (window[s[left]] <= need[s[left]]) {
                    valid--;
                }
                window[s[left]]--;
                left++;
            }
            right++;
        }
        return minn == 1e9 ? "" : s.substr(start, minn);
    }
};
