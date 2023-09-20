#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    bool canConstruct(string s, string t) {
        // 大小优化
        if (s.size() > t.size()) {
            return false;
        }
        int hash[128] = {0};
        for (int i = 0; i < t.size(); i++) {
            hash[t[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            hash[s[i]]--;
            if (hash[s[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool canConstruct(string s, string t) {
        if (s.size() > t.size()) {
            return false;
        }
        int hash1[128] = {0};
        int hash2[128] = {0};
        for (int i = 0; i < t.size(); i++) {
            hash1[t[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            hash2[s[i]]++;
        }
        for (int i = 0; i < 128; i++) {
            if (hash2[i] > hash1[i]) {
                return false;
            }
        }
        return true;
    }
};