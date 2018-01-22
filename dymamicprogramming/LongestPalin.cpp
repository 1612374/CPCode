#include <bits/stdc++.h>
using namespace std;
bool dp[100][100];
string s;
void init(){
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            if (i == j) dp[i][j] = true;
            else dp[i][j] = false;
}
int main(){
    cin >> s;
    init();
    int maxlength = 1, j = 0;
    int idx1=0, idx2=0;
    int n = s.length();
    for (int k=1; k <= n-1; k++){
        for (int i=0; i <= n-1-k; i++){
            j = i+k;
            dp[i][j] = ((dp[i+1][j-1])&&(s[i]==s[j]));
            
            if (dp[i][j] && k+1 > maxlength){
                maxlength = k+1;
                idx1 = i;
                idx2 = j;
            }
        }
    }
    cout << maxlength << endl;
    for (int m = idx1; m <= idx2; m++) cout << s[m];
    cout << endl;
    return 0;
}
