//http://acm.timus.ru/problem.aspx?space=1&num=2002
#include <bits/stdc++.h>
using namespace std;

int n;
map <string, string> M;
map <string, int> M1; // logged in or not
int main(){
  freopen("xx.txt","r",stdin);

  cin >> n;
  string s1, s2, s3;
  for (int i = 0; i < n; i++){
    cin >> s1 >> s2;
    if (s1 != "logout") cin >> s3;

    if (s1 == "register") {
      if (M[s2] == ""){
        cout << "success: new user added\n";
        M[s2] = s3;
      }
      else {
        cout << "fail: user already exists\n";
      }
    }
    else if (s1 == "login"){
      if (M[s2] == s3 && M1[s2] == 0){
        cout << "success: user logged in\n";
        M1[s2] = 1;
      }
      else if (M[s2] == "")
        cout << "fail: no such user\n";
      else if (M[s2] != s3)
        cout << "fail: incorrect password\n";
      else if (M1[s2] == 1)
        cout << "fail: already logged in\n";
    }
    else if (s1 == "logout"){
      if (M[s2] == ""){
        cout << "fail: no such user\n";
      }      
      else if (M1[s2] == 0){
        cout << "fail: already logged out\n";
      }
      else{ 
        cout << "success: user logged out\n";
        M1[s2] = 0;
      }
    }
  }

  return 0;
}