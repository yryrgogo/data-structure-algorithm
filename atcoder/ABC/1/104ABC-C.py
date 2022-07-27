d, g = map(int, input().split())
p = []
c = []
for _ in range(d):
    px, cx = map(int, input().split())
    p.append(px)
    c.append(cx)

ans = 2 << 9

# '1<<d'は1を2進数で2桁左にずらす
# 2進数を使ってるのは、MAXで2^D通り試せばいいからか
for m in range(1 << d):
    s = 0
    num = 0
    rest_max = -1
    for i in range(d):
        # mをi桁右にずらす（2進数）
        # &は論理積. 両方が1の時だけ1になる
        # コンプリートボーナスをとるかとらないかを全パターン網羅でやってるだけやな
        if m >> i & 1:
            s += 100 * (i + 1) * p[i] + c[i]
            num += p[i]
        else:
            # このrest_maxは、問題番号だから、まだコンプリートしていない最大の問題番号か
            # iは昇順でループするので、ここでrest_maxを更新するのは問題なし
            rest_max = i
    # まだ未達
    if s < g:
        s1 = 100 * (rest_max + 1)
        # 残っている最大の問題番号で達成できるか？
        need = (g - s + s1 - 1) // s1
        # 達成に必要な問題数が最大問題番号の問題数以上だったらcontinue
        # （コンプリート獲得なしでも達成できる数じゃなかったら）
        # これはコンプリートしない問題番号は1つのみで、2つ以上は存在しないことにしてるが、それでよいのか？反証はないか？
        # いや、よいな。複数の問題をコンプリートせずに半端にとくなら、最大の問題番号をコンプリートする場合の方が効率良いもん
        if need >= p[rest_max]:
            continue
        num += need
    # これまでの結果で最小の値を探す
    ans = min(ans, num)
print(ans)
