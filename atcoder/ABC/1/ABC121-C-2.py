# coding: utf-8
import sys
import itertools


def sr(): return sys.stdin.readline().rstrip()


def ir(): return int(sr())


def lr(): return list(map(int, sr().split()))


N, M = lr()
d_list = []
for i in range(N):
    a, b = lr()
    d_list.append([a, b, i])

d_list = sorted(d_list, key=lambda x: x[0])

cnt = 0
ans = 0
for d in d_list:
    if (M - cnt) > d[1]:
        ans += d[1] * d[0]
        cnt += d[1]
    elif (M - cnt) > 0:
        ans += (M - cnt) * d[0]
        cnt += (M - cnt)
    else:
        break

print(ans)
