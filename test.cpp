#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    static const int N = 1005;
    int f[N];
    int n;

    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }

    bool check(int x, int y) {
        return find(x) == find(y);
    }

    void unity(int x, int y) {
        f[find(x)] = find(y);
    }

    bool isTree(vector<vector<int>>& edges, int idx) {
        for (int i = 0; i < N; i++) {
            f[i] = i;
        }
        for (int i = 0; i < n; i++) {
            if (i == idx) {
                continue;
            }
            int first = edges[i][0];
            int second = edges[i][1];
            if (check(first, second)) {
                return false;
            }
            unity(first, second);
        }
        return true;
    }

    int getRemoveEdge(vector<vector<int>>& edges) {
        for (int i = 0; i < N; i++) {
            f[i] = i;
        }
        for (int i = 0; i < n; i++) {
            int first = edges[i][0];
            int second = edges[i][1];
            if (check(first, second)) {
                return i;
            }
            unity(edges[i][0], edges[i][1]);
        }
        return 0;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int in[N] = {0};
        n = edges.size();
        for (int i = 0; i < n; i++) {
            in[edges[i][1]]++;
        }
        vector<int> v;

        for (int i = n - 1; i >= 0; i--) {
            if (in[edges[i][1]] == 2) {
                v.push_back(i);
            }
        }

        if (v.size() > 0) {
            if (isTree(edges, v[0])) {
                return edges[v[0]];
            } else {
                return edges[v[1]];
            }
        }

        int res = getRemoveEdge(edges);
        return edges[res];
    }
};