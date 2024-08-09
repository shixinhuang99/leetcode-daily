#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        use std::collections::HashMap;

        let mut map: HashMap<Vec<i32>, i32> = HashMap::new();

        for mut d in dominoes.into_iter() {
            d.sort_unstable();
            map.entry(d).and_modify(|cnt| *cnt += 1).or_insert(1);
        }

        let mut ret = 0;

        for cnt in map.into_values() {
            if cnt <= 1 {
                continue;
            }
            ret += (1..cnt).sum::<i32>();
        }

        ret
    }

    pub fn num_equiv_domino_pairs_fast(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut num = [0; 100];
        let mut ret = 0;

        for d in dominoes {
            let v = if d[0] > d[1] {
                d[1] * 10 + d[0]
            } else {
                d[0] * 10 + d[1]
            } as usize;
            ret += num[v];
            num[v] += 1;
        }

        ret
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(vec![[1,2],[2,1],[3,4],[5,6]], 1)]
    #[test_case(vec![[1,2],[1,2],[1,1],[1,2],[2,2]], 3)]
    fn test_solution(dominoes: Vec<[i32; 2]>, ans: i32) {
        assert_eq!(
            Solution::num_equiv_domino_pairs(
                dominoes.into_iter().map(|arr| arr.to_vec()).collect()
            ),
            ans
        );
    }
}
