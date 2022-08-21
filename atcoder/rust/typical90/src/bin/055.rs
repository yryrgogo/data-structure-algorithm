use itertools::Itertools;
use whiteread::parse_line;

fn main() {
    let (n, p, q) = parse_line::<(usize, usize, usize)>().unwrap();
    let v = parse_line::<Vec<usize>>().unwrap();

    let mut ans: u64 = 0;
    for i in 0..n {
        for j in (i + 1)..n {
            for k in (j + 1)..n {
                for l in (k + 1)..n {
                    for m in (l + 1)..n {
                        let mut r = v[i] * v[j] % p;
                        r = r * v[k] % p;
                        r = r * v[l] % p;
                        r = r * v[m] % p;
                        if r == q {
                            ans += 1;
                        }
                    }
                }
            }
        }
    }

    // 5重の for 文より大分遅く TLE
    // combinations の内部実装は見たが、実装が悪いわけではなく、全ての組み合わせの iterator を作成し終えたあとにそれをループするので、O(n^5 / 120 * 組み合わせ数)というオーダーになっちゃうのか。上記だと生成のたびに計算するから最後の * 組み合わせ数がなく、間に合う
    // for comb in IntoIterator::into_iter(v).combinations(5) {
    //     let mut mul = 1;
    //     mul = (mul * comb[0]) % p;
    //     mul = (mul * comb[1]) % p;
    //     mul = (mul * comb[2]) % p;
    //     mul = (mul * comb[3]) % p;
    //     mul = (mul * comb[4]) % p;
    //     if mul == q {
    //         ans += 1;
    //     }
    // }

    println!("{}", ans);
}

fn npr(v: Vec<usize>, n: usize) -> Vec<Vec<usize>> {
    if v.len() < n {
        panic!("v.len() < n");
    }
    let mut result = vec![];
    for perm in IntoIterator::into_iter(v).permutations(n) {
        result.push(perm);
    }
    result
}

fn ncr(v: Vec<usize>, n: usize) -> Vec<Vec<usize>> {
    if v.len() < n {
        panic!("v.len() < n");
    }
    let mut result = vec![];
    for comb in IntoIterator::into_iter(v).combinations(n) {
        result.push(comb);
    }
    result
}

fn nhr(v: Vec<usize>, n: usize) -> Vec<Vec<usize>> {
    if v.len() < n {
        panic!("v.len() < n");
    }
    let mut result = vec![];
    for comb in IntoIterator::into_iter(v).combinations_with_replacement(n) {
        result.push(comb);
    }
    result
}

fn charint2usize(c: char) -> usize {
    c as usize - '0' as usize
}
