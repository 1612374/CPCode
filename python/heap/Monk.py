#https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-multiplication/

import queue
 
def inp():
    return map(int, input().split(' '))
 
def solve():
    n = int(input())
    a = list(inp())
    pq = queue.PriorityQueue()
    for i in range(n):
        if i < 2:
            print(-1)
            pq.put(-a[i])
        else:
            pq.put(-a[i])
            first = -pq.get()
            second = -pq.get()
            third = -pq.get()
            print(first * second * third)
            pq.put(-first)
            pq.put(-second)
            pq.put(-third)
if __name__ == '__main__':
    solve()
