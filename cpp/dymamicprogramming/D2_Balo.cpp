#include <bits/stdc++.h>
using namespace std;
int A[100],B[100];
int W = 15, N;
int dp[100][100]={0};
int main(){
    freopen("x.txt","r",stdin);

    scanf("%d", &N);

    for (int i = 1; i <= N; i++){
        cin >> A[i] >> B[i];
    }

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= W; j++){
            if (A[i] <= j){
                dp[i][j] = max(dp[i - 1][j - A[i]] + B[i], dp[i - 1][j]);
            }
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[N][W];
    return 0;
}
