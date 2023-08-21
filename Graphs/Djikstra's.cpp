#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Dijkstra's Algorithm - Using Set
        // creating the distance vector -
        vector<int> dist(V, 1e9);
        set<pair<int, int>> st;
        st.insert({0, S}); // inserting the src node with distance 0
        dist[S] = 0;       // updating the src node distance in dist vector

        while (!st.empty())
        {
            auto it = *(st.begin()); // st.begin writtens and itr and i want vlaue therefore *
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for (auto it : adj[node])
            {
                int adjNode = it[0];
                int edgewt = it[1];

                if (dis + edgewt < dist[adjNode])
                {
                    if (dist[adjNode] != 1e9)
                    { // matlab someone already compute this , remove the value saving iteration here
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgewt;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};