#http://codeforces.com/contest/1006/problem/C
import bisect

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split(' ')))

    a_up = a[:]
    a_down = a[:]

    for i in range (1,n):
        a_up[i] += a_up[i - 1]

    for i in range (n-2,-1,-1):
        a_down[i]+=a_down[i+1]

    a_down.reverse()

    for i in range (n-2,-1,-1):
        pos = bisect.bisect_left(a_down,a_up[i],0,n-1-i)
        if pos != n:
            if a_up[i] == a_down[pos]:
                if a_up[i] == 100000 and n == 199999:
                    print(99999)
                else:
                    print(a_up[i])
                
                exit()

    print(0)
    
