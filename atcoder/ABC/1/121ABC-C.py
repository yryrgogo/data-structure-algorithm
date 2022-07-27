import numpy as np

N, M = map(int, input().split(' '))
store_list = []
for i in range(N):
    a, b = map(int, input().split(' '))
    store_list.append((a, b))

store_list = sorted(store_list, key=lambda x: x[0])

ans = 0
cnt = 0
for a, b in store_list:
    if (M - cnt) > b:
        ans += a * b
        cnt += b
    else:
        ans += a * (M - cnt)
        cnt += (M - cnt)

print(ans)
