import sys
input = sys.stdin.readline

n = int(input())
stack = []
res = 0

for i in range(n):
  h = int(input())
  idx = i

  while stack and stack[-1][1] >= h:
    idx, prev = stack.pop()
    res = max(res, (i-idx) * prev)
  stack.append([idx, h])

while stack:
  idx, prev = stack.pop()
  res = max(res, (n-idx) * prev)

print(res)