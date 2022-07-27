S = input()

# while True:
#     flag = 1
#     for i, c in enumerate(S):
#         if pre == '':
#             pre = c
#             continue

#         if (pre == '1' and c == '0') or (pre == '0' and c == '1'):
#             if i + 1 != len(S):
#                 S = S[:i - 1] + S[i + 1:]
#             else:
#                 S = S[:i - 1]
#             ans += 2
#             flag = 0
#             break
#         pre = c
#     if flag:
#         break
a = S.count("1")
b = S.count("0")
print(min(a, b) * 2)
