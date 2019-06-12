//hacker earth, bfs, key
#include <bits/stdc++.h>
using namespace std;

int main(){
    int key, lock;
    int n;

    scanf("%d%d%d", &key, &lock, &n);
    int a[1001];

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    queue <int> q;
    int res[100005] = {-1};
    
    memset(res,-1,sizeof(res));
    
    q.push(key);
    res[key] = 0;

    while (q.empty() == false){
        long long tmp = q.front();
        if (q.front() == lock)
            break;

        q.pop();

        for (int i = 0; i < n; i++){
            long long x = a[i];
            x *= tmp;
            x %= 100000;
            if (res[x] == -1){
                q.push(x);
                res[x] = res[tmp] + 1;
            }
        }

    }

    cout << res[lock];

    return 0;
}