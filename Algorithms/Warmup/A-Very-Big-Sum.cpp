#include <bits/stdc++.h>

using namespace std;

// Complete the aVeryBigSum function below.
long long aVeryBigSum(vector<long> ar, int ar_count)
{
    long long int sum = 0;
    for (int i = 0; i < ar_count; i++)
    {
        sum = sum + ar[i];
    }

    return sum;
}

int main()
{

    int ar_count;
    cin >> ar_count;
    vector<long> ar(ar_count);
    for (int i = 0; i < ar_count; i++)
    {
        cin >> ar[i];
    }

    long long result = aVeryBigSum(ar, ar_count);

    cout << result << "\n";

    return 0;
}
