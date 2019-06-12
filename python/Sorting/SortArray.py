#http://codeforces.com/problemset/problem/451/B
def isinc(a):
    for i in range(len(a) - 1):
        if (a[i] > a[i+1]):
            return False
    return True

n=int(input())
a=list(map(int, input().split()))
b=a[:]
b.sort()

i=0
for x in range(n):
    if (a[x] != b[x]):
        i = x
        break

idx1=i

while (True):
    if ((i >= n - 1)):
        break
    if ((a[i] <= a[i+1])):
        break
    i+=1

a[idx1:i+1] = reversed(a[idx1:i+1])

if (isinc(a)):
    print("yes")
    print(idx1+1, i+1)
else:
    print("no")
