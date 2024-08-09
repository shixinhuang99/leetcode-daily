#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        let n = n as usize;
        let mut arr = [0; 38];

        arr[1] = 1;
        arr[2] = 1;

        if n < 3 {
            return arr[n];
        }

        for i in 3..=n {
            arr[i] = arr[i - 3] + arr[i - 2] + arr[i - 1];
        }

        arr[n]
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(4, 4)]
    #[test_case(25, 1389537)]
    fn test_solution(n: i32, ans: i32) {
        assert_eq!(Solution::tribonacci(n), ans);
    }
}
