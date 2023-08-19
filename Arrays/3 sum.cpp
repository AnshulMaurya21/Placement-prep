#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {

        int sum = 0;
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 and nums[i] == nums[i - 1])
                continue;
            int s = i + 1, e = nums.size() - 1;
            while (s < e)
            {
                sum = nums[i] + nums[s] + nums[e];
                if (sum < 0)
                    s++;
                else if (sum > 0)
                    e--;
                else
                {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    s++;
                    e--;

                    while (s < e && nums[s] == nums[s - 1])
                    {
                        s++; // Skip duplicates
                    }
                    while (s < e && nums[e] == nums[e + 1])
                    {
                        e--; // Skip duplicates
                    }
                }
            }
        }
        return ans;
    }
};