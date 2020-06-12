// Problem Link: https://www.hackerrank.com/challenges/counter-game/problem

/*
    Awesome explanation by Abhishek Verma
    Taken from hackerRank discussions
   
     Suppose N=1101001100(binary), then the operations will be :

    ------------------- N is not power of 2 ----------------------
    N = 1101001100          Louise will reduce it by 1000000000
    N =  101001100          Richard will reduce it by 100000000
    N =    1001100          Louise will reduce it by    1000000
    N =       1100          Richard will reduce it by      1000

    ------------------- N(100) is power of 2 ----------------------
    N =        100          Louise will reduce counter by half
    N =        10           Richard will reduce counter by half
    N =        1            Louise can't make a move, hence, loses
                            Richard is the winner !
    The above example shows that N=1101001100 can be better represented as "1101001100", where we need to count "1s to the left of 1" and "0s 
    to the right of 1", to know the total number of operations.

    Thus, total number of operations = 4 (1s in 1101001) + 2 (0s in 100) = 6. Since, this number (6) is even, hence, Richard wins.


    This is all that is required to know the answer, but, as you can see, this forces us to do calculation in two parts : counting 1s and counting 0s.
    Somehow, if we could modify the "100" part of "1101001100" to "011" thus changing the number to "1101001011", all we would need is to count 1s in 
    this number i.e. setBits in the number.

    This final requirement to flip all trailing 0s to 1s and last 1 to 0 (without modifying the other bits), can be easily achieved by subtracting 
    1 from the number N. For N=1101001100, we have N-1 = 1101001011. Thus popcount(N-1) gives the number of operations in the game, which gives winner 
    depending upon if its even or odd.

*/

#include <bits/stdc++.h>

using namespace std;

#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();

//  Brian Kernighan algorithm (ALT: Use popcount(N))
//  for counting set bits
//  Time Complexity: 0(total set bits)
//  Auxilary Space: 0(1)

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
