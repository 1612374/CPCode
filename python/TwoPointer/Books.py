#http://codeforces.com/problemset/problem/279/B
n,t = map(int, input().split())
a=list(map(int, input().split()))
i = 0
j = 0
sum = 0
res=0
while (j < n):
    sum += a[j]
    if (sum > t):
        sum-=a[i]
        i+=1

    res = max(res, j-i + 1)
    j+=1

print(res)