#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn relative_sort_array(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
        use std::collections::HashMap;

        let mut map: HashMap<i32, usize> = HashMap::new();

        for (i, n) in arr2.into_iter().enumerate() {
            map.insert(n, i);
        }

        let (mut a1, mut b1): (Vec<i32>, Vec<i32>) =
            arr1.into_iter().partition(|n| map.contains_key(n));

        a1.sort_unstable_by(|a, b| {
            let pa = map.get(a).unwrap_or(&0);
            let pb = map.get(b).unwrap_or(&0);
            pa.cmp(pb)
        });

        b1.sort_unstable();

        a1.extend(b1);

        a1
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(vec![2,3,1,3,2,4,6,7,9,2,19], vec![2,1,4,3,9,6], vec![2,2,2,1,4,3,3,9,6,7,19])]
    #[test_case(vec![28,6,22,8,44,17], vec![22,28,8,6], vec![22,28,8,6,17,44])]
    fn test_solution(arr1: Vec<i32>, arr2: Vec<i32>, ans: Vec<i32>) {
        assert_eq!(Solution::relative_sort_array(arr1, arr2), ans);
    }
}
