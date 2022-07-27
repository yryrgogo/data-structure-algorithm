# coding: utf-8
import sys
import itertools


def sr(): return sys.stdin.readline().rstrip()


def ir(): return int(sr())


def lr(): return list(map(int, sr().split()))


N, Q = lr()
S = sr()
lr_list = []
for i in range(Q):
    l, r = lr()
    lr_list.append((l, r))

cnt = 0
ac_list = [0]
for i, (s1, s2) in enumerate(zip(S, S[1:])):
    if s1 + s2 == 'AC':
        cnt += 1
        ac_list.append(cnt)
    else:
        ac_list.append(cnt)

for (l, r) in lr_list:
    print(ac_list[r - 1] - ac_list[l - 1])
