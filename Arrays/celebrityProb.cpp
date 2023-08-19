#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        int c = 0;
        for (int i = 1; i < n; i++)
        {
            if (M[c][i])
                c = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (i == c)
                continue;
            if (M[c][i] || !M[i][c])
                return -1;
        }
        return c;
    }
};
