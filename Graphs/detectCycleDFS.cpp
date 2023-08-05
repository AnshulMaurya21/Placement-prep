#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto it: adj[node]) {
            if(!vis[it]) {
                if(dfs(it, node, vis, adj) == true) return true;
            }
            else if(it != parent) return true;
        }
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // Initialize adjacency list
        for (const auto& pre : prerequisites) {
            adj[pre[1]].push_back(pre[0]); // Construct directed edge from pre[1] to pre[0]
            adj[pre[0]].push_back(pre[1]); // Construct undirected edge from pre[0] to pre[1]
        }
        
        vector<int> vis(numCourses, 0); // Initialize visited array
        for (int i = 0; i < numCourses; ++i) {
            if (!vis[i] && dfs(i, -1, vis, adj)) return false; // Check for cycles
        }
        
        return true;
    }
};
