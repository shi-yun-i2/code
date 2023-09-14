#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    const static int N = 1005;
    int f[N];

    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    bool check(int x, int y) {
        return find(x) == find(y);
    }

    void unity(int x, int y) {
        f[find(x)] = find(y);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for (int i = 0; i < N; i++) {
            f[i] = i;
        }
        vector<int> res;
        for (int i = 0; i < edges.size(); i++) {
            int first = edges[i][0];
            int second = edges[i][1];
            if (check(first, second)) {
                res.push_back(first);
                res.push_back(second);
                return res;
            } else {
                unity(first, second);
            }
        }
        return res;
    }
};