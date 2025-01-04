import sys
input = sys.stdin.readline


while True:
  n = list(map(int, input().split()))
  stack = []
  res = 0
  
  if n[0] == 0:
    break
  
  for i in range(1, len(n)):
    idx = i
  
    while stack and stack[-1][1] >= n[i]:
      idx, prev = stack.pop()
      res = max(res, (i-idx) * prev)
    stack.append([idx, n[i]])
  
  while stack:
    idx, prev = stack.pop()
    res = max(res, (len(n)-idx) * prev)
  
  print(res)