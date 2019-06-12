#http://codeforces.com/problemset/problem/731/
str = input()
ans = 0
cur = 'a'
for ch in str:
    sub = abs(ord(ch) - ord(cur))
    ans += min(sub, 26 - sub)
    cur = ch

print(ans)