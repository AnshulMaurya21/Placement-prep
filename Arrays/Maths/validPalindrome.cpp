#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string cleanedPhrase;
        for (char c : s)
        {
            if (isalnum(c))
            {
                cleanedPhrase += tolower(c);
            }
        }

        string reversedPhrase = cleanedPhrase;
        reverse(reversedPhrase.begin(), reversedPhrase.end());

        if (cleanedPhrase == reversedPhrase)
            return true;
        return false;
    }
};