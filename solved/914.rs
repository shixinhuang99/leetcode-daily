#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn has_groups_size_x(deck: Vec<i32>) -> bool {
        use std::collections::HashMap;

        let mut map: HashMap<i32, i32> = HashMap::new();

        for n in deck {
            map.entry(n).and_modify(|v| *v += 1).or_insert(1);
        }

        let mut g = -1;

        for n in map.values() {
            if g == -1 {
                g = *n;
            } else {
                g = gcd(g, *n);
            }
        }

        g >= 2
    }
}

fn gcd(mut a: i32, mut b: i32) -> i32 {
    if a <= b {
        std::mem::swap(&mut a, &mut b);
    }
    while b != 0 {
        let t = a;
        a = b;
        b = t % b;
    }
    a
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(&[1,2,3,4,4,3,2,1], true)]
    fn test_solution(deck: &[i32], ans: bool) {
        assert_eq!(Solution::has_groups_size_x(deck.to_vec()), ans);
    }
}
