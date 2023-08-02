#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        queue<pair<int, pair<int, int>>> q;
        int n = A.size();
        int m = A[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        q.push({0, {0, 0}});
        int drow[] = {1, 0, -1, 0};
        int dcol[] = {0, 1, 0, -1};
        if(X == 0 and Y == 0) return 0;
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i = 0; i<4; i++) {
                int newr = r + drow[i];
                int newc = c + dcol[i];
                
                if(newr >= 0 && newr < n && newc >= 0 && newc < m && A[newr][newc] == 1 && dis + 1 < dist[newr][newc]) {
                    dist[newr][newc] = 1 + dis;
                    if(newr == X && newc == Y) return dis + 1;
                    q.push({1 + dis, {newr, newc}});
                }
            }
        }
        return -1;
    }
};