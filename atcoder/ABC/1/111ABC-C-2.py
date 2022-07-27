from collections import defaultdict


def main():

    n = int(input())

    v = list(map(int, input().split(' ')))

    odd = defaultdict(int)
    even = defaultdict(int)
    odd[0] = 0
    even[0] = 0

    for i, num in enumerate(v):
        # print(i % 2)
        if (i % 2) == 0:
            even[num] += 1
        elif (i % 2) == 1:
            # print(i, ": ", num)
            odd[num] += 1

    even_list = sorted(even.items(), key=lambda x: x[1], reverse=True)
    odd_list = sorted(odd.items(), key=lambda x: x[1], reverse=True)

    ans_list = []
    for ev in even_list[:2]:
        for od in odd_list[:2]:
            if ev[0] != od[0]:
                ans = n - (ev[1] + od[1])
                ans_list.append(ans)

    print(min(ans_list))


main()
