from collections import defaultdict
import numpy as np

n, m = map(int, input().split())

list_ans = []
list_y = []
pre_p = -1
p_y = defaultdict(list)

for i in range(m):
    p, y = map(int, input().split())
    p_y[p].append(y)

for p in p_y.keys():
    list_y = p_y[p]
    list_num = np.argsort(list_y)
    for num in list_num:
        ans = str(p).zfill(6) + str(num + 1).zfill(6)
        print(ans)
