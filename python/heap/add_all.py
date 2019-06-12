#https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1895
import queue
import sys
import threading
 
# take care of a whitespace from the end of each line
 
def inp():
    line = input().split(' ')
    line.remove('')
    return map(int, line)
 
def solve():
    while True:
        n = int(input())
        if n == 0:
            break
        pq = queue.PriorityQueue()
        ans = 0
        a = list(inp())
        for x in a:
            pq.put(x)
        while pq.qsize() > 1:
            x = pq.get()
            y = pq.get()
            ans += x + y
            pq.put(x + y)
        print(ans)
        del pq
        del a
 
if __name__ == '__main__':
    # initation stack size is not enough, you must increase it
    threading.stack_size(67108864)
    sys.setrecursionlimit(2**20)
    thread = threading.Thread(target=solve)
    thread.start()
