#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Complete the staircase function below.
//count1 ----> n-1 to 0
//count2 ----> 1 to n
void staircase(int n)
{
    int count1 = n - 1;
    int count2 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < count1; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < count2; j++)
        {

            cout << "#";
        }
        cout << '\n';
        count1--;
        count2++;
        if (count2 > n)
            break;
    }
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    staircase(n);

    return 0;
}
