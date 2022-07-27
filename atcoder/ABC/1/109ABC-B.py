def main():
    n = int(input())
    before = ''
    words = set()

    for i in range(n):
        w = input()
        if w not in words:
            words.add(w)
        else:
            print('No')
            return

        if before == '':
            before = w
            continue

        if before[-1] != w[0]:
            print('No')
            return
        before = w

    print('Yes')


main()
