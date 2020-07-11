import sys
import collections

MAP = [[0 for i in range(100)] for j in range(100)]
visited = [[False for i in range(100)] for j in range(100)]
H = []
N, M = 0, 0

def BFS(y, x):
	global visited
	global MAP

	dx = [0, 1, 0, -1, 1, 1, -1, -1]
	dy = [1, 0, -1, 0, 1, -1, 1, -1]

	Q = collections.deque()
	Q.append([y, x])
	visited[y][x] = True

	while len(Q):
		p = Q.pop()

		for i in range(8):
			ny = p[0]+dy[i]
			nx = p[1]+dx[i]

			if not (0 <= ny < N and 0 <= nx < M):
				continue
			if visited[ny][nx] or MAP[ny][nx] > MAP[p[0]][p[1]]:
				continue

			Q.append([ny, nx])
			visited[ny][nx] = True


cnt = 0
N, M = map(int, sys.stdin.readline().split())

for i in range(N):
	for j, height in enumerate(list(map(int,sys.stdin.readline().split()))):
		MAP[i][j] = height
		visited[i][j] = (MAP[i][j] == 0)
		H.append([height, i, j])
	
H = sorted(H, key = lambda x : x[0], reverse=True)

for i in H:
	if visited[i[1]][i[2]] == False:
		BFS(i[1], i[2])
		cnt += 1

print(cnt)