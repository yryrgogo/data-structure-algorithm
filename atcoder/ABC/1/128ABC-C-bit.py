# coding: utf-8
import sys
import itertools


def sr(): return sys.stdin.readline().rstrip()


def ir(): return int(sr())


def lr(): return list(map(int, sr().split()))


N, M = lr()
a = [0] * N

for i in range(M):
    ks = lr()
    k = ks[0]
    s_list = ks[1:]
    for s in s_list:
        a[s - 1] |= 1 << i

# p_list = [0] * M
# for i in range(M):
#     x = ir()
#     p_list[i] |= x << i

for s in range(1 << N):
    t = 0
    for i in range(N):
        if s >> i & 1:
            t ^= a[i]

    print(t)
    # if (t == p_list)
