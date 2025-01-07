import sys
input = sys.stdin.readline

n = int(input())
pay = list(map(int, input().split()))

stack = []
res = 0

for i in range(len(pay)):
  idx = i

  while stack and stack[-1][1] >= pay[i]:
    idx, prev = stack.pop()
    res = max(res, (i-idx) * prev)
  stack.append([idx, pay[i]])

while stack:
  idx, prev = stack.pop()
  res = max(res, (len(pay)-idx) * prev)

print(res)