#https://www.hackerrank.com/challenges/qheap1/problem
import queue
 
def inp():
    return map(int, input().split(' '))
 
def solve():
    pq = queue.PriorityQueue()
    pq_remove = queue.PriorityQueue()
 
    q = int(input())
    for times in range(q):
        line = input()
        if line[0] == '1':
            value = int(line.split(' ')[1])
            pq.put(value)
        elif line[0] == '2':
            value = int(line.split(' ')[1])
            pq_remove.put(value)
        else:
            while not pq_remove.empty() and pq.queue[0] == pq_remove.queue[0]:
                pq.get()
                pq_remove.get()
            print(pq.queue[0])
 
if __name__ == '__main__':
    solve()
