#include <bits/stdc++.h>
using namespace std;

int test, M, C, price[25][25];
int dp[210][25];

int solve(int money, int g){ // g is recursion level
    if (money < 0)
        return -100000;
    if (g == C)
        return M - money;

    if (dp[money][g] != -1)
        return dp[money][-1];

    int ans = 0;
    for (int i = 1; i <= price[g][0]; i++){
        ans = max(ans, solve(money - price[g][i], g + 1));
    }

    return dp[money][g] = ans;
}

int main(){

    cin >> test;
    while (test--){
        cin >> M >> C;
        for (int i = 0; i < C; i++){
            cin >> price[i][0];
            for (int j = 1; j <= price[i][0]; j++){
                cin >> price[i][j];
            }
        }
        memset(dp, -1, sizeof(dp));

        int ans = solve(M, 0);

        if (ans <= 0)
            cout << "no solution\n";
        else
            cout << ans << endl;
    }

    return 0;
}
