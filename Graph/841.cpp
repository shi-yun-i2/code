#include <bits/stdc++.h>

using namespace std;

class Solution1 {
public:
    void dfs(vector<vector<int>>& rooms, vector<bool>& vis, int key) {
        vector<int> keys = rooms[key];
        vis[key] = true;
        for (int ele : keys) {
            if (!vis[ele]) {
                dfs(rooms, vis, ele);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        vector<bool> vis(n, 0);
        dfs(rooms, vis, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    void bfs(vector<vector<int>>& rooms, vector<bool>& vis, int key) {
        queue<int> q;
        q.push(key);
        vis[key] = true;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            vector<int> keys = rooms[cur];
            for (int ele : keys) {
                if (!vis[ele]) {
                    q.push(ele);
                    vis[ele] = true;
                }
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int m = rooms[0].size();
        vector<bool> vis(n, 0);
        bfs(rooms, vis, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                return false;
            }
        }
        return true;
    }
};
