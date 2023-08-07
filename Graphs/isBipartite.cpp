#include<bits/stdc++.h>
using namespace std;

class Solution {
        bool check(int start, int V, vector<int> adj[], int col[]) {
        queue<int> q;
        q.push(start);
        col[start] = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it: adj[node]) {
                if(col[it] == -1) {
                    col[it] = !col[node];
                    q.push(it);
                }
                else if(col[it] == col[node]) {
                    return false;
                }
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	  int color[V];
	  for(int i = 0; i<V; i++) color[i] = -1;
      for(int i = 0; i<V; i++) {
        if(color[i] == -1 && (check(i, V, adj, color) == false)) {
            return false;
        }
    }
    return true;
	}
};