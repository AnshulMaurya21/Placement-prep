#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> ans;
        
        queue<int>q; // Propery of BFS traversal 
        
        int vis[V]={0}; // Creating an Array to mark all the ones visited to 1 to avoide redundancy 
        
        vis[0]=1; //Question always marks 0 to be the staring node so handle it first 
        
        q.push(0);
        
        while(!q.empty())
        {
            
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x:adj[node])
            {
                if(vis[x]!=1){ // Check if not marked 1 then 
                    vis[x]=1; // Mark it to visited 
                    q.push(x); // Add it to queue to traverse the next corresponding nodes 
                }
            }
        }
        return ans;
    }
};