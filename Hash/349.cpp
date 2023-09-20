#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        // vector和set相互构造
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        if (set1.size() <= set2.size()) {
            for (int ele : set1) {
                if (set2.count(ele)) {
                    res.push_back(ele);
                }
            }
        } else {
            for (int ele : set2) {
                if (set1.count(ele)) {
                    res.push_back(ele);
                }
            }
        }
        return res;
    }
};