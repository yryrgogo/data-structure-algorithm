use whiteread::parse_line;

fn main() {
    let (n, m) = parse_line::<(usize, usize)>().unwrap();
    let mut sc = vec![];

    for i in 0..m {
        let (s, c) = parse_line::<(usize, usize)>().unwrap();
        sc.push((s, c));
    }

    for i in 0..1000 {
        let mut ok = true;
        let target = i.to_string();
        if n != target.len() {
            continue;
        };
        for (s, c) in sc.clone() {
            if c != (target.chars().nth(s - 1).unwrap() as usize - '0' as usize) {
                ok = false;
            }
        }
        if ok {
            println!("{}", target);
            return;
        }
    }
    println!("-1");

    // let mut ok = true;
    // for i in 0..m {
    //     let (s, c) = parse_line::<(usize, usize)>().unwrap();
    //     v.push((s, c));

    //     if ans_v[s - 1] == c {
    //         continue;
    //     } else if ans_v[s - 1] == 10 {
    //         ans_v[s - 1] = c;
    //     } else {
    //         ok = false;
    //         break;
    //     }
    // }

    // let mut ans = 0;
    // for i in 0..n {
    //     if i == 0 {
    //         if ans_v[i] == 0 && n != 1 {
    //             ok = false;
    //         } else if ans_v[i] == 10 {
    //             ans += 10usize.pow((n - i - 1) as u32);
    //         } else {
    //             ans += ans_v[i] * 10usize.pow((n - i - 1) as u32);
    //         }
    //     } else if ans_v[i] != 10 {
    //         ans += ans_v[i] * 10usize.pow((n - i - 1) as u32);
    //     }
    // }

    // if ok {
    //     println!("{}", ans);
    // } else {
    //     println!("-1");
    // }
}
