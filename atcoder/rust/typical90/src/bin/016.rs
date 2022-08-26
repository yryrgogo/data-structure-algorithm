use itertools::Itertools;
use whiteread::parse_line;

/**
 * NOTE: vector を O(n^2) のループ内で使うと、vector へのアクセスで計算量が増えて TLE する
 * NOTE: 10000^2 の各ループ内で要素数3の vector へ都度アクセスすると TLE
 */
fn main() {
    let n = parse_line::<u64>().unwrap();
    // NOTE: a, b, c を vector で持つと TLE
    let (a, b, c) = parse_line::<(u64, u64, u64)>().unwrap();

    let mut ans = 10000;

    for i in 0..10000 {
        let tmp = a * i;
        if tmp > n {
            continue;
        }
        for j in 0..(10000 - i) {
            let tmp2 = tmp + j * b;
            if tmp2 > n {
                continue;
            }
            if (n - tmp2) % c != 0 {
                continue;
            }
            if ans > i + j + ((n - tmp2) / c) {
                ans = i + j + ((n - tmp2) / c);
            }
        }
    }
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
