/*
    NAIVE SOL:
    `````````
        Time Complexity: 0(n^2)
        Auxilary Space: 0(1)

    (1 ≤ l ≤ r ≤ 10^3) Input constraints are upto 10^3 , therefore 0(n^2) algo with also work fine for this input range, as 
    for n = 10^3, we get 0(10^6) which can be handled by normal computing devices

*/

/* 
    EFFICIENT SOL:
    ``````````````
        Time Complexity: 0(1)
        Auxilary Space: 0(1)
    
    IDEA  
   ``````
    eg- l=10 -> (1010), r=15 -> (1111).
    The more distinct both the numbers are at every bit index , the larger the number we will get ( within constraint).

    The key is to get (highest) msb's position which we can get by xor of the range i.e l and r. 
                              __  __
                                \/      
    Here it is (1010 ^ 1111) = 0101 . Arrow indicates the msb.
    Now for a 32 bit m/c calculate the leading bits by subtracting from 32 & with 64 for a64 bit m/c.
    Once we get the position of the msb we turn on every bit from msb-1 to lsb.

*/

#include <bits/stdc++.h>
using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();

//     NAIVE SOL:
int maxXorNaive(int l, int r)
{
    int res = 0;
    int m = 0;
    for (int i = l; i <= r; i++)
    {
        for (int j = i; j <= r; j++)
        {
            res = i ^ j;
            m = max(res, m);
        }
    }
    return m;
}

//    EFFICIENT SOL:
int maxXorFast(int l, int r)
{

    int num = l ^ r;

    //  Calculate leading zeros
    int leading_zeros = __builtin_clz(num);

    //  For 32 bit system
    int last_zero_msb = 32 - leading_zeros;

    return pow(2, last_zero_msb) - 1;
}

int main()
{
    FAST int l, r;
    cin >> l >> r;

    //  Naive fn call
    //  int res = maxXorNaive(l, r);

    int res = maxXorFast(l, r);

    cout << res << '\n';
    return 0;
}
