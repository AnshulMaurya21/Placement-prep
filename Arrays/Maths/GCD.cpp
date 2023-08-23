#include <bits/stdc++.h>
using namespace std;

int calcGCD(int n, int m)
{
    // Write your code here.
    while (n > 0 and m > 0)
    {
        if (n > m)
            n = n % m;
        else
            m = m % n;
    }
    if (n == 0)
        return m;
    return n;
}

// intuition -> Euclidean Algorithm
//  GCD(a, b) = GCD(a-b, b)..........->0