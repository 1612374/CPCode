//http://codeforces.com/contest/1005/problem/C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[120006], res = 0;
map <ll,ll> cnt;
int main(){
    cin >> n;
    for (ll i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]]++;
    }
     
    for (ll i = 0; i < n; i++){
        bool flag = true;
        for (ll j = 1; j <= 30; j++){
            ll d = (ll)pow(2,j) - a[i];
         
            if (d <= 0) continue;
             
            if ((cnt[d] >= 1 && d != a[i])||(cnt[d] >1 && d == a[i])){
                flag = false;
                break;
            }


        }
        if (flag)
            res++;
    }

    cout << res;

    return 0;
}
