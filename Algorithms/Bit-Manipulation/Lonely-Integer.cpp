//Problem Link: https://www.hackerrank.com/challenges/lonely-integer/problem

//Time Complexity: 0(n)
//Auxilary Space: 0(1)
#include <iostream>
#include <vector>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();

int lonelyInterger(vector<int> v)
{
    int res = 0;
    for (int i = 0; i < v.size(); i++)
    {
        res = res ^ v[i];
    }
    return res;
}

int main()
{
    FAST int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int res = lonelyInterger(v);
    cout << res << '\n';
    return 0;
}

/*
Xor propertirs used:
    x^x = 0
    x^0 = x
*/