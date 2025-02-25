#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

int n, m;
int arr[10];
int ind[10];

void func(int cur)
{
    if (cur == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << arr[ind[i]] <<' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        ind[cur] = i;
        func(cur + 1);
    }
}

int main(void) 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    func(0);
}