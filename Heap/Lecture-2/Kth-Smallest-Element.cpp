#include <bits/stdc++.h>
using namespace std;

int kthSmallest(int arr[], int n, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    for (int i = k; i <= n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int ans = pq.top();
    return ans;
}

int kthSmallestBrute(int arr[], int n, int k){
    sort(arr, arr+n);

    return arr[k-1];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ans = kthSmallest(arr, 8, 5);
    cout << ans << endl;
    int ans2 = kthSmallestBrute(arr, 8, 5);
    cout << ans2 << endl;
}