#include <bits/stdc++.h>
using namespace std;

vector<int> getSecondOrderElements(int n, vector<int> a)
{
    // Write your code here.
    int largest = a[0], secondLargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            secondLargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > secondLargest)
        {
            secondLargest = a[i];
        }
    }
    int smallest = a[0], secondSmallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < smallest)
        {
            secondSmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] > smallest && a[i] < secondSmallest)
        {
            secondSmallest = a[i];
        }
    }
    vector<int> ans;
    ans.push_back(secondLargest);
    ans.push_back(secondSmallest);
    return ans;
}