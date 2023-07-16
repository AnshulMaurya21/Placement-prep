#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();
        int dp[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < m + 1; j++)
            {
                if (i == 0)
                    dp[i][j] = j; // Initialize with j
                else if (j == 0)
                    dp[i][j] = i; // Initialize with i
            }
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    int c1 = dp[i][j - 1];
                    int c2 = dp[i - 1][j];
                    int c3 = dp[i - 1][j - 1];
                    dp[i][j] = min(c1, min(c2, c3)) + 1; // Add 1 for substitution
                }
            }
        }
        return dp[n][m];
    }
};