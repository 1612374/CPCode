//http://codeforces.com/problemset/problem/224/B

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, k, a[100001];
    bool check[100001] = {false};

    int cnt = 0;
    cin >> n >> k;

    for (int i = 1 ; i <= n; i++){
        cin >> a[i];
        check[a[i]] = true;
    }


    int idx = -1;
    for (int i = 1; i <= n; i++){
        if (check[a[i]]){
            cnt++;
            check[a[i]] = false;
        }

        if (cnt == k){
            idx = i;
            break;
        }
    }

    if (idx == -1)
        return 0 & puts("-1 -1");




    int ans1 = idx;
    int ans2 = 0;
    bool check2[100001] = {false};
    int cnt2 = 0;
    while (idx >= 1)
    {
        if (check2[a[idx]] == false){
            check2[a[idx]] = true;
            cnt2++;
        }

        if (cnt2 == k)
        {
            ans2 = idx;
            break;
        }
        idx--;

    }

    printf("%d %d", ans2, ans1);


    return 0;
}
