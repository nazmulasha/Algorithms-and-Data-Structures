#include <bits/stdc++.h>
using namespace std;

int lps( char *str )
{
    int n = strlen( str );
    bool table[n][n];
    memset(table, 0, sizeof(table));
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (str[i] == str[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n-k+1 ; ++i)
        {
            int j = i + k - 1;
            if (table[i+1][j-1] && str[i] == str[j])
            {
                table[i][j] = true;
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    printf("Longest palindrome substring is: ");
    return maxLength;
}
int main()
{
    char str[] = "whateverissays";
    printf("nLength is: %dn", lps(str));
    int min_deletion_to_make_palindrome=strlen(str)-lps(str);
    return 0;
}
