#http://codeforces.com/problemset/problem/439/B
n,x = map(int, input().split())
a = list(map(int, input().split()))

a.sort(reverse=False)
res= 0
for i in range(n):
    res += a[i]*x
    if (x > 1): x-=1

print(res)
