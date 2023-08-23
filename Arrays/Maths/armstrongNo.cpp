#include <bits/stdc++.h>
using namespace std;

bool checkArmstrong(int n)
{
    // Write your code here
    int count = 0;
    int num = n;
    while (num > 0)
    {
        count++;
        num = num / 10;
    }

    int sum = 0;
    int temp = n;
    while (temp > 0)
    {
        int digit = temp % 10;
        sum += pow(digit, count);
        temp = temp / 10;
    }

    if (n == sum)
        return true;
    return false;
}