#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        // 定义数组优先初始化
        int hash[128] = {0};
        for (int i = 0; i < t.size(); i++) {
            hash[t[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            hash[s[i]]--;
        }
        for (int i = 0; i < 128; i++) {
            if (hash[i] != 0) {
                return false;
            }
        }
        return true;
    }
};