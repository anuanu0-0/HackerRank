#include <bits/stdc++.h>

using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();

int countSetBK(unsigned long long int n)
{
    int res = 0;
    while (n > 0)
    {
        n = (n & (n - 1));
        res++;
    }

    return res;
}

int main()
{
    int t = 1;
    cin >> t;

    while (t--)
    {
        unsigned long long int n;
        cin >> n;
        (countSetBK(n - 1) & 1) ? cout << "Louise" << '\n' : cout << "Richard" << '\n';
    }
    return 0;
}
