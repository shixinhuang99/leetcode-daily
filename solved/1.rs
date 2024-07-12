#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        use std::collections::HashMap;

        let mut map: HashMap<i32, usize> = HashMap::new();

        for (i, n) in nums.iter().enumerate() {
            let t = target - *n;
            if let Some(j) = map.get(&t) {
                return vec![i as i32, *j as i32];
            }
            map.insert(*n, i);
        }

        vec![]
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(vec![2,7,11,15], 9, vec![0, 1])]
    #[test_case(vec![3,2,4], 6, vec![1,2])]
    #[test_case(vec![3,3], 6, vec![0,1])]
    fn test_solution(nums: Vec<i32>, target: i32, mut ans: Vec<i32>) {
        assert!(slice_eq_no_order(
            &mut Solution::two_sum(nums.to_vec(), target),
            &mut ans
        ));
    }
}
