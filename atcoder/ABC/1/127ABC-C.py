# coding: utf-8
import sys
import itertools


def sr(): return sys.stdin.readline().rstrip()


def ir(): return int(sr())


def lr(): return list(map(int, sr().split()))


N, M = lr()
l_list = []
r_list = []
for i in range(M):
    l, r = lr()
    l_list.append(l)
    r_list.append(r)

for i in range(M):
    if i == 0:
        maxL = l_list[i]
        minR = r_list[i]
        continue
    maxL = max(maxL, l_list[i])
    minR = min(minR, r_list[i])
ans = max(minR - maxL + 1, 0)
print(ans)
