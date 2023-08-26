#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int mini = 0;
    for (int i = 0; i <= n - 2; i++)
    {
        mini = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[mini])
                mini = j;
        }
        swap(arr[mini], arr[i]);
    }
}