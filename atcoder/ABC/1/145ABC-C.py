# coding: utf-8
import itertools
import numpy as np
import sys


def sr(): return sys.stdin.readline().rstrip()


def ir(): return int(sr())


def lr(): return list(map(int, sr().split()))


N = ir()

roots = []
for i in range(N):
    x, y = lr()
    roots.append([x, y])

ans = 0
path_dict = {}
all_path = list(itertools.permutations(range(0, N, 1)))
for pattern in all_path:
    sum_dist = 0
    for n1, n2 in zip(pattern, pattern[1:]):
        path = sorted([n1, n2])
        # if key not in path_dict:
        p1 = roots[path[0]]
        p2 = roots[path[1]]
        dist = np.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)
        # path_dict[key] = dist
        # else:
        #     dist = path_dict[path]

        sum_dist += dist
    ans += sum_dist
ans /= len(all_path)
print(ans)
