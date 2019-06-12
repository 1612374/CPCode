//http://codeforces.com/problemset/problem/279/B

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, t, a[100001];
    scanf("%d%d", &n, &t);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    int l = 0, r = 0, ans = 0;
    int Sum = 0;

    while (r < n)
    {
        Sum+= a[r];
        if (Sum <= t && r - l + 1 > ans)
            ans = r - l + 1;

        if (Sum > t){
            while (Sum > t){
                Sum -= a[l];
                l++;
            }
        }
        r++;
    }

    cout << ans;
    return 0;
}
