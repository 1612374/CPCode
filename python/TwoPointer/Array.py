#http://codeforces.com/problemset/problem/224/B
n,k = map(int, input().split())
a = list(map(int, input().split()))
b = list()
b.extend([0]*100010)
cnt=0
j=0

if (k==1):
    print("1 1")

for i in range(n):
    if (b[a[i]] == 0):
        cnt += 1
    b[a[i]] += 1
    if (cnt == k):
        j = i
        break

if (cnt != k):
    print("-1 -1")
    exit()

res = 0


for i in range(j):
    if ((a[i] != a[i+1])):
        if ((b[a[i]] == 1)):
            print(i+1,j+1)
            exit()

    b[a[i]]-=1

