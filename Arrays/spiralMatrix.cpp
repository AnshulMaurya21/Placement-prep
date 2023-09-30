#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        if (matrix.empty())
        {
            return ans; // Handle empty matrix
        }

        int m = matrix.size();    // Number of rows
        int n = matrix[0].size(); // Number of columns
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right)
        {
            // Traverse from left to right along the top boundary
            for (int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;

            // Traverse from top to bottom along the right boundary
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // Check if there are more rows to visit
            if (top <= bottom)
            {
                // Traverse from right to left along the bottom boundary
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Check if there are more columns to visit
            if (left <= right)
            {
                // Traverse from bottom to top along the left boundary
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};