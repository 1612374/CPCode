#http://www.spoj.com/problems/MAKEMAZE/
import queue


def inp():
    return map(int, input().split(' '))


class pair:
    x = 0
    y = 0

    def __init__(self, a, b):
        self.x = a
        self.y = b


def isValid(u, maze):
    return u.x >= 0 and u.x < n and u.y >= 0 and u.y < m and maze[u.x][u.y] == '.'


def BFS(start, end, maze):
    dh = [0, -1, 0, 1]
    dc = [1, 0, -1, 0]
    visited = [[False for xx in range(m)] for yy in range(n)]
    visited[start.x][start.y] = True

    q = queue.Queue()
    q.put(start)
    while not q.empty():
        u = q.get()
        for k in range(4):
            v = pair(u.x + dh[k], u.y + dc[k])
            if isValid(v, maze) and not visited[v.x][v.y]:
                visited[v.x][v.y] = True
                if v.x == end.x and v.y == end.y:
                    return True
                q.put(v)
    return False


if __name__ == '__main__':
    testcase = int(input())
    while testcase:
        testcase -= 1
        n, m = inp()
        maze = []
        for i in range(0, n):
            maze.append(input())
        points = []
        for i in range(0, n):
            for j in range(0, m):
                if maze[i][j] == '.' and (i == 0 or j == 0 or i == n - 1 or j == m - 1):
                    points.append(pair(i, j))

        if len(points) == 2:
            if BFS(points[0], points[1], maze):
                print("valid")
            else:
                print("invalid")
        else:
            print("invalid")
