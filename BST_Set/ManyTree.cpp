//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1167
#include <bits/stdc++.h>
using namespace std;
 
int t;
 
int main(){
  //freopen("xx.txt", "r", stdin);

  ios_base::sync_with_stdio(false);

 
  cin >> t;
  string s;
  multiset<string> ms;
  //getline(cin , s);
  cin.ignore();
  getline(cin, s);
 
  while (t--){
 
    ms.clear();
    int cnt = 0;
 
    while (getline(cin,s))
    {
 
      if (s == "") break;
      ms.insert(s);
      cnt++;
        //cout << s << endl;
    }
 
 
    multiset<string>::iterator it = ms.begin();
    string s = *it;
 
    int cnt_tmp = 0;
    for (; it != ms.end(); it++)
    {
      if (*it == s) cnt_tmp++;
      else {
        it--;
        cout << *it << " ";
        //printf("%.4lf\n", 100 * ((double)cnt_tmp / cnt));
        cout << fixed << setprecision(4) << 100 * ((double)cnt_tmp / cnt) << "\n";
        cnt_tmp = 1;
        it++;
        s = *it;
      }
    }
 
    it = ms.end();
    it--;
 
    cout << *it << " ";
    cout << fixed << setprecision(4) << 100 * ((double)cnt_tmp / cnt) << "\n";
 
    if (t) cout << "\n";
 
  }
 
  return 0;
}