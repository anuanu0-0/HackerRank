#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// Complete the miniMaxSum function below.
void miniMaxSum(vector<long long int> arr)
{

    sort(arr.begin(), arr.end());
    long long int sumS = arr[0] + arr[1] + arr[2] + arr[3];
    long long int sumL = arr[2] + arr[3] + arr[4] + arr[1];
    cout << sumS << " " << sumL;
}

int main()
{

    vector<long long int> arr(5);

    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    miniMaxSum(arr);

    return 0;
}
