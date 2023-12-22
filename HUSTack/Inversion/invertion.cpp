#include <bits/stdc++.h>
using namespace std;

int const Q = 1e9 + 7;
int const N = 1e6 + 5;
int n, temp[N], a[N], cnt = 0;
int merge(int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            temp[k++] = a[j++];
            cnt = (cnt + mid - i + 1) % Q;
        }
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= right)
        temp[k++] = a[j++];
    for (int i = left; i <= right; i++)
        a[i] = temp[i];
    return cnt;
}

int mergeSort(int left, int right)
{
    int mid;
    if (right > left)
    {
        mid = (right + left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
    return cnt; 
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(0, n - 1);
    cout << cnt; 
    return 0;
}
