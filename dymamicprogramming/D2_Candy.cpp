#include <bits/stdc++.h>
using namespace std;
int N, a[100];
int L[100][100], ans = 0;

void Init(){

    for (int i = 1; i <= N; i++){
        L[i][a[i]] = 1;
    }
}

int main(){
    freopen("x.txt", "r", stdin);
    scanf("%d", &N);
    int T=0;
    for (int i = 1; i <= N; i++){
        cin >> a[i];
        T += a[i];
    }

    for (int x = T/2; x >= 0; --x){
        Init();
        for (int i = 1;i <= N; i++){
            for (int j = 1; j <= x; j++){
                if (L[i - 1][j] == 1 || L[i - 1][j - a[i]] == 1){
                    L[i][j] = 1;
                }
            }
        }
        if (L[N][x] == 1){
            ans = x;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
