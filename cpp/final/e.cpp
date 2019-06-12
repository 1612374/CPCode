//Ubiquitous Religions
#include <bits/stdc++.h>
using namespace std;

const int MAX = 50000+5;

int p[MAX], r[MAX], cnt[MAX];

int findset(int u){
    while (u != p[u]) u = p[u];
    return u;
}

void unionSet(int u, int v){
    u = findset(u);
    v = findset(v);

    if (u != v){
        if (r[u] > r[v]){
            r[u] += r[v];
            p[v] = p[u];
            r[v] = 0;
        }
        else{
            r[v] += r[u];
            p[u] = p[v];
            r[u] = 0;
        }
    }
}

int main(int argc, char const *argv[])
{
    //freopen("xx.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int m, n, x, y;
    int t = 0;
    while (cin >> n >> m){
        ++t;
        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < MAX; i++){
            p[i] = i, r[i] = 1, cnt[i] = 0;
        }

        for (int i = 0; i < m; i++){
            cin >> x >> y;
            unionSet(x, y);
        }
        int res = 0;
        for (int i = 1; i <= n; i++){
            if (r[i] > 0)
                res++;
        }

        printf("Case %d: %d\n", t, res);
    }

    return 0;
}