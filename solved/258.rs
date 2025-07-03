#[cfg(test)]
mod utils;

pub struct Solution;

// start
impl Solution {
    pub fn add_digits(mut num: i32) -> i32 {
        while num > 9 {
            let mut sum = 0;
            while num > 0 {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        num
    }
}
// end

#[cfg(test)]
mod tests {
    use super::*;
    use test_case::test_case;
    use utils::*;

    #[test_case(38, 2)]
    #[test_case(0, 0)]
    #[test_case(1, 1)]
    #[test_case(10, 1)]
    #[test_case(i32::MAX, 1)]
    fn test_solution(num: i32, ans: i32) {
        assert_eq!(Solution::add_digits(num), ans);
    }
}
